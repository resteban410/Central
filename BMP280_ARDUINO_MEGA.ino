/*
  Capitulo 36 de Arduino desde cero en Español.
  Programa que muestra en monitor serie los valores de temperatura, presion
  atmosferica y altitud relativa del sensor BMP280 conectado mediante bus I2C.

  Autor: bitwiseAr  

*/

#include <Wire.h>   // incluye libreria de bus I2C
#include <Adafruit_Sensor.h>  // incluye librerias para sensor BMP280
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;    // crea objeto con nombre bmp

float TEMPERATURA;    // variable para almacenar valor de temperatura
float PRESION, P0;    // variables para almacenar valor de presion atmosferica
        // y presion actual como referencia para altitud

void setup() {
  Serial.begin(9600);       // inicializa comunicacion serie a 9600 bps
  Serial.println("Iniciando:");     // texto de inicio
  if ( !bmp.begin() ) {       // si falla la comunicacion con el sensor mostrar
    Serial.println("BMP280 no encontrado !"); // texto y detener flujo del programa
    while (1);          // mediante bucle infinito
  }
  P0 = bmp.readPressure()/100;      // almacena en P0 el valor actual de presion
}           // en hectopascales para calculo de altitud relativa

void loop() {
  TEMPERATURA = bmp.readTemperature();    // almacena en variable el valor de temperatura
  PRESION = bmp.readPressure()/100;   // almacena en variable el valor de presion divido
            // por 100 para covertirlo a hectopascales
  Serial.print("Temperatura: ");    // muestra texto
  Serial.print(TEMPERATURA);      // muestra valor de la variable
  Serial.print(" C ");        // muestra letra C indicando grados centigrados
    
  Serial.print("Presion: ");      // muestra texto
  Serial.print(PRESION);      // muestra valor de la variable
  Serial.println(" hPa");     // muestra texto hPa indicando hectopascales

  Serial.print("Altitud aprox: ");    // muestra texto
  Serial.print(bmp.readAltitude(P0));   // muestra valor de altitud con referencia a P0
  Serial.println(" m");       // muestra letra m indicando metros

  delay(50000);          // demora de 5 segundos entre lecturas
}
