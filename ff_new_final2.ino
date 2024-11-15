#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor M1(1);
AF_DCMotor M2(2);
int left_sensor = A4; 
int middle_sensor = A3; 
int right_sensor = A2;
int water_pump =12;
int servo_pin=11;
Servo myservo;
int pos = 0;

void setup() {
  M1.setSpeed(80);        
  M2.setSpeed(80);
  pinMode(water_pump, OUTPUT);
  pinMode(left_sensor, INPUT);
  pinMode(middle_sensor, INPUT);
  pinMode(right_sensor, INPUT);
}
 
void loop() {
  if(digitalRead(middle_sensor) == LOW)
  {
  M1.run(FORWARD);
  M2.run(FORWARD);
  delay(600);
  delay(15);
  M1.run(RELEASE);
  M2.run(RELEASE);
  delay(1000);
  digitalWrite(water_pump, LOW);
    delay(15);  
     myservo.attach(servo_pin); 
     for(int j = 0 ; j<4;j++)
     {
       for (pos = 90; pos <= 180; pos += 1) {
      
        myservo.write(pos);            
        delay(15);                     
        }
        for (pos = 180; pos >= 90; pos -= 1) { 
        myservo.write(pos);              
        delay(15);                       
      }
     }
    
     myservo.detach();
  }

   else if(digitalRead(left_sensor) == LOW)
  {
  M1.run(FORWARD);
  M2.run(BACKWARD);
  delay(400);
  M1.run(RELEASE);
  M2.run(RELEASE); 
  delay(100);
  M1.run(FORWARD);
  M2.run(FORWARD);
  delay(600);
  M1.run(RELEASE);
  M2.run(RELEASE); 
  delay(100);
  digitalWrite(water_pump, LOW);
    delay(15);  
     myservo.attach(servo_pin); 
     for(int j = 0 ; j<4;j++)
     {
       for (pos = 90; pos <= 180; pos += 1) { 
        // in steps of 1 degree
        myservo.write(pos);             
        delay(15);                       
        }
        for (pos = 180; pos >= 90; pos -= 1) { 
        myservo.write(pos);              
        delay(15);                     
      }
     }
    
     myservo.detach();
  }
     M1.run(RELEASE);
     M2.run(RELEASE);
    digitalWrite(water_pump, HIGH);
  
 }
