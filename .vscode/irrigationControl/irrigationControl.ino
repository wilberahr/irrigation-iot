#include <DS18B20.h>

const int hydrometer = A0;
int value;
int humidity;

DS18B20 temperatureSensor(2);

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	getTemperature();
  humidity = getHumidity();

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