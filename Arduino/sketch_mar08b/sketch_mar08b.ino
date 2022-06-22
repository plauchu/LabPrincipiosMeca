//#include <DHT.h>
//#include <LiquidCrystal.h>  // inluimos la lib
//
//DHT dht(7, DHT11);
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // initialize the interface pins
//
//void setup() {
//  // put your setup code here, to run once:
//  lcd.begin(16, 2);
//  Serial.begin(9600);
//  dht.begin();
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  float hum = dht.readHumidity();
//  float tempC = dht.readTemperature();
//  float tempF = dht.readTemperature(true);
//
//  Serial.print("Humedad: ");
//  Serial.print(hum);
//  Serial.print(" Temp: ");
//  Serial.print(tempC);
//  Serial.print("ºC _ ");
//  Serial.print(tempF);
//  Serial.println("ºF");
//
//  //lcd
//  lcd.clear();
//  lcd.setCursor(0, 0);
//  lcd.print("Temp C: Hum:"); // Print a message to the LCD.
//  lcd.setCursor(0, 1);
//  lcd.print(tempC); // Print a message to the LCD.
//  lcd.setCursor(8, 1);
//  lcd.print(hum); // Print a message to the LCD.
//  
//  // Esperamos un tiempo para repetir el loop
//  delay(1000);
//}

//#include <LiquidCrystal.h> // include the library code

// Declaracion de variables globales
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // initialize the interface pins
//int t_muestreo = 500; // Tiempo de muestreo del acelerómetro
int xpin = A0;                  
int ypin = A1;                  
int zpin = A2;
int minVal = 0; // Valor mínimo del acelerometro en reposo
int maxVal = 1023; // Valor máximo del acelerometro en reposo


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Configuramos el puerto serial a 9600 bps
  //lcd.begin(16, 2); // set up the LCD’s number of columns and rows
  //analogReference(EXTERNAL); // La tensión aplicada en el pin AREF (3.3V) será la que haga que el conversor analogo-digital de su máxima lectura (1023) 
  
  // Initialize pin modes:
}

void loop() {
  // put your main code here, to run repeatedly:
  // Mostrar en el LCD
//  lcd.clear();
//  lcd.setCursor(2, 0);
//  lcd.print("X     Y    Z"); // Print a message to the LCD.

  int xR = analogRead(xpin); // Leemos el valor de la tensión en el pin x
  int yR = analogRead(ypin); // Leemos el valor de la tensión en el pin y
  int zR = analogRead(zpin); // Leemos el valor de la tensión en el pin z

  // Mapea los valores leidos a un rango -90 a 90 grados (-pi a pi)
  int x_ang = map(xR, minVal, maxVal, -90, 90);
  int y_ang = map(yR, minVal, maxVal, -90, 90);
  int z_ang = map(zR, minVal, maxVal, -180, 180);

  Serial.print("X: ");
  Serial.print(xR);
  Serial.print(" Y: ");
  Serial.print(yR);
  Serial.print(" Z: ");
  Serial.println(zR);

  delay(100);
}
