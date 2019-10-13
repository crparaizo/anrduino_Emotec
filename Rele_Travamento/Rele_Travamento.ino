#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledVerm = 13;
const int botao1 = 7; 
const int botao2 = 5; 
const int rele = 2;

/* The following trigPin/echoPin cycle is used to determine the distance of the nearest
 object by bouncing soundwaves off it */
 
// defines variables
long duration;
int distancia;
int safetyDistance;
 
 
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledVerm, OUTPUT);
pinMode(botao1, INPUT_PULLUP);
pinMode(botao2, INPUT_PULLUP);
pinMode(rele, OUTPUT);
Serial.begin(9600); // Starts the serial communication



  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  /*
  lcd.setCursor(1,0);
  lcd.print("A distancia eh:");
  lcd.setCursor(1,1);
  lcd.print(distancia);

  */
}

 
 
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
 
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

 
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
 
// Calculating the distance
distancia= duration*0.034/2;

safetyDistance = distancia;

if (safetyDistance <= 30 ){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledVerm, HIGH);
  digitalWrite(rele, HIGH);
} else if (digitalRead(botao1) == LOW && digitalRead(botao2) == LOW){
  digitalWrite(buzzer, LOW);
  digitalWrite(ledVerm, LOW);
  digitalWrite(rele, LOW);  
}
else{
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledVerm, HIGH);
  digitalWrite(rele, HIGH);
}
 
// Prints the distance on the Serial Monitor
Serial.print("Distância: ");
Serial.println(distancia);

lcd.init();
lcd.setCursor(1,0);
lcd.print("Distancia: ");
lcd.setCursor(1,1);
lcd.println(distancia);
}
