
const int botao1 = 7; //PINO DIGITAL UTILIZADO PELO PUSH BUTTON
const int botao2 = 5; //PINO DIGITAL UTILIZADO PELO PUSH BUTTON
const int pinoLed = 13; //PINO DIGITAL UTILIZADO PELO LED
const int buzzer = 11;

void setup() {
pinMode(botao1, INPUT_PULLUP); //DEFINE O PINO COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
  //DO ARDUINO PARA GARANTIR QUE NÃO EXISTA FLUTUAÇÃO ENTRE 0 (LOW) E 1 (HIGH)
pinMode(botao2, INPUT_PULLUP);
pinMode(pinoLed, OUTPUT); //DEFINE O PINO COMO SAÍDA
digitalWrite(pinoLed, LOW); //LED INICIA DESLIGADO
pinMode(buzzer, OUTPUT);

}
void loop(){
  if(digitalRead(botao1) == LOW && digitalRead(botao2) == LOW ){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
      digitalWrite(pinoLed, LOW); //APAGA O LED
      digitalWrite(buzzer, LOW);
  }else{ //SENÃO, FAZ
    digitalWrite(pinoLed, HIGH); //ACENDE O LED
    digitalWrite(buzzer, HIGH);
  }
}
