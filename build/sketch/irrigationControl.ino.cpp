#include <Arduino.h>
#line 1 "G:\\My Drive\\Courses\\UCR\\IE0624 Laboratorio de microcontroladores\\Proyecto\\irrigation-iot\\.vscode\\irrigationControl\\irrigationControl.ino"
#include <DS18B20.h>

const int hydrometer = A0;
const int fowardPin = 12;
const int speedMotorPin = 11;

int value;
int humidity;

DS18B20 temperatureSensor(2);

#line 12 "G:\\My Drive\\Courses\\UCR\\IE0624 Laboratorio de microcontroladores\\Proyecto\\irrigation-iot\\.vscode\\irrigationControl\\irrigationControl.ino"
void setup();
#line 19 "G:\\My Drive\\Courses\\UCR\\IE0624 Laboratorio de microcontroladores\\Proyecto\\irrigation-iot\\.vscode\\irrigationControl\\irrigationControl.ino"
void loop();
#line 34 "G:\\My Drive\\Courses\\UCR\\IE0624 Laboratorio de microcontroladores\\Proyecto\\irrigation-iot\\.vscode\\irrigationControl\\irrigationControl.ino"
void getTemperature();
#line 42 "G:\\My Drive\\Courses\\UCR\\IE0624 Laboratorio de microcontroladores\\Proyecto\\irrigation-iot\\.vscode\\irrigationControl\\irrigationControl.ino"
int getHumidity();
#line 52 "G:\\My Drive\\Courses\\UCR\\IE0624 Laboratorio de microcontroladores\\Proyecto\\irrigation-iot\\.vscode\\irrigationControl\\irrigationControl.ino"
void waterPlants(int speed);
#line 12 "G:\\My Drive\\Courses\\UCR\\IE0624 Laboratorio de microcontroladores\\Proyecto\\irrigation-iot\\.vscode\\irrigationControl\\irrigationControl.ino"
void setup()
{
	pinMode(fowardPin,OUTPUT);
  digitalWrite(fowardPin,HIGH);
  Serial.begin(9600);
}

void loop()
{
	getTemperature();
  humidity = getHumidity();

  if(humidity == 0){
    waterPlants(100);
  }
  else{
    waterPlants(50);
  }

  delay(2000);
}

void getTemperature(){
  while (temperatureSensor.selectNext()) {
    Serial.print("Temperature (celsius): ");
    Serial.println(temperatureSensor.getTempC());
  }

}

int getHumidity(){

  value = analogRead(hydrometer);
  value = constrain(value,400,1023);
  value = map(value,400,1023,100,0);
  Serial.print("Soil humidity (%): ");
  Serial.println(value);
  return value;
}

void waterPlants(int speed){
  speed = map(speed,0,100,0,255);
  analogWrite(speedMotorPin,speed);
  Serial.print("Speed (%): ");
  Serial.println(speed);
}

