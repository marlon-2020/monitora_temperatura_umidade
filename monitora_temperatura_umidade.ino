#include <LiquidCrystal.h>
#define ledAzul 10
#define ledVerde 9
#define ledVermelho 8
#define ledVerdeUmidade 1
#define ledVermelhoUmidade 0

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerdeUmidade, OUTPUT);
  pinMode(ledVermelhoUmidade, OUTPUT);
  lcd.begin(16, 2);
  //lcd.print("Temp C|Umidade %");
}

void loop() {
  int umidade = map(((analogRead(A1) - 20) * 3.04), 0, 1023, 0, 100);
  int tempC = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  if(tempC < 17){
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, LOW);
  }else if(tempC >= 17 && tempC <=23){
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
  }else{
  	digitalWrite(ledAzul, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
  }
  if(umidade <= 36 || umidade >= 58){
    digitalWrite(ledVerdeUmidade, LOW);
    digitalWrite(ledVermelhoUmidade, HIGH);
  }else{
    digitalWrite(ledVerdeUmidade, HIGH);
    digitalWrite(ledVermelhoUmidade, LOW);
  }
  lcd.print("Temp:");
  lcd.setCursor(6, 0);
  lcd.print(float(tempC), 1);
  lcd.setCursor(0, 1);
  lcd.print("Umidade:");
  lcd.setCursor(9, 1);
  lcd.print(float(umidade), 1);
  if(umidade >= 37 && umidade <= 57 && tempC >= 17 && tempC<=23){
  	lcd.setCursor(13, 1);
  	lcd.print("OK!");
  }else{
  	lcd.setCursor(13, 1);
  	lcd.print("   ");
  }
}
 