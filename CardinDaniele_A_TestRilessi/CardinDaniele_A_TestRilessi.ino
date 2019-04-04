#include <LiquidCrystal.h>
  int tempoLed = random(1, 7) * 1000;
  int tempoBuzzer = random(1, 7) * 1000;
  int tempoInizioLed;
  int tempoClickLed;
  int tempoInizioBuzzer;
  int tempoFineBuzzer;
  int tempoPled = 0;
  int tempoPbuzzer = 0;
  int pinBottone = 5;
  int pinLed = 7;
  int pinBuzzer = 6;
  LiquidCrystal lcd(0,1,8,9,10,11);
  //variables and lcd initialization 
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(pinBottone, INPUT);
  digitalWrite(pinBottone, HIGH);
  //pullUp
  pinMode(pinLed, OUTPUT);
  pinMode(pinBuzzer,OUTPUT);
  //buzzer and led pins
}

void inizioBottone(int bottone)
{
  lcd.setCursor(0,0);
  lcd.print("Press the button"),
  lcd.setCursor(0,1);
  lcd.print("to start");
  while (digitalRead(bottone) == HIGH){
  }
  lcd.clear();
}
//press the button to start

void ledReaction(int tLed, int pLed, int pBottone)
{
  lcd.setCursor(0,0);
  lcd.print("Be ready for the");
  lcd.setCursor(0,1);
  lcd.print("led");
  delay(tLed);
  tempoPled = millis();
  digitalWrite(pLed,HIGH);
  while (digitalRead(pBottone) == HIGH){  
  }
  lcd.clear();
  tempoPled = millis() - tempoPled;
  digitalWrite(pLed,LOW);
}
//reaction to the led

void buzzerReaction(int tBuzzer, int pBuzzer, int pBottone)
{
  lcd.setCursor(0,0);
  lcd.print("Be ready for the");
  lcd.setCursor(0,1);
  lcd.print("buzzer");
  delay(tBuzzer);
  tempoPbuzzer = millis();
  tone(pBuzzer, 1000);
  while (digitalRead(pBottone) == HIGH){  
  }
  lcd.clear();
  tempoPbuzzer = millis() - tempoPbuzzer;
  tone(pBuzzer, 1000, 1);
}
//reaction to the buzzer

void lcdWrite(int tPled, int tPbuzzer)
{
    lcd.setCursor(0,0);
  lcd.print(tPled);
  lcd.setCursor(0,1);
  lcd.print(tPbuzzer);
  if (tPled < 250)
  {
    lcd.setCursor(7,0);
    lcd.print("good");  
  }
  else
  {
    lcd.setCursor(7,0);
    lcd.print("bad");
  }
  if (tPbuzzer < 250)
  {
    lcd.setCursor(7,1);
    lcd.print("good");  
  }
  else
  {
    lcd.setCursor(7,1);
    lcd.print("bad");
  }
  delay(5000);
  lcd.clear();
}
void loop() {
  // put your main code here, to run repeatedly
  
  inizioBottone(pinBottone);
  //random times
  ledReaction(tempoLed, pinLed, pinBottone);
  buzzerReaction(tempoBuzzer, pinBuzzer, pinBottone);
  lcdWrite(tempoPled, tempoPbuzzer);
}
