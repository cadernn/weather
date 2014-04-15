int i;
void setup() 
{
Serial.begin(115200);
Serial1.begin(115200);

}

void loop()
{
/*int i=0;
delay(500);
Serial1.print("ATE1\r\n");
delay(500);
Serial1.print("AT+COLP=1\r\n");
delay(500);
Serial1.print("ATD14718091728;\r\n");
for(i=0;i<=60;i++)
{
  delay(1000); 
}
Serial1.print("ATH\r\n");
while(1);*/  
  
  
  connect(); 
  Serial1.print("AT+CIPSEND\r\n"); 
  delay(500);
  Serial1.print("TEST"); 
  delay(500);
  Serial1.write(26);
  delay(500); 
  
  //Serial1.print("\r\n");
  
  for(i=0;i<=30;i++)
  {
  delay(1000); 
  }
  
  close();
  while(1);
 }
 


 
 void connect()
 {
  Serial1.print("ati\r\n"); 
  delay(1000);
  Serial1.print("ati\r\n"); 
  delay(1000);
  Serial1.print("ati\r\n"); 
  delay(1000);
  
  delay(500); 
  Serial1.print("AT+CGCLASS=\"B\"\r\n"); 
  delay(500); 
  Serial1.print("AT+CGDCONT=1,\"IP\",\"UNINET\"\r\n"); 
  delay(500);
  Serial1.print("AT+CGATT=1\r\n"); 
  delay(500); 
  Serial1.print("AT+CIPCSGP=1,\"UNINET\"\r\n"); 
  delay(500);  
  Serial1.print("AT+CLPORT=\"TCP\",\"2000\"\r\n"); 
  delay(500);  
  Serial1.print("AT+CIPSTART=\"TCP\","); 
  Serial1.print("\"120.82.86.75\",\"80\"\r\n");
  delay(500);   
  for(i=0;i<=12;i++)
  {
  delay(1000); 
  }
}
 
 void close()
 {
  Serial1.print("AT+CIPCLOSE=1\r\n"); 
  delay(500);
  Serial1.print("AT+CIPSHUT\r\n"); 
  delay(500);
 }

