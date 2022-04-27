# PG2_2021-2
## Estudo de acelerômetros para sistemas embarcados. Uma abordagem de instrumentação para estimação da velocidade
### Projeto de Graduação do Curso de Engenharia da Computação da UFES no 2º semestre de 2021.

**Última atualização:** 27/05/2022

**Autor:** Gabriel Ferrari Batista Martins

**Palavras-Chave:** acelerômetro, velocidade, redução de erro, ruído, giroscópio

**Estrutura:**

[PG2_2021-2](./)
  - [CALIBRACAO](CALIBRACAO) : Arquivos usados para calibrar o sensor.
    - [logger](CALIBRACAO/logger) : Sketch Arduino usado na calibração.
  - [MEDICAO](MEDICAO) : Sketchs usados para calibrar o sensor.
    - [code](MEDICAO/code) : Versão modificada desse [exemplo](https://github.com/jrowberg/i2cdevlib/blob/master/Arduino/MPU6050/examples/MPU6050_DMP6/MPU6050_DMP6.ino).
    - [datalog](MEDICAO/datalog) : Versão modificada desse [projeto](https://github.com/anmolio/mpu6050-datalogging).
  - [PG](PG) : Documentação do Projeto de Graduação.
  - [TRATAMENTO](TRATAMENTO) : Medidas obtidas e arquivos usados na manipulação delas.


 
 
