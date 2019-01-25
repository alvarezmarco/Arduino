#include <LiquidCrystal.h>
#include <DHT.h>

// Se inicializa la librería con el número de pines
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
//Pin donde se conecta el sensor
byte sen_pin_conect=2;
byte temperatura, humedad;

DHT dht(sen_pin_conect, DHT11);

void setup() {
  // Indica el número de columnas y filas del LCD, en este caso 16 columnas y dos filas que tiene el LCD 1602
   lcd.begin(16, 2);
     dht.begin();
   lcd.print("Dig. Thermometer");
 
}

void loop() {
   
   humedad = dht.readHumidity();
   temperatura=dht.readTemperature();
   lcd.setCursor(0, 1);
   lcd.print("Temp:"+ String (temperatura)+"C Hum:"+String(humedad)+"%");
   
}
