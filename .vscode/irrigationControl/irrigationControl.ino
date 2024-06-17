#include <DS18B20.h>

DS18B20 temperatureSensor(2);

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	getTemperature();
}

void getTemperature(){
  while (temperatureSensor.selectNext()) {
    Serial.print("Temperature (celsius): ");
    Serial.println(temperatureSensor.getTempC());
  }

}