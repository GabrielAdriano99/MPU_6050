#include<Wire.h>

#define MPU9250_ADDRESS 0x68
#define MAG_ADDRESS 0x0C

int ledGreen = 11;
int ledRed = 10;
int ledYellow = 9;
int i;

int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ, MgX, MgY, MgZ;
float Gz, Gx, Gy, m, angleX, angleY, angleZ;
float inclinacaoX, inclinacaoY, inclinacaoZ;
float left, right, front, back;
char attsTwo[2];
char attsThree[3];

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU9250_ADDRESS);
  //Wire.write(0x6B);  // PWR_MGMT_1 register
  //Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU9250_ADDRESS);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU9250_ADDRESS,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  //Serial.println("AcX = "); Serial.println(AcX);

  Gx = float(AcX)/16384;
  Gy = float(AcY)/16384;
  Gz = float(AcZ)/16384;

  m = sqrt(Gx*Gx + Gy*Gy + Gz*Gz);

  angleX = acos(Gx/m);
  angleY = acos(Gy/m);
  angleZ = acos(Gz/m);

  angleX = angleX*180/3.14;
  angleY = angleY*180/3.14;
  angleZ = angleZ*180/3.14;

  inclinacaoX = angleX - 90;
  inclinacaoY = angleY - 90;
  inclinacaoZ = angleZ - 90;

  Serial.print("angleX = "); 
  Serial.print(angleX);
  Serial.print(" | angleY = "); 
  Serial.print(angleY);
  Serial.print(" | angleZ = "); 
  Serial.println(angleZ);

  Serial.print("inclinacaoX = "); 
  Serial.print(inclinacaoX);
  Serial.print(" | inclinacaoY = "); 
  Serial.print(inclinacaoY);
  Serial.print(" | inclinacaoZ = "); 
  Serial.println(inclinacaoZ);
  Serial.println();

  for(i = 0; i < 2; i++){
    if(attsTwo[i] != 'D' && attsTwo[i] != 'E'){
      if(inclinacaoZ > 35){
        Serial.println("ESQUERDA");
        Serial.println("'E' add ao vetor attsT");
        attsTwo[i] = 'E';
        delay(3000);
      } 
      if(inclinacaoZ < -30) {
        Serial.println("DIREITA");
        Serial.println("'D' add ao vetor attsTwo");
        attsTwo[i] = 'D';
        delay(3000);
      } 
      if(inclinacaoX < -40) {
        Serial.println("FRENTE");
        Serial.println("'F' add ao vetor attsTwo");
        attsTwo[i] = 'F';
        delay(3000);
      }
      Serial.println(attsTwo[i]);
      break;
    }
  }
  Serial.println("");
  Serial.print("INDiCE 0 = ");
  Serial.println(attsTwo[0]);
  Serial.print("INDiCE 1 = ");
  Serial.println(attsTwo[1]);


  //Serial.println(" | inclinacao = "); 
  //Serial.print(inclinacao);
  //Serial.println(" | AcY = "); Serial.print(AcY);
  //Serial.print(" | AcZ = "); Serial.print(AcZ);
  //Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
  //Serial.print(" | GyX = "); Serial.print(GyX);
  //Serial.print(" | GyY = "); Serial.print(GyY);
  //Serial.print(" | GyZ = "); Serial.println(GyZ);

  Wire.requestFrom(MAG_ADDRESS,6,true);  // request a total of 14 registers

  MgX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  MgY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  MgZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)

  //Serial.println("MgX = "); Serial.println(inclinacao);

  delay(250);
}











