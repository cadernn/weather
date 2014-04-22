#include <Wire.h>
#include <dht11.h>
#include <SD.h>

File myFile;

dht11 DHT11;
#define DHT11PIN 22
#define BMP085_ADDRESS 0x77  // I2C address of BMP085
const unsigned char OSS = 0;  // Oversampling Setting
int BH1750address = 0x23; 
byte buff[2];
int wind_cout;

//data of  weather station
float temperature;
float pressure;
uint16_t lx=0;
float humidity;
int dir;
float wind_speed;


// Calibration values
int ac1;
int ac2; 
int ac3; 
unsigned int ac4;
unsigned int ac5;
unsigned int ac6;
int b1; 
int b2;
int mb;
int mc;
int md;

// b5 is calculated in bmp085GetTemperature(...), this variable is also used in bmp085GetPressure(...)
// so ...Temperature(...) must be called before ...Pressure(...).
long b5; 

String inputString = "";         // 用于保存输入数据的字符串
boolean stringComplete = false;  // 字符串是否已接收完全


void setup()
{
  Serial.begin(9600);
  Serial2.begin(115200);
  Serial3.begin(9600);
  sd_begin();
  Wire.begin();
  bmp085Calibration(); 
  pinMode(1,INPUT);
  
}
int t;

void loop()
{
 seneor_work();//function in the sensor.ino

 sd_write();
 

 post_temperature();
 post_press();
 post_lx();
 post_humidity();
 post_dir();
 post_wind();
 

 for(t=0;t<=10;t++)
  {
    delay(1000); 
  }
  
}


