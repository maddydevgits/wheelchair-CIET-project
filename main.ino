#include <Wire.h>
#include <Adafruit_Sensor.h> 
#include <Adafruit_ADXL345_U.h>

int in1=2;
int in2=3;
int in3=4;
int in4=5;

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();

void setup(void) 
{
   pinMode(in1,OUTPUT);
   pinMode(in2,OUTPUT);
   pinMode(in3,OUTPUT);
   pinMode(in4,OUTPUT);
   
   Serial.begin(9600);  
   if(!accel.begin())
   {
      Serial.println("No valid sensor found");
      while(1);
   }
}

void loop(void) 
{
   sensors_event_t event; 
   accel.getEvent(&event);

   Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
   Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
   Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");
   Serial.println("m/s^2 ");

   float x=event.acceleration.x;
   float y=event.acceleration.y;
   float z=event.acceleration.z;

   if((x>2 && x<9) && (y>-3 && y<1.5)) {
    Serial.println("LEFT");
    left();
   } else if((x>-10 && x<-2) && (y>-2 && y<0)){
    Serial.println("RIGHT");
   } else if((x>0 && x<3) && (y>3 && y<10)) {
    Serial.println("FRONT");
    forward();
   } else if((x>0 && x<2) && (y>-9 && y<-3)) {
    Serial.println("BACK");
    back();
   } else {
    stopp();
   }

   delay(500);
}

void forward() {
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
}

void back() {
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
}

void left() {
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
  delay(1000);
  forward();
}

void right() {
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,0);
  delay(1000);
  forward();
}

void stopp() {
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,0);
}
