// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledVerm = 13;
const int botao1 = 7; 
const int botao2 = 5; 

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
Serial.begin(9600); // Starts the serial communication
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
if (safetyDistance <= 20 ){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledVerm, HIGH);
} else if (digitalRead(botao1) == LOW && digitalRead(botao2) == LOW){
  digitalWrite(buzzer, LOW);
  digitalWrite(ledVerm, LOW);  
}
else{
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledVerm, HIGH);
}
 
// Prints the distance on the Serial Monitor
Serial.print("Distância: ");
Serial.println(distancia);
}
