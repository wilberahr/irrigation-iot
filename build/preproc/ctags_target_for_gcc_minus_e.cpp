# 1 "G:\\My Drive\\Courses\\UCR\\IE0624 Laboratorio de microcontroladores\\Proyecto\\irrigation-iot\\.vscode\\irrigationControl\\irrigationControl.ino"
# 2 "G:\\My Drive\\Courses\\UCR\\IE0624 Laboratorio de microcontroladores\\Proyecto\\irrigation-iot\\.vscode\\irrigationControl\\irrigationControl.ino" 2

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
