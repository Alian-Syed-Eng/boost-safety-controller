#include <LiquidCrystal.h>

//Pins Lcd
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//boost Pins
const int boostPin    = A0;
const int boostCutPin = 6;

//parameters for boost simulation
const float maxPSI   = 25.0;
const float tripPSI  = 20.0;
const float resetPSI = 18.0;

bool overboostActive = false;
bool lastOverboostState = false;

//Self test screen load up page
void startupSelfTest() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BOOST CONTROLLER");
  lcd.setCursor(0, 1);
  lcd.print("SELF TEST...");
  delay(2500);

  //Test boost cut output
  digitalWrite(boostCutPin, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BOOST CUT: ON");
  delay(2500);

  digitalWrite(boostCutPin, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BOOST CUT: OK");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM READY");
  delay(2500);

  lcd.clear();
}

void setup() {
  pinMode(boostCutPin, OUTPUT);
  digitalWrite(boostCutPin, LOW);

  lcd.begin(16, 2);

  startupSelfTest();
}

void loop() {

  //For Joystick output
  int adcValue = analogRead(boostPin);
  float voltage = adcValue * (5.0 / 1023.0);

  float psi = (voltage / 5.0) * maxPSI;
  if (psi < 0) psi = 0;
  if (psi > maxPSI) psi = maxPSI;

  //Hysterisis Logic
  if (!overboostActive && psi >= tripPSI) {
    overboostActive = true;
  }
  if (overboostActive && psi <= resetPSI) {
    overboostActive = false;
  }

  //Boost Cut 
  digitalWrite(boostCutPin, overboostActive ? HIGH : LOW);

  //Lcd
  lcd.setCursor(0, 0);
  lcd.print("Boost: ");
  lcd.print(psi, 1);
  lcd.print(" PSI   ");

  //Lcd again but second line
  if (overboostActive != lastOverboostState) {
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);

    if (overboostActive) {
      lcd.print("BOOST CUT ACTIVE");
    } else {
      lcd.print("STATUS: SAFE");
    }

    lastOverboostState = overboostActive;
  }

  delay(100);
}

