#include <Arduino.h>
#include "drive.hpp"
#include "siren.hpp"

int senseL;
int senseR;

String val;
int camPos;

int driveL;
int driveR;

int clamp (int in, int max){
  if(in > max){
    in = max;
  }

  if(in < -max){
    in = -max;
  }
  return in;

}


void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);
  // put your setup code here, to run once:
  setupDrive();

  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(27, OUTPUT);

  pinMode(14, OUTPUT);
  pinMode(32, OUTPUT);

  xTaskCreatePinnedToCore( blinkLights, "blinkLights", 10000, NULL, 3, NULL, 1 );
}

void loop() {
  senseL = analogReadMilliVolts(25);
  senseR = analogReadMilliVolts(26);

  if(senseL + senseR < 500){
    digitalWrite(27, HIGH);
  } else {
    digitalWrite(27, LOW);
  }

/*
  Serial.print(senseL);
  Serial.print(" ");
  Serial.print(senseR);
  Serial.println();
*/

  if (Serial2.available()){
    val = Serial2.readStringUntil('\n');
    camPos = val.toInt();
    //0 to 319
    driveL = 90+(camPos-160);
    driveR = 90-(camPos-160);

    driveL = clamp(driveL, 50);
    driveR = clamp(driveR, 50);

    setDrive(driveL,driveR);

    Serial.print("Drives: ");
    Serial.print(driveL);
    Serial.print(" ");
    Serial.println(driveR);
    if(senseL + senseR < 3000){
      setDrive(0,0);
      Serial.println("!!!!!!FIRE!!!!!!");
      vTaskDelay( 5000 / portTICK_PERIOD_MS );

    }
    Serial.print("Cam POS = ");
    Serial.println(camPos);
  }
    vTaskDelay( 100 / portTICK_PERIOD_MS );

}