#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 9
#define ECHO_PIN 10

#define RELAY_PIN 8
#define BUZZER_PIN 7

#define GREEN_LED 5
#define YELLOW_LED 6
#define RED_LED 4

#define PH_PIN A0

LiquidCrystal_I2C lcd(0x27, 16, 2);

const float TANK_HEIGHT = 20.0;

void setup()
{
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Water");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring");
  delay(2000);

  lcd.clear();
}

void loop()
{
  // ---------------- WATER LEVEL ----------------

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  float distance;

  // If no echo is received, assume tank is empty
  if (duration == 0)
  {
    distance = TANK_HEIGHT;
  }
  else
  {
    distance = duration * 0.0343 / 2;
  }

  // Keep distance within tank height
  if (distance > TANK_HEIGHT)
  {
    distance = TANK_HEIGHT;
  }

  if (distance < 0)
  {
    distance = 0;
  }

  // Calculate water percentage
  float waterLevel;

  waterLevel = ((TANK_HEIGHT - distance) / TANK_HEIGHT) * 100;

  waterLevel = constrain(waterLevel, 0, 100);

  Serial.print("Water Level: ");
  Serial.print(waterLevel);
  Serial.println("%");


  // ---------------- WATER CONTROL ----------------

  if (waterLevel < 20)
  {
    // LOW WATER

    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);

    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  }

  else if (waterLevel < 90)
  {
    // NORMAL WATER

    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);

    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  else
  {
    // FULL TANK

    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);

    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(BUZZER_PIN, HIGH);
  }


  // ---------------- LCD WATER DISPLAY ----------------

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Water: ");
  lcd.print((int)waterLevel);
  lcd.print("%");

  lcd.setCursor(0, 1);

  if (waterLevel < 20)
  {
    lcd.print("LOW Pump: ON");
  }
  else if (waterLevel < 90)
  {
    lcd.print("NORMAL Pump:OFF");
  }
  else
  {
    lcd.print("FULL Pump: OFF");
  }

  delay(2000);


  // ---------------- pH SENSOR ----------------

  int sensorValue = analogRead(PH_PIN);

  // Wokwi pH conversion
  float pH = (sensorValue / 1023.0) * 14.0;

  Serial.print("pH: ");
  Serial.println(pH);


  // ---------------- LCD pH DISPLAY ----------------

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("pH: ");
  lcd.print(pH, 2);

  lcd.setCursor(0, 1);

  if (pH >= 6.5 && pH <= 8.5)
  {
    lcd.print("Quality: GOOD");
  }
  else if ((pH >= 5.5 && pH < 6.5) ||
           (pH > 8.5 && pH <= 9.5))
  {
    lcd.print("Quality: WARN");
  }
  else
  {
    lcd.print("Quality: BAD");
  }

  delay(2000);
}
