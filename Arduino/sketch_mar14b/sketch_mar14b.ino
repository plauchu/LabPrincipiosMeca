int xpin = A0;                  
int ypin = A1;                  
int zpin = A2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Configuramos el puerto serial a 9600 bps
  
  // Initialize pin modes:
}

void loop() {
  // put your main code here, to run repeatedly:

  int xR = analogRead(xpin); // Leemos el valor de la tensión en el pin x
  int yR = analogRead(ypin); // Leemos el valor de la tensión en el pin y
  int zR = analogRead(zpin); // Leemos el valor de la tensión en el pin z

  // Mapea los valores leidos a un rango -1 a 1 
  int x_ang = map(xR, 266, 402, -1000, 1000);
  int y_ang = map(yR, 268, 403, -1000, 1000);
  int z_ang = map(zR, 266, 401, -1000, 1000);

  Serial.print("X: ");
  Serial.print((float)x_ang);

  Serial.print(" Y: ");
  Serial.print((float)y_ang;)
  
  Serial.print(" Z: ");
  Serial.println((float)z_ang);

  delay(100);
}
