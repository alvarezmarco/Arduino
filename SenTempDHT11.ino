

#include <DHT.h>
/*
 Autor: Marco Alvarez M.
 Permite el control de un sensor de humedad y temperatura DHT11.
 Se necesita instalar la libreria DHT-sensor-library 
 */

//Variable donde se conecta el sensor, en este caso al pin 2 
int sen_pin_conect=2;
int temperatura, humedad;
int espera = 10000;


//Se Define una constante de la librería
DHT dht(sen_pin_conect, DHT11); //DHT11 es el tipo de sensor a utilizar
// Variables que controlan los leds y colores se asigna el número de pin al que se conecta.
int led_rojo=6;
int led_verde=5;
int led_amarillo=3;

void setup() {
  
  Serial.begin(9600);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  dht.begin();
  
}

void loop() {
  humedad = dht.readHumidity();
  temperatura=dht.readTemperature();
  Serial.println("Temperatura: "+String(temperatura)+"Centígrados");
  Serial.println("Humedad: "+String(humedad)+" %");
  
  if(temperatura<20){
      //Si la temperatura es menor que 20 se enciende el led amarillo
      encender_amarillo();
      Serial.println("Led Amarillo Encendido");    
    } else {
          //Si la temperatura es mayor o igual que 20 pero menor 30  se enciende el led amarillo
             if (temperatura>=20 && temperatura<30){
                encender_verde();
                Serial.println("Led Verde Encendido");
            
          } else {
                    Serial.println("Temperatura mayor que 30");
                    encender_rojo();
                    Serial.println("Led Rojo Encendido");
                }
       }
   //Se espera 10 segundos para una nueva medición
    delay(espera);

}
void encender_rojo(){
  
   digitalWrite(led_rojo, HIGH);
   digitalWrite(led_verde, LOW);
   digitalWrite(led_amarillo, LOW);
   
}

void encender_verde(){
    digitalWrite(led_rojo, LOW);
   digitalWrite(led_verde, HIGH);
   digitalWrite(led_amarillo, LOW);
}


void encender_amarillo(){
   digitalWrite(led_rojo, LOW);
   digitalWrite(led_verde, LOW);
   digitalWrite(led_amarillo, HIGH);
}
