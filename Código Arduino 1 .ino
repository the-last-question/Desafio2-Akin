// Code Sensor 

#include <SoftwareSerial.h>
const int echoPin = 9;
const int trigPin = 10;
int vermelho = 7;
int amarelo = 6;
int verde = 5;

// Definindo variáveis
long duration;
double distance;

void setup() { // Configurando os pontos como entradas ou saídas
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode (verde, OUTPUT);
  pinMode (amarelo, OUTPUT);
  pinMode (vermelho, OUTPUT);
  Serial.begin(9600); // Dando Start na comunicação serial
}
void loop() {
  // Limpando memorial residual no TrigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Armazena a duração de um ciclo do sensor
  duration = pulseIn(echoPin, HIGH);
  // Cálculo da distâncias
  distance = duration * 0.0349999999/2;
  
  
  if (distance >= 0 and distance <= 110  ) { // Distância permitida para ligar o led Verde
    digitalWrite(verde, HIGH);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, LOW);}
  
  
   if (distance >=110 and distance <= 220) { // Distância de alerta ( só o led Amarelo ligado)
     digitalWrite(verde, LOW);
     digitalWrite(amarelo, HIGH);
     digitalWrite(vermelho, LOW);
   }
  
  if (distance >=221 and distance <= 330){ // Distância limite ( Somento o led Vermelho ligado)
     digitalWrite(verde, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, HIGH);
  }
  
  
  Serial.write("Distancia: ");      // Print da Distancia
  Serial.print(String(distance,2));  // Conversão da variavel distance em uma string
  Serial.print('\n');
 delay(950);
}

//Led 1 (Verde) => distancia = 110 cm
//Led 2 (Amarelo) => distancia = 220 cm
//Led 3 (Vermelho) => distancia = 330 cm
