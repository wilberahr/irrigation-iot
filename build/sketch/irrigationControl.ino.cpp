#include <Arduino.h>
#line 1 "G:\\My Drive\\Courses\\UCR\\IE0624 Laboratorio de microcontroladores\\Proyecto\\irrigation-iot\\.vscode\\irrigationControl\\irrigationControl.ino"
#include <DS18B20.h>

DS18B20 ds(2);

#line 5 "G:\\My Drive\\Courses\\UCR\\IE0624 Laboratorio de microcontroladores\\Proyecto\\irrigation-iot\\.vscode\\irrigationControl\\irrigationControl.ino"
void setup();
#line 10 "G:\\My Drive\\Courses\\UCR\\IE0624 Laboratorio de microcontroladores\\Proyecto\\irrigation-iot\\.vscode\\irrigationControl\\irrigationControl.ino"
void loop();
#line 15 "G:\\My Drive\\Courses\\UCR\\IE0624 Laboratorio de microcontroladores\\Proyecto\\irrigation-iot\\.vscode\\irrigationControl\\irrigationControl.ino"
void getTemperature();
#line 5 "G:\\My Drive\\Courses\\UCR\\IE0624 Laboratorio de microcontroladores\\Proyecto\\irrigation-iot\\.vscode\\irrigationControl\\irrigationControl.ino"
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
