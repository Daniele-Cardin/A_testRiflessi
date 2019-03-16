#include <LiquidCrystal.h>
  int tempoLed = random(1, 7) * 1000;
  int tempoBuzzer = random(1, 7) * 1000;
  int tempoInizioLed;
  int tempoClickLed;
  int tempoInizioBuzzer;
  int tempoFineBuzzer;
  int tempoPled = 0;
  int tempoPbuzzer = 0;
  LiquidCrystal lcd(0,1,8,9,10,11);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(5, INPUT);
  digitalWrite(5, HIGH);
  pinMode(7, OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int tempoLed = random(1000, 7000);
  int tempoBuzzer = random(1000, 7000);
  lcd.setCursor(0,0);
  lcd.print("Per avviare il");
  lcd.setCursor(0,0);
  lcd.print("test");
  while (digitalRead(5) == HIGH){
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Be ready for the");
  lcd.setCursor(0,1);
  lcd.print("led");
  delay(tempoLed);
  tempoPled = millis();
  digitalWrite(7,HIGH);
  while (digitalRead(5) == HIGH){  
  }
  lcd.clear();
  tempoPled = millis() - tempoPled;
  digitalWrite(7,LOW);
  lcd.setCursor(0,0);
  lcd.print("Be ready for the");
  lcd.setCursor(0,1);
  lcd.print("buzzer");
  delay(tempoBuzzer);
  tempoPbuzzer = millis();
  tone(6, 1000);
  while (digitalRead(5) == HIGH){  
  }
  lcd.clear();
  tempoPbuzzer = millis() - tempoPbuzzer;
  tone(6, 1000, 1);
  lcd.setCursor(0,0);
  lcd.print(tempoPled);
  lcd.setCursor(0,1);
  lcd.print(tempoPbuzzer);
  if (tempoPled < 250)
  {
    lcd.setCursor(7,0);
    lcd.print("good");  
  }
  else
  {
    lcd.setCursor(7,0);
    lcd.print("bad");
  }
  if (tempoPbuzzer < 250)
  {
    lcd.setCursor(7,1);
    lcd.print("good");  
  }
  else
  {
    lcd.setCursor(7,1);
    lcd.print("bad");
  }
  delay(10000);
  lcd.clear();
}
