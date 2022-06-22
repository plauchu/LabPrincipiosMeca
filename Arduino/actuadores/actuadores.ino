//ACT1
#define MotA 10 //se definen pines
#define MotB 11

void setup() {
  // put your setup code here, to run once:
  pinMode(MotA, OUTPUT); // pin del led rojo1 como salida
  pinMode(MotB, OUTPUT); // pin del led rojo2 como salida
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Mandamos 0 y 0
  digitalWrite(MotA, LOW);
  digitalWrite(MotB, LOW);
  Serial.print("Freno pasivo: ");
  Serial.print(MotA);
  Serial.println(MotB);
  delay(1000);

  //Mandamos 0 y 1
  digitalWrite(MotA, LOW);
  digitalWrite(MotB, HIGH);
  Serial.print("dextrogiro: ");
  Serial.print(MotA);
  Serial.println(MotB);
  delay(1000);

  //Mandamos 1 y 0
  digitalWrite(MotA, HIGH);
  digitalWrite(MotB, LOW);
  Serial.print("Levogiro: ");
  Serial.print(MotA);
  Serial.println(MotB);
  delay(1000);

  //Mandamos 1 y 1
  digitalWrite(MotA, HIGH);
  digitalWrite(MotB, HIGH);
  Serial.print("Freno activo: ");
  Serial.print(MotA);
  Serial.println(MotB);
  delay(1000);
  
 }

//ACT2
#define MotA 10 //se definen pines
#define MotB 11
#define A0 A0

void setup() {
  // put your setup code here, to run once:
  pinMode(MotA, OUTPUT); // pin del led rojo1 como salida
  pinMode(MotB, OUTPUT); // pin del led rojo2 como salida
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float x = analogRead(A0)/204.6;
  Serial.print("Potenciometro: ");
  Serial.println(x);

  if(x >= 0 && x < 2){
    levogiro();
  } if (x >= 2 && x < 3){
     frenoP();
  } if (x >= 3 && x <= 5){
    dextrogiro();
  }
  
 }

 void levogiro(){
   //Mandamos 1 y 0
    digitalWrite(MotA, HIGH);
    digitalWrite(MotB, LOW);
    Serial.print("Levogiro: ");
    Serial.print(MotA);
    Serial.println(MotB);
    delay(1000);
 }

 void frenoP(){
  //Mandamos 0 y 0
    digitalWrite(MotA, LOW);
    digitalWrite(MotB, LOW);
    Serial.print("Freno pasivo: ");
    Serial.print(MotA);
    Serial.println(MotB);
    delay(1000);
 }

 void dextrogiro(){
   //Mandamos 0 y 1
    digitalWrite(MotA, LOW);
    digitalWrite(MotB, HIGH);
    Serial.print("dextrogiro: ");
    Serial.print(MotA);
    Serial.println(MotB);
    delay(1000);
 }

//Act4
#define MotA 10 //se definen pines
#define MotB 11
#define A0 A0

void setup() {
  // put your setup code here, to run once:
  pinMode(MotA, OUTPUT); // pin del led rojo1 como salida
  pinMode(MotB, OUTPUT); // pin del led rojo2 como salida
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float x = analogRead(A0)/204.6;
  Serial.print("Potenciometro: ");
  Serial.println(x);
  int y = map(x, 0, 5, 0, 255);

  if(x >= 0 && x <= 2){
    levogiro(y);
  } if (x > 2 && x < 3){
     frenoP();
  } if (x >= 3 && x <= 5){
    dextrogiro(y);
  }
  
 }

void levogiro(int y){
   //Mandamos 1 y 0
    analogWrite(MotA, 255 - y);
    digitalWrite(MotB, LOW);
    Serial.print("Levogiro: ");
    Serial.print(MotA);
    Serial.println(MotB);
 }

 void frenoP(){
  //Mandamos 0 y 0
    digitalWrite(MotA, LOW);
    digitalWrite(MotB, LOW);
    Serial.print("Freno pasivo: ");
    Serial.print(MotA);
    Serial.println(MotB);
 }

 void dextrogiro(int y){
   //Mandamos 0 y 1
    digitalWrite(MotA, LOW);
    analogWrite(MotB, y);
    Serial.print("dextrogiro: ");
    Serial.print(MotA);
    Serial.println(MotB);
 }
