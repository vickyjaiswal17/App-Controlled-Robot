
int motorpin1=7;
int motorpin2=6;
int motorpin3=5;
int motorpin4=4;
int pwm1=3;
int pwm2=11;
int irpin1=12;
int irpin2=13;
int motorspeed=130;
String ch;


int trigpin=8;
int echopin=9;
float echovalue,speedofsound=343;
float distance,d1,d2;
int pos=90;
#include<Servo.h>
Servo myservo;


int value1=0,value2=0;
int randomvalue;
int n=0,m=1;

void setup() {
  // put your setup code here, to run once:
  
pinMode( motorpin1,OUTPUT);
pinMode( motorpin2,OUTPUT);
pinMode( motorpin3,OUTPUT);
pinMode( motorpin4,OUTPUT);
pinMode( pwm1,OUTPUT);
pinMode( pwm2,OUTPUT);
pinMode( irpin1,INPUT);
pinMode( irpin2,INPUT);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
myservo.attach(10);
Serial.begin(9600);
Serial.setTimeout(30);
}

void loop() {
  // put your main code here, to run repeatedly:
  
 if(Serial.available())     // True, if data is available on serial
 { ch=Serial.readString();}   // Reading the data in string 
 
 delay(5);
 if( ch<="255" && ch>="10")   // True, if string is between 10 to 255 
 {
  motorspeed=ch.toInt();      // Converting string into integer
 }
  
 if(ch=="Bluetooth")          // Checking condition for Bluetooth Control Car
 {n=1;}

 if(ch=="Obstacle")           // Checking condition for Obstacle Avoider
 {n=2;}

 if(ch=="Line")              // Checking condition for Line Follower
 {n=3;}

 if(ch=="start")              // Checking condition for start of the robot 
 {m=2;}

 if(ch=="stop")               // Checking condition for stop of the robot 
 {m=1;}
 


//Bluetooth Car
 if(n==1)
 {
  if(ch=="F")
  {
    analogWrite(pwm1,motorspeed);
    analogWrite(pwm2,motorspeed);
  digitalWrite(motorpin1,HIGH); 
   digitalWrite(motorpin2,LOW);
    digitalWrite(motorpin3,HIGH); 
     digitalWrite(motorpin4,LOW);  
     
    
  }
   else if(ch=="B")
  {
    analogWrite(pwm1,motorspeed);
    analogWrite(pwm2,motorspeed);
  digitalWrite(motorpin1,LOW) ;
   digitalWrite(motorpin2,HIGH);
    digitalWrite(motorpin3,LOW) ;
     digitalWrite(motorpin4,HIGH);   
    
  }
  else  if(ch=="L")
  {
    analogWrite(pwm1,motorspeed);
    analogWrite(pwm2,motorspeed);
  digitalWrite(motorpin1,HIGH); 
   digitalWrite(motorpin2,LOW);
    digitalWrite(motorpin3,LOW); 
     digitalWrite(motorpin4,HIGH);  
  }
   else if(ch=="R")
  {
    analogWrite(pwm1,motorspeed);
    analogWrite(pwm2,motorspeed);
  digitalWrite(motorpin1,LOW) ;
   digitalWrite(motorpin2,HIGH);
    digitalWrite(motorpin3,HIGH); 
     digitalWrite(motorpin4,LOW) ;  
  }
  else
  { 
    analogWrite(pwm1,motorspeed);
    analogWrite(pwm2,motorspeed);
  digitalWrite(motorpin1,LOW) ;
   digitalWrite(motorpin2,LOW);
    digitalWrite(motorpin3,LOW); 
     digitalWrite(motorpin4,LOW) ;  
  }
 }


 //Obsticle Avoider & Edge Avoider
 else if(n==2 && m==2)
 {
  value1=digitalRead(irpin1);
  value2=digitalRead(irpin2);
   Serial.println(distance);
   digitalWrite(trigpin,LOW);  //set the triger pin of Ultrasonic sensor
   delayMicroseconds(2000);    // waiting for two milli-seconds
   digitalWrite(trigpin,HIGH);  // transmition of sound wave
   delayMicroseconds(10);
   digitalWrite(trigpin,LOW);   
   echovalue=pulseIn(echopin,HIGH);  // time of recieving (in microseconds) 
   distance=speedofsound*echovalue/20000.; // distance in cm

   if(value1==1)
  {
      analogWrite(pwm1,motorspeed);
      analogWrite(pwm2,motorspeed);
      digitalWrite(motorpin1,LOW) ;
      digitalWrite(motorpin2,LOW);
      digitalWrite(motorpin3,LOW); 
      digitalWrite(motorpin4,LOW) ;  
      delay(500);

      analogWrite(pwm1,motorspeed);
      analogWrite(pwm2,motorspeed);
      digitalWrite(motorpin1,LOW) ;
      digitalWrite(motorpin2,HIGH);
      digitalWrite(motorpin3,LOW) ;
      digitalWrite(motorpin4,HIGH);   
      delay(350);
    
      analogWrite(pwm1,motorspeed+50);
      analogWrite(pwm2,motorspeed+50);
      digitalWrite(motorpin1,HIGH); 
      digitalWrite(motorpin2,LOW);
      digitalWrite(motorpin3,LOW); 
      digitalWrite(motorpin4,HIGH);  
      delay(600);
  }
  else if(value2==1)
  {
      analogWrite(pwm1,motorspeed);
      analogWrite(pwm2,motorspeed);
      digitalWrite(motorpin1,LOW) ;
      digitalWrite(motorpin2,LOW);
      digitalWrite(motorpin3,LOW); 
      digitalWrite(motorpin4,LOW) ;  
      delay(500);

      analogWrite(pwm1,motorspeed);
      analogWrite(pwm2,motorspeed);
      digitalWrite(motorpin1,LOW) ;
      digitalWrite(motorpin2,HIGH);
      digitalWrite(motorpin3,LOW) ;
      digitalWrite(motorpin4,HIGH);   
      delay(350);
    
      analogWrite(pwm1,motorspeed+50);
      analogWrite(pwm2,motorspeed+50);
      digitalWrite(motorpin1,LOW) ;
      digitalWrite(motorpin2,HIGH);
      digitalWrite(motorpin3,HIGH); 
      digitalWrite(motorpin4,LOW) ;  
      delay(600);
     }

   if(distance<20)   
   {
      analogWrite(pwm1,motorspeed);
      analogWrite(pwm2,motorspeed);
      digitalWrite(motorpin1,LOW) ;
      digitalWrite(motorpin2,LOW);
      digitalWrite(motorpin3,LOW); 
      digitalWrite(motorpin4,LOW) ;  
      delay(500);

      analogWrite(pwm1,motorspeed);
      analogWrite(pwm2,motorspeed);
      digitalWrite(motorpin1,LOW) ;
      digitalWrite(motorpin2,HIGH);
      digitalWrite(motorpin3,LOW) ;
      digitalWrite(motorpin4,HIGH);   
      delay(350);

     analogWrite(pwm1,motorspeed);
     analogWrite(pwm2,motorspeed);
     digitalWrite(motorpin1,LOW) ;
     digitalWrite(motorpin2,LOW);
     digitalWrite(motorpin3,LOW); 
     digitalWrite(motorpin4,LOW) ;  
      delay(500);
      
     
        myservo.write(10);
        delay(500);
      
      
     digitalWrite(trigpin,LOW);
     delayMicroseconds(2000);
     digitalWrite(trigpin,HIGH);
     delayMicroseconds(10);
     digitalWrite(trigpin,LOW);
     echovalue=pulseIn(echopin,HIGH);
     d1=speedofsound*echovalue/20000.;
     delay(50);
     Serial.println(d1);
   
   
        myservo.write(170);
        delay(500);
      

      
     digitalWrite(trigpin,LOW);
     delayMicroseconds(2000);
     digitalWrite(trigpin,HIGH);
     delayMicroseconds(10);
     digitalWrite(trigpin,LOW);
     echovalue=pulseIn(echopin,HIGH);
     d2=speedofsound*echovalue/20000.;
     delay(50);
     Serial.println(d2);
   
     
        myservo.write(90);
        delay(500);
     
    if(d1>d2)
    { 
       analogWrite(pwm1,motorspeed + 50);
      analogWrite(pwm2,motorspeed + 50);
       digitalWrite(motorpin1,HIGH); 
       digitalWrite(motorpin2,LOW);
       digitalWrite(motorpin3,LOW); 
       digitalWrite(motorpin4,HIGH); 
       delay(600);
   }
   else
   {
      analogWrite(pwm1,motorspeed + 50);
      analogWrite(pwm2,motorspeed + 50);
      digitalWrite(motorpin1,LOW) ;
      digitalWrite(motorpin2,HIGH);
      digitalWrite(motorpin3,HIGH); 
      digitalWrite(motorpin4,LOW) ; 
      delay(600);
    }
      
    }
    else
    {
      analogWrite(pwm1,motorspeed);
      analogWrite(pwm2,motorspeed);
      digitalWrite(motorpin1,HIGH); 
     digitalWrite(motorpin2,LOW);
     digitalWrite(motorpin3,HIGH); 
     digitalWrite(motorpin4,LOW);
        
     }
   
 }


//Line Follower
else if(n==3 && m==2)
 {
 value1=digitalRead(irpin1);
 value2=digitalRead(irpin2);
 if(value1!=1 && value2!=1)
  {
    analogWrite(pwm1,motorspeed-40);
    analogWrite(pwm2,motorspeed-40);
    digitalWrite(motorpin1,HIGH); 
    digitalWrite(motorpin2,LOW);
    digitalWrite(motorpin3,HIGH); 
    digitalWrite(motorpin4,LOW);  
     
  }
 else if(value1==1)
  {
    
    analogWrite(pwm1,motorspeed-10);
    analogWrite(pwm2,motorspeed-10);
   digitalWrite(motorpin1,HIGH); 
   digitalWrite(motorpin2,LOW);
    digitalWrite(motorpin3,LOW); 
     digitalWrite(motorpin4,HIGH);  
     
  }
  else if(value2==1)
  {
    
    analogWrite(pwm1,motorspeed-10);
    analogWrite(pwm2,motorspeed-10);
     digitalWrite(motorpin1,LOW) ;
   digitalWrite(motorpin2,HIGH);
    digitalWrite(motorpin3,HIGH); 
     digitalWrite(motorpin4,LOW) ;  
  }
 }

 if(m==1 && n!=1)
 {
   digitalWrite(motorpin1,LOW) ;
     digitalWrite(motorpin2,LOW);
     digitalWrite(motorpin3,LOW); 
     digitalWrite(motorpin4,LOW) ;
 }
 
  delay(5);
Serial.println(ch);
}
