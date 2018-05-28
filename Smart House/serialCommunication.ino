#include <ArduinoJson.h>
#include <GP2Y0A02YK0F.h>
#include <TinkerKit.h>
#include "DHT.h"

#define DHTPIN 8                        // digital pin we're connected to
#define DHTTYPE DHT11                   // DHT 11

#define led1 3                          //define the pin's for leds
#define led2 4
#define led3 5
#define led4 6
#define led5 7

#define trigPin1 A4                     //define pin's for the ultrasonic sensor
#define echoPin1 A3

#define trigPin2 12
#define echoPin2 A5

#define trigPin3 11
#define echoPin3 10

long duration, distance;
long sensor_Room3 , sensor_Room4 , sensor_Room5;

GP2Y0A02YK0F irSensor1;                 
GP2Y0A02YK0F irSensor2;
int sensor_Room1, sensor_Room2;
  
DHT dht(DHTPIN, DHTTYPE);                 //set temperature sensor

TKLightSensor ldr(I0);                    //initialize ldr sensor

int led1_n = 1;                           //get the id from led
int led2_n = 2;
int led3_n = 3;
int led4_n = 4;
int led5_n = 5;

bool led1_status = false;
bool led2_status = false;
bool led3_status = false;
bool led4_status = false;
bool led5_status = false;

int led1_auto_status = 0 , led2_auto_status = 0 , led3_auto_status = 0 , led4_auto_status = 0 , led5_auto_status = 0 ;
int led1_auto_mode = 0 , led2_auto_mode = 0 , led3_auto_mode = 0 , led4_auto_mode = 0 , led5_auto_mode = 0;

int threshold = 0;
int auto_mode = 0;

int room1_occupied = 0 , room2_occupied = 0 , room3_occupied = 0 , room4_occupied = 0 , room5_occupied = 0 ; 

const int bSize = 20;
char Buffer[bSize];                           //Serial buffer

String cmd , cmdAux;

char dataBuffer[20];


void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);                     // need to read string, default 1000

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  digitalWrite(led1 , LOW);                   //in the beggining all lights are off
  digitalWrite(led2 , LOW);
  digitalWrite(led3 , LOW);
  digitalWrite(led4 , LOW);
  digitalWrite(led5 , LOW);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  irSensor1.begin(A1);
  irSensor2.begin(A2);

  dht.begin();
}

void loop() {
  //initiate JsonBuffer
  StaticJsonBuffer<50> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();


  //--Temperature--
  float temp = dht.readTemperature();
  
  //--Light Sensor--
  int brightnessVal = ldr.read();
  delay(100);
  
  //Serial.print(brightnessVal);
  //Serial.print(" | ");
  //Serial.println(threshold);
  if(brightnessVal <= threshold){                                                           
    if(led1_auto_status == 1 && led1_status == false){                                         //send json object for each of the leds 
      digitalWrite(led1,HIGH);
      led1_status = true;
      led1_auto_mode = 1;

      root["source"]            = "light";
      root["id"]                = led1_n;
      root["turnon"]            = led1_status;
      root.printTo(Serial);
      jsonBuffer.clear();
    }
    if(led2_auto_status == 1 && led2_status == false){
      digitalWrite(led2,HIGH);
      led2_status = true;
      led2_auto_mode = 1;

      root["source"]            = "light";
      root["id"]                = led2_n;
      root["turnon"]            = led2_status;
      root.printTo(Serial);
      jsonBuffer.clear();
    }
    if(led3_auto_status == 1 && led3_status == false){
      digitalWrite(led3,HIGH);
      led3_status = true;
      led3_auto_mode = 1;

      root["source"]            = "light";
      root["id"]                = led3_n;
      root["turnon"]            = led3_status;
      root.printTo(Serial);
      jsonBuffer.clear();
    }
    if(led4_auto_status == 1 && led4_status == false){
      digitalWrite(led4,HIGH);
      led4_status = true;
      led4_auto_mode = 1;

      root["source"]            = "light";
      root["id"]                = led4_n;
      root["turnon"]            = led4_status;
      root.printTo(Serial);
      jsonBuffer.clear();
    }
     if(led5_auto_status == 1 && led5_status == 0){
      digitalWrite(led5,HIGH);
      led5_status = true;
      led5_auto_mode = 1;

      root["source"]            = "light";
      root["id"]                = led5_n;
      root["turnon"]            = led5_status;
      root.printTo(Serial);
      jsonBuffer.clear();
    }
  }
  
  else if(brightnessVal > threshold){
    if(led1_auto_status == 1 && room1_occupied == 0 && led1_auto_mode == 1){                        //send json object for each of the leds
      digitalWrite(led1,LOW);
      led1_status = false;
      led1_auto_mode = 0;

      root["source"]            = "light";
      root["id"]                = led1_n;
      root["turnon"]            = led1_status;
      root.printTo(Serial);
      jsonBuffer.clear();
    }
    if(led2_auto_status == 1 && room2_occupied == 0 && led2_auto_mode == 1){
      digitalWrite(led2,LOW);
      led2_status = false;
      led2_auto_mode = 0;

      root["source"]            = "light";
      root["id"]                = led2_n;
      root["turnon"]            = led2_status;
      root.printTo(Serial);
      jsonBuffer.clear();
    }
    if(led3_auto_status == 1 && room3_occupied == 0 && led3_auto_mode == 1){
      digitalWrite(led3,LOW);
      led3_status = false;
      led3_auto_mode = 0;

      root["source"]            = "light";
      root["id"]                = led3_n;
      root["turnon"]            = led3_status;
      root.printTo(Serial);
      jsonBuffer.clear();
    }    
    if(led4_auto_status == 1 && room4_occupied == 0 && led4_auto_mode == 1){
      digitalWrite(led4,LOW);
      led4_status = false;
      led4_auto_mode = 0;

      root["source"]            = "light";
      root["id"]                = led4_n;
      root["turnon"]            = led4_status;
      root.printTo(Serial);
      jsonBuffer.clear();
    }
     if(led5_auto_status == 1 && room5_occupied == 0 && led5_auto_mode == 1){
      digitalWrite(led5,LOW);
      led5_status = false;
      led5_auto_mode = 0;

      root["source"]            = "light";
      root["id"]                = led5_n;
      root["turnon"]            = led5_status;
      root.printTo(Serial);
      jsonBuffer.clear();
    }
  }


  //--Distance Sensor--
  //Sensor 1
  sensor_Room1 = irSensor1.getDistanceCentimeter();
  if(sensor_Room1 < 15 && led1_status == false && room1_occupied == 0){
    digitalWrite(led1,HIGH);
    led1_status = true;
    room1_occupied = 1;
    
    root["source"]            = "light";
    root["id"]                = led1_n;
    root["turnon"]            = led1_status;
    root.printTo(Serial);
  }
  
  if(sensor_Room1 > 15 && led1_status == true && room1_occupied == 1){
    digitalWrite(led1,LOW);
    led1_status = false;
    room1_occupied = 0;  

    root["source"]            = "light";
    root["id"]                = led1_n;
    root["turnon"]            = led1_status;
    root.printTo(Serial);
  }

  //Sensor 2
  sensor_Room2 = irSensor2.getDistanceCentimeter();
  if(sensor_Room2 < 15 && led2_status == false && room2_occupied == 0){
    digitalWrite(led2,HIGH);
    led2_status = true;
    room2_occupied = 1;

    root["source"]            = "light";
    root["id"]                = led2_n;
    root["turnon"]            = led2_status;
    root.printTo(Serial);
  }
  
  if(sensor_Room2 > 15 && led2_status == true && room2_occupied == 1){
    digitalWrite(led2,LOW);
    led2_status = false;
    room2_occupied = 0;

    root["source"]            = "light";
    root["id"]                = led2_n;
    root["turnon"]            = led2_status;
    root.printTo(Serial); 
  }

  //Sensor 3
  sensor_Room3 = SonarSensor(trigPin1, echoPin1);
  if(sensor_Room3 < 15 && led3_status == false && room3_occupied == 0){
    digitalWrite(led3,HIGH);
    led3_status = true;
    room3_occupied = 1;

    root["source"]            = "light";
    root["id"]                = led3_n;
    root["turnon"]            = led3_status;
    root.printTo(Serial);
  }
  
  if(sensor_Room3 > 15 && led3_status == true && room3_occupied == 1){
    digitalWrite(led3,LOW);
    led3_status = false;
    room3_occupied = 0;

    root["source"]            = "light";
    root["id"]                = led3_n;
    root["turnon"]            = led3_status;
    root.printTo(Serial);
  }

  //Sensor 4
  sensor_Room4 = SonarSensor(trigPin2, echoPin2);
  if(sensor_Room4 < 15 && led4_status == false && room4_occupied == 0){
    digitalWrite(led4,HIGH);
    led4_status = true;
    room4_occupied = 1;

    root["source"]            = "light";
    root["id"]                = led4_n;
    root["turnon"]            = led4_status;
    root.printTo(Serial);
  }
  
  if(sensor_Room4 > 15 && led4_status == true && room4_occupied == 1){
    digitalWrite(led4,LOW);
    led4_status = false;
    room4_occupied = 0;

    root["source"]            = "light";
    root["id"]                = led4_n;
    root["turnon"]            = led4_status;
    root.printTo(Serial);
  }

  //Sensor 5
  sensor_Room5 = SonarSensor(trigPin3, echoPin3);
  if(sensor_Room5 < 15 && led5_status == false && room5_occupied == 0){
    digitalWrite(led5,HIGH);
    led5_status = true;
    room5_occupied = 1;
    
    root["source"]            = "light";
    root["id"]                = led5_n;
    root["turnon"]            = led5_status;
    root.printTo(Serial);
  }
  
  if(sensor_Room5 > 15 && led5_status == true && room5_occupied == 1){
    digitalWrite(led5,LOW);
    led5_status = false;
    room5_occupied = 0;

    root["source"]            = "light";
    root["id"]                = led5_n;
    root["turnon"]            = led5_status;
    root.printTo(Serial);
  }

  
  //Something to read from Serial
  if (Serial.available() > 0) {
    Serial.readBytesUntil('\n',Buffer,bSize);
    cmd = String(Buffer);                                                   // Set buffer as String
    memset(Buffer, 0, sizeof(Buffer));                                      // Clear contents of Buffer

    //--THRESHOLD--
    cmdAux = cmd.substring(0,16);                                           // Parse threshold
    if(cmdAux == "house_threshold_"){                                    
      //Serial.println(cmd.substring(16));                                       
      threshold = cmd.substring(16).toInt();                                //get threshold value from 0 to 1023 
      //Serial.println(threshold);
    }

    //--all the leds STATUS--
    if(cmd=="leds_STATUS"){
      root["led1"]              = led1_status ;
      root["led2"]              = led2_status ;
      root["led3"]              = led3_status ;
      root["led4"]              = led4_status ;
      root["led5"]              = led5_status ;
      root["temp"]              = temp;
      root["led1_auto"]         = led1_auto_status ;
      root["led2_auto"]         = led2_auto_status ;  
      root["led3_auto"]         = led3_auto_status ;
      root["led4_auto"]         = led4_auto_status ;
      root["led5_auto"]         = led5_auto_status ;
      root["luminosity"]        = brightnessVal ;
      root["threshold"]         = threshold;
      root.prettyPrintTo(Serial);
    }

    //--led ON/OFF--
    if(cmd=="led1_ON"){
      //Serial.println("Ligar Led1");
      if(led1_status == false && room1_occupied == 0){
        digitalWrite(led1,HIGH);
        led1_status = true;
      }
    }
    
    if(cmd=="led1_OFF"){
      //Serial.println("Desligar Led1");
      if(led1_status == true && room1_occupied == 0 && led1_auto_mode == 0){
        digitalWrite(led1,LOW);
        led1_status = false;
      }
    }

     if(cmd=="led2_ON"){
      //Serial.println("Ligar Led2");
      if(led2_status == false && room2_occupied == 0){
        digitalWrite(led2,HIGH);
        led2_status = true;
      }
    }
    
    if(cmd=="led2_OFF"){
      //Serial.println("Desligar Led2");
      if(led2_status == true && room2_occupied == 0){
        digitalWrite(led2,LOW);
        led2_status = false;
      }
    }    

    if(cmd=="led3_ON"){
      //Serial.println("Ligar Led3");
      if(led3_status == false && room3_occupied == 0){
        digitalWrite(led3,HIGH);
        led3_status = true;
      }
    }
    
    if(cmd=="led3_OFF"){
      //Serial.println("Desligar Led3");
      if(led3_status == true && room3_occupied == 0){
        digitalWrite(led3,LOW);
        led3_status = false;
      }
    } 
    
    if(cmd=="led4_ON"){
      //Serial.println("Ligar Led4");
      if(led4_status == false && room4_occupied == 0){
        digitalWrite(led4,HIGH);
        led4_status = true;
      }
    }
    
    if(cmd=="led4_OFF"){
      //Serial.println("Desligar Led4");
      if(led4_status == true && room4_occupied == 0){
        digitalWrite(led4,LOW);
        led4_status = false;
      }
    } 

    if(cmd=="led5_ON"){
      //Serial.println("Ligar Led5");
      if(led5_status == false && room5_occupied == 0){
        digitalWrite(led5,HIGH);
        led5_status = true;
      }
    }
    
    if(cmd=="led5_OFF"){
      //Serial.println("Desligar Led5");
      if(led5_status == true && room5_occupied == 0){
        digitalWrite(led5,LOW);
        led5_status = false;
      }
    }

    //--house_auto_(ON/OFF)--
    if(cmd == "house_auto_ON"){
      //Serial.println("House_auto_ON");
      led1_auto_status = 1;
      led2_auto_status = 1;
      led3_auto_status = 1;
      led4_auto_status = 1;
      led5_auto_status = 1;
      auto_mode = 1; 
    }
  
    if(cmd == "house_auto_OFF"){
      //Serial.println("House_auto_OFF");
      led1_auto_status = 0;
      led2_auto_status = 0;
      led3_auto_status = 0;
      led4_auto_status = 0;
      led5_auto_status = 0;
      auto_mode = 0;
    }

    //--get temperature--
    if(cmd == "temperature"){
      Serial.println(temp);
      //root["source"]            = "sensor";
      //root["value"]              = temp;
      //root.printTo(Serial);
      //root.prettyPrintTo(Serial);
    }

    //--get luminosity--
    if(cmd == "luminosity"){
      Serial.println(brightnessVal);
      //root["source"]            = "sensor";
      //root["value"]              = brightnessVal;
      //root.printTo(Serial);
      //root.prettyPrintTo(Serial);
    }

    if(cmd == "house_settings"){
      root["source"]            = "settings";
      root["automatic"]         = auto_mode;
      root["threshold"]         = threshold;
      root.printTo(Serial);
    }
  }

jsonBuffer.clear();                                             //clean jsonBuffer
}


//measurements from the ultrasonic sensor
long SonarSensor(int trigPin,int echoPin){                      
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}





