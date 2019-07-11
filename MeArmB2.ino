 #include <Servo.h>
#include <SoftwareSerial.h>

#define pinbase 12 //desde 15 a 185 grados
#define pinderecho 11
#define pinizquierdo 10
#define pingarra 9
Servo base;
Servo derecho;
Servo izquierdo;
Servo garra;
SoftwareSerial BT (2,3);
void setup()
{
  BT.begin (9600);
  Serial.begin(9600);
   base.attach(pinbase);
  derecho.attach(pinderecho);
  izquierdo.attach(pinizquierdo);
  garra.attach(pingarra);
  garra.write(5);
  base.write(100);
  izquierdo.write(90);
  derecho.write(85);
  
  
}

 int a,b,c;
 char s[4];
void loop() 
{
 if(BT.available()>0&&BT.available()<=4)
   {
    BT.readBytes(s,4);
    Serial.println(s);
    switch(s[0])
    {
      
case'b':
      a=(s[1]-48)*100;
      b=(s[2]-48)*10;
      c=a+b+(s[3]-48);
      base.write(c);
      Serial.println(c);
      break; 
case'd':
      a=(s[1]-48)*100;
      b=(s[2]-48)*10;
      c=a+b+(s[3]-48);
      derecho.write(c);
      Serial.println(c);
      break; 
case'i':
      a=(s[1]-48)*100;
      b=(s[2]-48)*10;
      c=a+b+(s[3]-48);
      izquierdo.write(c);
      Serial.println(c);
      break; 
case'g':
      a=(s[1]-48)*100;
      b=(s[2]-48)*10;
      c=a+b+(s[3]-48);
      garra.write(c);
      Serial.println(c);
      break; 
case 'a':
  garra.write(50);
  izquierdo.write(35);
  delay(300);  
  derecho.write(125);
  delay(1000);
  garra.write(30);
  delay(300);
  derecho.write(85);
  delay(300);
  izquierdo.write(90);
  delay(300);
  base.write(180);
  delay(300);
  garra.write(00);
  delay(1000);
 
  case 'r':
    derecho.write(85);
  delay(300);
  izquierdo.write(90);
  delay(300);
   base.write(100);
  delay(300);
  garra.write(5);
  delay(300);
  /* i035
    * d125 
    * g030
    * d085
    * i090
    * b180
    * g000*/
      }
   }
}
 /*i090 i020
   d085 d160
   g000 g050
  */
