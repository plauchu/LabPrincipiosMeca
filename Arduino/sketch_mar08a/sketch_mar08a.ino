////ACT 1
//
////Se definen puertos
//#define X A0
//#define Y A1
//#define BTN 13
//
//
////declaramos variables
//float xPos, yPos;
//bool button;
//
//void setup() {
//  // put your setup code here, to run once:
//  //communications at 9600 bps:
//  Serial.begin(9600);
//
//  // Initialize pin modes:
//  pinMode(BTN, INPUT_PULLUP);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  // Se leen los valores
//  xPos = analogRead(X);
//  yPos = analogRead(Y);
//  button = digitalRead(BTN);
//
//  // Imprime (x, y) values:
//  Serial.print("Valores (x, y) registrados por el joystick: ");
//  //Serial.print("(");
//  Serial.println(xPos);
//  //Serial.print(", ");
//  Serial.println(yPos);
//  //Serial.println(" ");
//  //Serial.println(button);
//  //Serial.println(")");
//  delay(100);
//}

//ACT 1.2

//Se definen puertos
//#define X A0
//#define Y A1
//#define BTN 13


//declaramos variables
//float xPos, yPos;
//bool button;
//
//void setup() {
//  // put your setup code here, to run once:
//  //communications at 9600 bps:
//  Serial.begin(9600);
//
//  // Initialize pin modes:
//  pinMode(BTN, INPUT_PULLUP);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  // Se leen los valores
//  xPos = analogRead(X);
//  yPos = analogRead(Y);
//  button = digitalRead(BTN);
//
//  // Imprime (x, y) values:
//  Serial.print("Valores (x, y) registrados por el joystick entre -1, 1: ");
//  //Serial.print("(");
//  Serial.println((xPos-512)/512);
//  //Serial.print(", ");
//  Serial.println((512-yPos)/512);
//  //Serial.println(" ");
//  Serial.println(button);
//  //Serial.println(")");
//  delay(100);
//}

//ACT 3
//
//#define X A3
//#define LED 13
//float x;
//
//void setup () {
//  Serial.begin(9600);
////  Initialize pin modes:
//  pinMode(LED, OUTPUT);
//}
//
//void loop () {
//  x = analogRead(X);
//  Serial.println(x);
//  if (x < 90) {
//    digitalWrite(LED, HIGH);
//  } else {
//    digitalWrite(LED, LOW);
//  }
//  
//}

//ACT TEMP Y HUMEDAD

#include <LiquidCrystal.h>  // inluimos la lib

// Declaracion de variables globales
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // initialize the interface pins
int pinLM35 = A0; // Variable del pin de entrada del sensor (A0)
float tempC; // Variable para almacenar el valor obtenido del sensor (0 a 1023)
float millivolts;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);     // set up the LCD’s number of columns and rows
  
  // Configuramos el puerto serial a 9600 bps
  Serial.begin(9600);

  // Initialize pin modes:
  pinMode(pinLM35, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Con analogRead leemos el sensor, recuerda que es un valor de 0 a 1023
  tempC = analogRead(pinLM35); 

  // Calculamos la temperatura con la fórmula
  millivolts = (tempC / 1023.0) * 500;
  tempC = millivolts / 10;

  Serial.print("Temperatura en °C: ");
  Serial.println(tempC); // Envia el dato al puerto serial
  //Serial.print("Temperatura en °F: ");
  //Serial.println((tempC*1.8) + 32);

  // Mostrar en el LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperatura C,F:"); // Print a message to the LCD.
  lcd.setCursor(0, 1);
  lcd.print(tempC); // Print a message to the LCD.
  lcd.setCursor(7, 1);
  lcd.print((tempC*1.8) + 32); // Print a message to the LCD.
  
  // Esperamos un tiempo para repetir el loop
  delay(1000);
}
