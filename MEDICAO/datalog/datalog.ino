#include "I2Cdev.h"
#include <SPI.h>
#include <SD.h>
#include "MPU6050_6Axis_MotionApps20.h"
// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif


// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for SparkFun breakout and InvenSense evaluation board)
// AD0 high = 0x69
MPU6050 mpu;

#define INTERRUPT_PIN 2  // use pin 2 on Arduino Uno & most boards
#define LED_PIN 13 // (Arduino is 13, Teensy is 11, Teensy++ is 6)
#define CS_PIN 4 // cs pin from sd card
#define pausepin 8 // button de pause
#define configpin 9 // button de config gyro e accel
#define rotapin 7 // button de rota


uint8_t gyro_config = 0x00;
uint8_t accel_config =  0x00;
uint8_t rota = 0;
char nome_arquivo[20]; //nome do arquivo de texto

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 gg;         // [x, y, z]            gyro sensor measurements
int bpress[6]; // status atual do button e status anterior button
unsigned long miliseconds, start;
bool blinkState = false;
bool pause = true, novo=true;
String dataString;
File dataFile;

// ================================================================
// ===               INTERRUPT DETECTION ROUTINE                ===
// ================================================================

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}

// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================


void refresh(){ //atualiza o nome do arquivo
  mpu.setFullScaleGyroRange(gyro_config);
  mpu.setFullScaleAccelRange(accel_config);
  sprintf(nome_arquivo,"G%uA%uR%u.txt",mpu.getFullScaleGyroRange(),mpu.getFullScaleAccelRange(),rota);
  Serial.println(nome_arquivo); 
}



void buttons(){ //le os buttons
  //atualiza estados
  bool mudou = false;
  bpress[1]=bpress[0];
  bpress[3]=bpress[2];
  bpress[5]=bpress[4];
  bpress[0]=digitalRead(pausepin);
  bpress[2]=digitalRead(configpin);
  bpress[4]=digitalRead(rotapin);
  if( !bpress[1] && bpress[0]){
    pause=!pause;
    if(!pause){ //comecou de novo
      Serial.print("Recomecou ");
      novo=true;
      refresh();
    }else Serial.println("Parou.");
  }
  if(pause){ //le os outros quando pausado
    if( !bpress[3] && bpress[2] ){
      if(gyro_config <3){
          gyro_config=0x03;
      }else {
        gyro_config=0x00;
      }
      if(accel_config<3){
        accel_config=0x03;
      }else accel_config= 0x00;
           
      refresh();
    }
    if( !bpress[5] && bpress[4] ){
      if(rota <7){
        rota++;
      }else rota=0;
      refresh();
    }
  }
}

void setup() {
    
    // configure LED for output
    pinMode(LED_PIN, OUTPUT);
    pinMode(pausepin, INPUT);
    pinMode(configpin, INPUT);
    pinMode(rotapin, INPUT);
    digitalWrite(LED_PIN,HIGH);
    
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    // initialize serial communication
    // (115200 chosen because it is required for Teapot Demo output, but it's
    // really up to you depending on your project)
    Serial.begin(9600);
    while (!Serial); // wait for Leonardo enumeration, others continue immediately

    // NOTE: 8MHz or slower host processors, like the Teensy @ 3.3V or Arduino
    // Pro Mini running at 3.3V, cannot handle this baud rate reliably due to
    // the baud timing being too misaligned with processor ticks. You must use
    // 38400 or slower in these cases, or use some kind of external separate
    // crystal solution for the UART timer.

    // initialize device
    Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);

    // verify connection
    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    // wait for ready
    Serial.println(F("\n Press leftmost button to start: "));
    while(pause){
      buttons();
    };
    // load and configure the DMP
    Serial.println(F("Initializing DMP..."));
    devStatus = mpu.dmpInitialize();

    


      // see if the card is present and can be initialized:
    if (!SD.begin(CS_PIN)) {
      Serial.println("Card failed, or not present");
      // don't do anything more:
      return;
    }
    Serial.println("card initialized.");
    if(SD.exists(nome_arquivo)){
          SD.remove(nome_arquivo);
    }

    // supply your own gyro offsets here, scaled for min sensitivity
    mpu.setXAccelOffset(-1604);
    mpu.setYAccelOffset(-1057);
    mpu.setZAccelOffset(358); // 1688 factory default for my test chip
    mpu.setXGyroOffset(111);
    mpu.setYGyroOffset(98);
    mpu.setZGyroOffset(-64);
    // make sure it worked (returns 0 if so)
    if (devStatus == 0) {
        // Calibration Time: generate offsets and calibrate our MPU6050
        mpu.CalibrateAccel(6);
        mpu.CalibrateGyro(6);
        mpu.PrintActiveOffsets();
        // turn on the DMP, now that it's ready
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        Serial.print(F("Enabling interrupt detection (Arduino external interrupt "));
        Serial.print(digitalPinToInterrupt(INTERRUPT_PIN));
        Serial.println(F(")..."));
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }
    refresh();
}

// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
    buttons();
    if(pause){ //parado esperando button
      return;
    }
    if(novo){ //novo comeco
      novo=!novo;
      start=millis();
      refresh();
    }
    // if programming failed, don't try to do anything
    if (!dmpReady) return;
    // read a packet from FIFO
    if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) { // Get the Latest packet 
        //RAW READINGS for config accuracy
        mpu.dmpGetAccel(&aa,fifoBuffer);
        mpu.dmpGetGyro(&gg,fifoBuffer);

        // blink LED to indicate activity
        blinkState = !blinkState;
        digitalWrite(LED_PIN, blinkState);
        ////////////////////////////////////
        // make a string for assembling the data to log:
        dataString = "";
        
        dataString+=String( aa.x )+" ";
        dataString+=String( aa.y )+" ";
        dataString+=String( aa.z )+" ";
        dataString+=String( gg.x )+" ";
        dataString+=String( gg.y )+" ";
        dataString+=String( gg.z )+" ";        
         dataString += String(millis()-start);
        
        // open the file. note that only one file can be open at a time,
        // so you have to close this one before opening another.
       
        dataFile = SD.open(nome_arquivo, FILE_WRITE);
        Serial.println(dataString);
        // if the file is available, write to it:
        if (dataFile) {
          dataFile.println(dataString);
          dataFile.close();
         
        } else {// if the file isn't open, pop up an error:
          Serial.println("error opening datalog.txt");
        }
    }
    
}
