#include <stdio.h>
#include <stdlib.h>

int pinSensor = 13;            //Vib
int redP = 12;                   
int greenP = 11;
int pirPin = 2;                 // PIR Out pin 
int pirStat = 0;                // PIR status
int pinLuz = A0;
int xpin = A2;                  
int ypin = A3;                  
int zpin = A4;
int minVal = 280; // Valor mínimo del acelerometro en reposo
int maxVal = 415; // Valor máximo del acelerometro en reposo

//Este programa permite conocer la temperatura con el sensor DS18B20
//Para obtener la temperatura del sensor LM35, es necesario amplificar la señal. Se ha realizado la prueba exitosamente en Proteus.
#include <OneWire.h> //Se incluye esta librería que permite la comunicación con un solo pin
#include <DallasTemperature.h>//Se incluye la librería Dallas para realizar la lectura del sensor
#define one_Wire A1 //Se configura el pin 9 como entrada
OneWire oneWire(one_Wire);//Creamos un objeto OneWire para comunicarnos con el sensor.
//Pasamos nuestra resferencia oneWire a la instancia de DallasTemperature
DallasTemperature sensorT(&oneWire);//Se crea un objeto DallasTemperature que leera el OneWire

void setup() 
{
  pinMode(pinSensor,INPUT);
  pinMode(redP,OUTPUT);
  pinMode(greenP,OUTPUT);    
  pinMode(pirPin, INPUT);    
  Serial.begin(9600);
  sensorT.begin();//Inicializamos la librería
}
void loop() 
{
  int value = analogRead(pinLuz);

  int xR = analogRead(xpin); // Leemos el valor de la tensión en el pin x
  int yR = analogRead(ypin); // Leemos el valor de la tensión en el pin y
  int zR = analogRead(zpin); // Leemos el valor de la tensión en el pin z

  // Mapea los valores leidos a un rango -90 a 90 grados (-pi a pi)
  int x_ang = map(xR, minVal, maxVal, -90, 90);
  int y_ang = map(yR, minVal, maxVal, -90, 90);
  int z_ang = map(zR, minVal, maxVal, -180, 180);

  Serial.print("X: ");
  Serial.print(x_ang);
  Serial.print(" Y: ");
  Serial.print(y_ang);
  Serial.print(" Z: ");
  Serial.println(z_ang);

  delay(100);

  if(value < 512 or (z_ang < 0 and z_ang > -180)){
    digitalWrite(greenP,HIGH);
    digitalWrite(redP,LOW);
    Serial.println("Sistema Activado");
    vibra();
    temp();
  }else if(z_ang < -180){
    Serial.println("PUERTA COLAPSÓ, ALERTANDO AUTORIDADES");
  }
  else{
    digitalWrite(redP,HIGH);
    digitalWrite(greenP,LOW);
    Serial.println("Sistema desactivado");
  }

  
  
  delay(1000);
}

void vibra(){
  if(digitalRead(pinSensor))
  {
    Serial.println("Cuidado, están forzando la cerradura");
   }else{
    Serial.println("Todo bien");
   }
   pirStat = digitalRead(pirPin); 
   if (pirStat == HIGH) {            // if motion detected
  // turn LED ON
   Serial.println("Hay alguien cerca");
  } 
  else {
   Serial.println("No hay nadie");
  }
}

void temp(){
  //Este programa se realizó para leer datos seriales de un sensor 
  sensorT.requestTemperatures(); //Se pide al sensor la temperatura
  Serial.print("Temperatura: ");
  Serial.print(sensorT.getTempCByIndex(0));//Obtiene la temperatura del sensor
  Serial.println(" °C");
  if(sensorT.getTempCByIndex(0) > 40 and sensorT.getTempCByIndex(0) < 79){
    Serial.println("PRECAUCIÓN: INTENTO DE FUNDICIÓN, ALERTANDO AUTORIDADES");
  } else if(sensorT.getTempCByIndex(0) > 80){
    Serial.println("CERCA DE FUNDICIÓN: MANCHANDO DINERO");
  }else{
    Serial.println("Temperatura controlada");
  }
}
