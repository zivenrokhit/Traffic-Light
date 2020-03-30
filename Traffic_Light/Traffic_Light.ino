/*
 * Ziven, Rokhit 
 * 27 March 2020
 * 
 */
#include <LiquidCrystal.h>
const int rs = 10, en = 9, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(10, 9, 5, 4, 3, 2);

int yellow = 7;
int red = 11;
int green = 8;
const int trigPin = 13;
const int echoPin = 12;
int brightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
  analogWrite(6, 100);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  
 


}

void loop() {
  long duration;
  int distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0343;
  Serial.print(distance);
  Serial.println("cm");
  delay(10);
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.print(distance);
  lcd.print("cm");
  analogWrite(green, brightness);
  

  if ((distance > 20))
  {
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);

  }
  else
  {
    digitalWrite(green, LOW);

    if (digitalRead(red) == HIGH) {
      digitalWrite(yellow, LOW);

    } else {
      digitalWrite(yellow, HIGH);

    }

    delay(1000);
    digitalWrite(red, HIGH);
  }

}
