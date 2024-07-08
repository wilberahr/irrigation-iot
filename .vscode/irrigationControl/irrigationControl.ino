#include <DS18B20.h>

const int hydrometer = A0;
const int fowardPin = 12;
const int speedMotorPin = 11;

int value;
int humidity;
float temperature;

DS18B20 temperatureSensor(2);

void setup()
{
	pinMode(fowardPin,OUTPUT);
  digitalWrite(fowardPin,HIGH);
  Serial.begin(9600);
}

void loop()
{
  temperature = getTemperature();
  humidity = getHumidity();
  if(humidity == 0 && temperature < 30){
    waterPlants(100);
  }
  else{
    if(humidity == 1 && temperature < 30)
      else{
        waterPlants(0);
      }
    )else {
      if (temperature >=30){
         waterPlants(0)
      }else{
        waterPlants(0)
      }
    }  
  }

  delay(2000);
}

float getTemperature(){
  while (temperatureSensor.selectNext()) {
    Serial.print("Temperature (celsius): ");
    Serial.println(temperatureSensor.getTempC());
  }
  return temperatureSensor.getTempC();
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
