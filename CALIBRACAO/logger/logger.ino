// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

Adafruit_MPU6050 mpu;
const int chipSelect = 4;
unsigned long contador = 0;
String arquivo= "0calix.txt";
unsigned int config=0;

void setup(void) {
  Serial.begin(115200);
  while (!Serial) {
    delay(10); // will pause Zero, Leonardo, etc until serial console opens
  }
  
  // Try to initialize!
  while (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    delay(100);
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  Serial.println("");
  delay(100);
  // see if the card is present and can be initialized:
  while (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    delay(100);
  }
  Serial.println("card initialized.");
  delay(500);
}

void loop() {

  /* Get new sensor events with the readings */
  File dataFile = SD.open(arquivo,FILE_WRITE);
  if (contador == 0){
    Serial.print("Configuracao atual ");
    Serial.println(config);
    switch(config){
          case 0:
            dataFile.println("2 250");
            break;
          case 1:
            dataFile.println("2 250");
            break;
          case 2:
            dataFile.println("2 250");
            break;
          case 3:
            dataFile.println("2 250");
            break;
          default:
            Serial.print("Erro");
            while(1);
          }
  }else if(contador>=10000){
      Serial.print("Acabou rodada ");
      Serial.println(config);
      if(config<3){
        config++;
        arquivo[0]='0'+config;
        contador=0;
        switch(config){
          case 1:
            mpu.setAccelerometerRange(MPU6050_RANGE_4_G);
            mpu.setGyroRange(MPU6050_RANGE_500_DEG);
            break;
          case 2:
            mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
            mpu.setGyroRange(MPU6050_RANGE_1000_DEG);
            break;
          case 3:
            mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
            mpu.setGyroRange(MPU6050_RANGE_2000_DEG );
            break;
          default:
            Serial.print("Erro");
            while(1);
        }
        dataFile.close();
        delay(100);
        return;  
      }else{
        Serial.println("Acabou");
        dataFile.close();
        while(1);
      }     
  }
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  Serial.println(contador);
  
  // if the file is available, write to it:
  if (dataFile) {
    dataFile.print(a.acceleration.x);
    dataFile.print(" ");
    dataFile.print(a.acceleration.y);
    dataFile.print(" ");
    dataFile.print(a.acceleration.z);
    dataFile.print(" ");
    dataFile.print(g.gyro.x);
    dataFile.print(" ");
    dataFile.print(g.gyro.y);
    dataFile.print(" ");
    dataFile.print(g.gyro.z);
    dataFile.println("");
    dataFile.close();
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
  delay(10);
  contador++;
}
