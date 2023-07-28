#include<Servo.h>
const int servotrig = 9;
const int servoecho = 8;

const int trigPin = 2;
const int echoPin = 3;

int distance=0;
int duration=0;

const int LED1 = A0;
const int LED2 = A1;
const int LED3 = A2;
const int LED4 = A3;

Servo gate;


void setup() {
  Serial.begin(9600);
  
  pinMode(servotrig, OUTPUT);
  pinMode(servoecho, INPUT);
  
  gate.attach(7);
  

}

void loop() {

  digitalWrite(servotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(servotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(servotrig,LOW);

  long t =pulseIn(servoecho,HIGH);

  long cm = t /29 / 2;

  gate.write(170);

  if (cm<= 19){

    for( int j=170;j>=80;j--){
      gate.write(j);
      delay(20);
    }

    delay(3500);
    
    for( int i=80;i<=170;i++){
    gate.write(i);
    delay(20);
  }
   
  }
  else{
    gate.write(170);
  }

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;

  if ( distance <= 2 )
  {
    digitalWrite(LED1, HIGH);
  }
  else{
    digitalWrite(LED1, LOW);
  }
  if ( distance <= 5 )
  {
    digitalWrite(LED2, HIGH);
  }
  else{
    digitalWrite(LED2, LOW);
  }
  if ( distance <= 8 )
  {
    digitalWrite(LED3, HIGH);
  }
  else{
    digitalWrite(LED3, LOW);
  }
  if ( distance <= 11 )
  {
    digitalWrite(LED4, HIGH);
  }
  else{
    digitalWrite(LED4, LOW);
  }
  delay(100);

}

//this code is perfect, just make changes in the distances