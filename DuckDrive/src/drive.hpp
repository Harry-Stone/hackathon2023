#include <Arduino.h>
void setupDrive(){
    pinMode(22,OUTPUT);
    pinMode(23,OUTPUT);
    pinMode(18,OUTPUT);
    pinMode(19,OUTPUT);

    analogWrite(22,0);
    analogWrite(23,0);
    analogWrite(18,0);
    analogWrite(19,0);
}

void setDrive(int speedL, int speedR){
    if(speedL > 0){
        analogWrite(22,0);
        analogWrite(23,speedL);
    } else {
        analogWrite(22,speedL);
        analogWrite(23,0);
    }
        if(speedR > 0){
        analogWrite(18,0);
        analogWrite(19,speedR);
    } else {
        analogWrite(18,speedR);
        analogWrite(19,0);
    }
}