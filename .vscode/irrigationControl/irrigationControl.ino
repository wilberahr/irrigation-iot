#include <DS18B20.h>

DS18B20 ds(2);

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	getTemperature();
}

void getTemperature(){
  while (ds.selectNext()) {
    Serial.print("Temperature (celsius): ");
    Serial.println(ds.getTempC());
  }

}