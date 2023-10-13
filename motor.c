#include <ESP8266WiFi.h>

int ENA_PIN = D3;

int IN1_PIN = D1;

int IN2_PIN = D2;

void setup() {

  // set all the motor control pins to outputs

  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
}

// this function will run the motors in both directions at a fixed speed

void loop() {
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
  analogWrite(ENA_PIN, 50);
  delay(10000);

  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  delay(2000);

  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  analogWrite(ENA_PIN, 50);
  delay(10000);
}

//test-------------------------------------------------

//sets blinds control to manual
if (ctrl_Blinds_manual = true)
{
  if (ctrl_Blinds_onOff = true && manual_blinds = false)
  {
    digitalWrite(IN1_PIN_BLINDS, HIGH);
    digitalWrite(IN2_PIN_BLINDS, LOW);
    analogWrite(ENA_PIN_BLINDS, 50);
    delay(10000);

    digitalWrite(IN1_PIN_BLINDS, LOW);
    digitalWrite(IN2_PIN_BLINDS, LOW);
    manual_blinds = true;
  }

  else 
  {
    digitalWrite(IN1_PIN_BLINDS, LOW);
    digitalWrite(IN2_PIN_BLINDS, HIGH);
    analogWrite(ENA_PIN_BLINDS, 50);
    delay(10000);

    digitalWrite(IN1_PIN_BLINDS, LOW);
    digitalWrite(IN2_PIN_BLINDS, LOW);
    manual_blinds = false;
  }
}

//sets blinds control to automatic
else
{
  if (myData.store_Humid >= param_Humid_Max && myData.store_Temp >= param_Temp_Max && manual_blinds = false)
  {
    digitalWrite(IN1_PIN_BLINDS, HIGH);
    digitalWrite(IN2_PIN_BLINDS, LOW);
    analogWrite(ENA_PIN_BLINDS, 50);
    delay(10000);

    digitalWrite(IN1_PIN_BLINDS, LOW);
    digitalWrite(IN2_PIN_BLINDS, LOW);
    manual_blinds = true;
  }

  else if (myData.store_Humid <= param_Humid_Min && myData.store_Temp <= param_Temp_Min && manual_blinds = true)
  {
    digitalWrite(IN1_PIN_BLINDS, HIGH);
    digitalWrite(IN2_PIN_BLINDS, LOW);
    analogWrite(ENA_PIN_BLINDS, 50);
    delay(10000);

    digitalWrite(IN1_PIN_BLINDS, LOW);
    digitalWrite(IN2_PIN_BLINDS, LOW);
    manual_blinds = true;
  }
}

//waterpump
if (ctrl_WaterPump_manual = true)
{
  if (ctrl_WaterPump_onOff = true)
  {
    digitalWrite(RELAY_PIN, HIGH); // turn on pump 15 seconds
    delay(15000);
    digitalWrite(RELAY_PIN, LOW);
}

else
{
  if (myData.store_Moist <= param_Moist_Max)
  {
    digitalWrite(RELAY_PIN, HIGH); // turn on pump 15 seconds
    delay(15000);
    digitalWrite(RELAY_PIN, LOW);
  }
}

//sets windows control to manual
if (ctrl_Windows_manual = true)
{
  if (ctrl_Windows_onOff = true && manual_windows = false)
  {
    digitalWrite(IN1_PIN_WINDOW, HIGH);
    digitalWrite(IN2_PIN_WINDOW, LOW);
    analogWrite(ENA_PIN_WINDOW, 50);
    delay(10000);

    digitalWrite(IN1_PIN_WINDOW, LOW);
    digitalWrite(IN2_PIN_WINDOW, LOW);
    manual_blinds = true;
  }

  else 
  {
    digitalWrite(IN1_PIN_WINDOW, LOW);
    digitalWrite(IN2_PIN_WINDOW, HIGH);
    analogWrite(ENA_PIN_WINDOW, 50);
    delay(10000);

    digitalWrite(IN1_PIN_WINDOW, LOW);
    digitalWrite(IN2_PIN_WINDOW, LOW);
    manual_blinds = false;
  }
}

//sets window control to automatic
else
{
  if (myData.store_Wind >= param_Wind_Max && manual_windows = false)
  {
    digitalWrite(IN1_PIN_WINDOW, HIGH);
    digitalWrite(IN2_PIN_WINDOW, LOW);
    analogWrite(ENA_PIN_WINDOW, 50);
    delay(10000);

    digitalWrite(IN1_PIN_WINDOW, LOW);
    digitalWrite(IN2_PIN_WINDOW, LOW);
    manual_blinds = true;
  }

  else if (myData.store_Wind <= param_Wind_Min && manual_windows = true)
  {
    digitalWrite(IN1_PIN_WINDOW, HIGH);
    digitalWrite(IN2_PIN_WINDOW, LOW);
    analogWrite(ENA_PIN_WINDOW, 50);
    delay(10000);

    digitalWrite(IN1_PIN_WINDOW, LOW);
    digitalWrite(IN2_PIN_WINDOW, LOW);
    manual_blinds = true;
  }
}
