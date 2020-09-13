#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library

#define relay_a 2 
#define relay_b 3
#define relay_c 4
#define relay_d 5
#define relay_e 6
#define relay_f 7
#define relay_g 8
#define relay_h 9

#define trigPin A1 //analog input 1
#define echoPin A2 //analog input 2

#define maximum_distance 200
int distance = 50;
int readPing();
NewPing sonar(trigPin, echoPin, maximum_distance); //sensor function

void setup(){

Serial.begin(9600);
  
pinMode(relay_a, OUTPUT); 
pinMode(relay_b, OUTPUT);
pinMode(relay_c, OUTPUT); 
pinMode(relay_d, OUTPUT);
pinMode(relay_e, OUTPUT);
pinMode(relay_f, OUTPUT);
pinMode(relay_g, OUTPUT);
pinMode(relay_h, OUTPUT);

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

digitalWrite(relay_a,HIGH);
digitalWrite(relay_b,HIGH);
digitalWrite(relay_c,HIGH);
digitalWrite(relay_d,HIGH);
digitalWrite(relay_e,HIGH);
digitalWrite(relay_f,HIGH);
digitalWrite(relay_g,HIGH);
digitalWrite(relay_h,HIGH);
Serial.println("Mati");

distance = readPing();
delay(100);
}

void loop(){
  if (distance < 10){
    digitalWrite(relay_a,HIGH);
    digitalWrite(relay_b,HIGH);
    digitalWrite(relay_c,HIGH);
    digitalWrite(relay_d,HIGH);
    digitalWrite(relay_e,HIGH);
    digitalWrite(relay_f,HIGH);
    digitalWrite(relay_g,HIGH);
    digitalWrite(relay_h,HIGH);
    delay(300);
    digitalWrite(relay_a,LOW);
    digitalWrite(relay_b,HIGH);
    digitalWrite(relay_c,HIGH);
    digitalWrite(relay_d,LOW);
    digitalWrite(relay_e,HIGH);
    digitalWrite(relay_f,LOW);
    digitalWrite(relay_g,LOW);
    digitalWrite(relay_h,HIGH);
    delay(400);
    digitalWrite(relay_a,HIGH);
    digitalWrite(relay_b,HIGH);
    digitalWrite(relay_c,HIGH);
    digitalWrite(relay_d,HIGH);
    digitalWrite(relay_e,HIGH);
    digitalWrite(relay_f,HIGH);
    digitalWrite(relay_g,HIGH);
    digitalWrite(relay_h,HIGH);
    delay(300);
  }
  if (Serial.available()>0)
  {
    int command = Serial.read();
    if (command =='F')
    {
    digitalWrite(relay_a,HIGH);
    digitalWrite(relay_b,LOW);
    digitalWrite(relay_c,LOW);
    digitalWrite(relay_d,HIGH);
    digitalWrite(relay_e,LOW);
    digitalWrite(relay_f,HIGH);
    digitalWrite(relay_g,HIGH);
    digitalWrite(relay_h,LOW);
    Serial.println("Maju");
    }
    if (command =='B')
    {
    digitalWrite(relay_a,LOW);
    digitalWrite(relay_b,HIGH);
    digitalWrite(relay_c,HIGH);
    digitalWrite(relay_d,LOW);
    digitalWrite(relay_e,HIGH);
    digitalWrite(relay_f,LOW);
    digitalWrite(relay_g,LOW);
    digitalWrite(relay_h,HIGH);
    Serial.println("Mundur");
    }
    if (command =='L')
    {
    digitalWrite(relay_a,HIGH);
    digitalWrite(relay_b,LOW);
    digitalWrite(relay_c,LOW);
    digitalWrite(relay_d,HIGH);
    digitalWrite(relay_e,HIGH);
    digitalWrite(relay_f,LOW);
    digitalWrite(relay_g,LOW);
    digitalWrite(relay_h,HIGH);
    Serial.println("Kiri");
    }
    if (command =='R')
    {
    digitalWrite(relay_a,LOW);
    digitalWrite(relay_b,HIGH);
    digitalWrite(relay_c,HIGH);
    digitalWrite(relay_d,LOW);
    digitalWrite(relay_e,LOW);
    digitalWrite(relay_f,HIGH);
    digitalWrite(relay_g,HIGH);
    digitalWrite(relay_h,LOW);
    Serial.println("Kanan");
    }
    if (command =='S')
    {
    digitalWrite(relay_a,HIGH);
    digitalWrite(relay_b,HIGH);
    digitalWrite(relay_c,HIGH);
    digitalWrite(relay_d,HIGH);
    digitalWrite(relay_e,HIGH);
    digitalWrite(relay_f,HIGH);
    digitalWrite(relay_g,HIGH);
    digitalWrite(relay_h,HIGH);
    Serial.println("Stop");
    } 
  }
    distance = readPing();
}
