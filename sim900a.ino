 #include <stdio.h>;  
 #include <math.h>  
   
  int i;
  int len; 
  int times;
  int temp;

   char post[]={//提交数据包
    "POST /v1.0/device/8187/sensor/aaaaa/datapoints HTTP/1.1\r\n"
    "Host: api.yeelink.net\r\n"
    "Accept: */*\r\n"
    "U-ApiKey: f92************************b2b42\r\n"
    "Content-Length: dt\r\n"
    "Content-Type: application/x-www-form-urlencoded\r\n"
    "Connection: close\r\n"
    "\r\n"
    "{\"value\":xxxxxx}\r\n"
       };//xx用来填充数值

    char post_reserve[]={//提交数据包
    "POST /v1.0/device/8187/sensor/aaaaa/datapoints HTTP/1.1\r\n"
    "Host: api.yeelink.net\r\n"
    "Accept: */*\r\n"
    "U-ApiKey: f92************************b2b42\r\n"
    "Content-Length: dt\r\n"
    "Content-Type: application/x-www-form-urlencoded\r\n"
    "Connection: close\r\n"
    "\r\n"
    "{\"value\":xxxxxx}\r\n"
       };//xx用来填充数值
  
char temperature_sensor_id[]={"12975"};
char humidity_sensor_id[]={"12976"};
char press_sensor_id[]={"12977"};
char lx_sensor_id[]={"12979"};
char direction_sensor_id[]={"12981"};
char wind_sensor_id[]={"12984"};


/////1
void post_temperature() //发送温度数据
{  connect();
   len=strlen(post);
   for(times=0;times<len;times++) 
   {
      if(post[times]=='a'&&post[times+1]=='a'&&post[times+2]=='a')
       { 
          post[times]=temperature_sensor_id[0];
	  post[times+1]=temperature_sensor_id[1];
	  post[times+2]=temperature_sensor_id[2];
	  post[times+3]=temperature_sensor_id[3];
	  post[times+4]=temperature_sensor_id[4];
          break;        
       }
   }
   temp=0;
   len=strlen(post);   
   temp=Serial3.print(temperature,1);  
    for(times=0;times<len;times++)
   {
       if(post[times]=='d'&&post[times+1]=='t')
	   {
              post[times]=(temp+10)/10+0x30;  
	      post[times+1]=(temp+10)%10+0x30;
	      break;
	   }
   }
   
   for(times=0;times<len;times++)//填改传感器数值，发送报文
     {
       if(post[times]=='x'&&post[times+1]=='x'&&post[times+2]=='x') 
	   {
              Serial2.print(temperature,1);                 
              times=times+6;
	    } 
        Serial2.print(post[times]);
     } 
    Serial2.write(26);//send order
    delay(5000);
    //close();
   for(times=0;times<len;times++)
  {
     post[times]=post_reserve[times];
  }       
}
////////2
void post_humidity() //
{  connect();
   len=strlen(post);
   for(times=0;times<len;times++) 
   {
      if(post[times]=='a'&&post[times+1]=='a'&&post[times+2]=='a')
       { 
          post[times]=humidity_sensor_id[0];
	  post[times+1]=humidity_sensor_id[1];
	  post[times+2]=humidity_sensor_id[2];
	  post[times+3]=humidity_sensor_id[3];
	  post[times+4]=humidity_sensor_id[4];
          break;        
       }
   }
   temp=0;
   len=strlen(post);   
   temp=Serial3.print(humidity);  
    for(times=0;times<len;times++)
   {
       if(post[times]=='d'&&post[times+1]=='t')
	   {
              post[times]=(temp+10)/10+0x30;  
	      post[times+1]=(temp+10)%10+0x30;
	      break;
	   }
   }
   
   for(times=0;times<len;times++)//填改传感器数值，发送报文
     {
       if(post[times]=='x'&&post[times+1]=='x'&&post[times+2]=='x') 
	   {
              Serial2.print(humidity);                 
              times=times+6;
	    } 
        Serial2.print(post[times]);
     } 
    Serial2.write(26);//send order
    delay(5000);
    //close();
   for(times=0;times<len;times++)
  {
     post[times]=post_reserve[times];
  }       
}


//////

void post_press() //发送压力数据
{  connect();
   len=strlen(post);
   for(times=0;times<len;times++) 
   {
      if(post[times]=='a'&&post[times+1]=='a'&&post[times+2]=='a')
       { 
      post[times]=press_sensor_id[0];
	  post[times+1]=press_sensor_id[1];
	  post[times+2]=press_sensor_id[2];
	  post[times+3]=press_sensor_id[3];
	  post[times+4]=press_sensor_id[4];
          break;        
       }
   }
   temp=0;
   len=strlen(post);   
   temp=Serial3.print(pressure,1);  
    for(times=0;times<len;times++)
   {
       if(post[times]=='d'&&post[times+1]=='t')
	   {
              post[times]=(temp+10)/10+0x30;  
	      post[times+1]=(temp+10)%10+0x30;
	      break;
	   }
   }
   
   for(times=0;times<len;times++)//填改传感器数值，发送报文
     {
       if(post[times]=='x'&&post[times+1]=='x'&&post[times+2]=='x') 
	   {
              Serial2.print(pressure,1);                 
              times=times+6;
	    } 
        Serial2.print(post[times]);
     } 
    Serial2.write(26);//send order
    delay(5000);
    //close();
   for(times=0;times<len;times++)
  {
     post[times]=post_reserve[times];
  }       
}
void post_wind() //
{  connect();
   len=strlen(post);
   for(times=0;times<len;times++) 
   {
      if(post[times]=='a'&&post[times+1]=='a'&&post[times+2]=='a')
       { 
      post[times]=wind_sensor_id[0];  
	  post[times+1]=wind_sensor_id[1];
	  post[times+2]=wind_sensor_id[2];
	  post[times+3]=wind_sensor_id[3];
	  post[times+4]=wind_sensor_id[4];
       break;        
       }
   }
   temp=0;
   len=strlen(post);   
   temp=Serial3.print(wind_speed,1);  
    for(times=0;times<len;times++)
   {
       if(post[times]=='d'&&post[times+1]=='t')
	   {
              post[times]=(temp+10)/10+0x30;  
	      post[times+1]=(temp+10)%10+0x30;
	      break;
	   }
   }
   
   for(times=0;times<len;times++)//填改传感器数值，发送报文
     {
       if(post[times]=='x'&&post[times+1]=='x'&&post[times+2]=='x') 
	   {
              Serial2.print(wind_speed,1);             
              times=times+6;
	    } 
        Serial2.print(post[times]);
     } 
    Serial2.write(26);//send order
    delay(5000);
    //close();
   for(times=0;times<len;times++)
  {
     post[times]=post_reserve[times];
  }       
}
///////////////////////////////
void post_dir() //发送温度数据
{  connect();
   len=strlen(post);
   for(times=0;times<len;times++) 
   {
      if(post[times]=='a'&&post[times+1]=='a'&&post[times+2]=='a')
       { 
          post[times]=direction_sensor_id[0];
	  post[times+1]=direction_sensor_id[1];
	  post[times+2]=direction_sensor_id[2];
	  post[times+3]=direction_sensor_id[3];
	  post[times+4]=direction_sensor_id[4];
          break;        
       }
   }
   temp=0;
   len=strlen(post);   
   temp=Serial3.print(dir);  
    for(times=0;times<len;times++)
   {
       if(post[times]=='d'&&post[times+1]=='t')
	   {
              post[times]=(temp+10)/10+0x30;  
	      post[times+1]=(temp+10)%10+0x30;
	      break;
	   }
   }
   
   for(times=0;times<len;times++)//填改传感器数值，发送报文
     {
       if(post[times]=='x'&&post[times+1]=='x'&&post[times+2]=='x') 
	   {
              Serial2.print(dir);                 
              times=times+6;
	    } 
        Serial2.print(post[times]);
     } 
    Serial2.write(26);//send order
    delay(5000);
    //close();
   for(times=0;times<len;times++)
  {
     post[times]=post_reserve[times];
  }       
}

////////////////
void post_lx() //发送压力数据
{  connect();
   len=strlen(post);
   for(times=0;times<len;times++) 
   {
      if(post[times]=='a'&&post[times+1]=='a'&&post[times+2]=='a')
       { 
          post[times]=lx_sensor_id[0];  
	  post[times+1]=lx_sensor_id[1];
	  post[times+2]=lx_sensor_id[2];
	  post[times+3]=lx_sensor_id[3];
	  post[times+4]=lx_sensor_id[4];
       break;        
       }
   }
   temp=0;
   len=strlen(post);   
   temp=Serial3.print(lx);  
    for(times=0;times<len;times++)
   {
       if(post[times]=='d'&&post[times+1]=='t')
	   {
              post[times]=(temp+10)/10+0x30;  
	      post[times+1]=(temp+10)%10+0x30;
	      break;
	   }
   }
   
   for(times=0;times<len;times++)//填改传感器数值，发送报文
     {
       if(post[times]=='x'&&post[times+1]=='x'&&post[times+2]=='x') 
	   {
              Serial2.print(lx);        //fix         
              times=times+6;
	    } 
        Serial2.print(post[times]);
     } 
    Serial2.write(26);//send order
    delay(5000);
    //close();
   for(times=0;times<len;times++)
  {
     post[times]=post_reserve[times];
  }       
}



 void connect()//TCP连接
 {
  int i;
  Serial2.print("ati\r\n"); 
  delay(1000);
  Serial2.print("ati\r\n"); 
  delay(1000);
  Serial2.print("ati\r\n"); 
  delay(1000);
  delay(500); 
  Serial2.print("AT+CGCLASS=\"B\"\r\n"); 
  delay(500); 
  Serial2.print("AT+CGDCONT=1,\"IP\",\"UNINET\"\r\n"); 
  delay(500);
  Serial2.print("AT+CGATT=1\r\n"); 
  delay(500); 
  Serial2.print("AT+CIPCSGP=1,\"UNINET\"\r\n"); //uninet
  delay(500);  
  Serial2.print("AT+CLPORT=\"TCP\",\"2000\"\r\n"); 
  delay(500);  
  Serial2.print("AT+CIPSTART=\"TCP\",\"42.96.164.52\",\"80\"\r\n"); //the ip addr to yeelink
  delay(500);   
  for(i=0;i<=9;i++)
  {
  delay(1000); 
  }
  Serial2.print("AT+CIPSEND\r\n"); 
  delay(500);
 }
 
 void close()//结束TCP连接
 {
 
  Serial2.print("AT+CIPCLOSE=1\r\n"); 
  delay(500);
  Serial2.print("AT+CIPSHUT\r\n"); 
  delay(500);
 }


