//Code Display

#include <LiquidCrystal.h>
#include <string.h>
#include <SoftwareSerial.h>

//Criando um objeto da classe LiquidCrystal e 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //inicializando os pinos da interface.
 String distancia;

void setup() {
   lcd.begin(16, 2); // Inicializando formato da tela do display
   lcd.print("System ON");
  delay(500);
  Serial.begin(9600);
  lcd.clear();
  // Inicializando comunicação serial
  
}
 
void loop() { 
	lcd.setCursor(0, 0);
  if(Serial.available() > 0){
    delay(500);
    lcd.clear();
   	 distancia = Serial.readStringUntil('\n');  // Comunicação entre os dois arduinios
  }
  
  Serial.println(distancia);  // Print da Distancia capitada no Arduino 1, demonstrada no display conectado ao arduino 2
  lcd.print(distancia);
    delay(500);
 
}
