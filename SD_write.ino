#include<SD.h>
const int chipSelect=49;

void sd_begin()
{
   pinMode(53,OUTPUT);
   Serial.print("Init SD"); 
   if(!SD.begin(chipSelect))
   {
     Serial.println("failed"); 
     return;
   }
   Serial.println("done");
}

void sd_write()
{
  Serial.println("Open file");
  File dataFile=SD.open("data.txt",FILE_WRITE);
  if(dataFile)
  {
   dataFile.println();
   dataFile.println("time 00:00:00");
   dataFile.print("Temperature:");
   dataFile.println(temperature,DEC);
   
   dataFile.print("Pressure:");
   dataFile.println(pressure,DEC);
   dataFile.print("luminance:");
   dataFile.println(lx,DEC);
   dataFile.print("Humidity :");
   dataFile.println(humidity,DEC);
   dataFile.print("wind direction:");
   dataFile.println(dir,DEC);
   dataFile.print("wind_speed:");
   dataFile.println(wind_speed,DEC);
   Serial.println("write done");
   dataFile.close();
  }
  else
  {
   Serial.println("open file error") ;
  }
  delay(6000);
}

