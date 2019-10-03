#include <HCSR04.h>

// Initialize sensor that uses digital pins 13 and 12.
int triggerPin = 13;
int echoPin = 12;

int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

int ena = 8;
int enb = 9;

UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);
  
void setup()
{

  Serial.begin(9600);
  //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);

 
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);

 
 digitalWrite(ena, HIGH);
 digitalWrite(enb, HIGH);
 
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
}

void clearOuts(){
  
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
}

void rightForward(){
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
  
}

void rightOff(){
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);
}

void rightBack(){
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
  
}
void leftForward(){
  
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
}

void leftOff(){
  
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, HIGH);
}

void leftBack(){
  
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
}

void moveForward(){
  Serial.println("FROWARD");
  rightForward();
  leftForward();
}

void stopMove(){
  rightOff();
  leftOff();
}

void moveBackward(){
  rightBack();
  leftBack();
}

void loop()
{
  double distance = distanceSensor.measureDistanceCm();
  Serial.print("DISTANCE ");
  Serial.println(distance);
  if (distance < 0){
    moveForward();
  } else if(distance < 30){
  Serial.println("LEFT");
    stopMove();
    leftForward();
  } else {
    moveForward();
  }
}
