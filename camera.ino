//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//
// This sketch is a good place to start if you're just getting started with 
// Pixy and Arduino.  This program simply prints the detected object blocks 
// (including color codes) through the serial console.  It uses the Arduino's 
// ICSP port.  For more information go here:
//
// http://cmucam.org/projects/cmucam5/wiki/Hooking_up_Pixy_to_a_Microcontroller_(like_an_Arduino)
//
// It prints the detected blocks once per second because printing all of the 
// blocks for all 50 frames per second would overwhelm the Arduino's serial port.
//
   
#include <SPI.h>  
#include <Pixy.h>

// This is the main Pixy object 
Pixy pixy;

// recording the information of the fire
static int fire_status_x[20];
static int fire_status_y[20];
static int fire_status_height[20];
static int fire_status_width[20];
static int detect_second = 10;
static int current_x;
static int current_y;


void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...\n");

  pixy.init();
}

int average(int array[]){
  static int sum = 0;
  for (int i = 0; i < 20; i++){
    sum += array[i];
  }
  int average = sum/20;
  return average;
}

int getSd(int mean){
  static int sd_sum = 0;
  for (int i = 0; i < 20; i++){
    sd_sum += sq(sd_sum-mean);
  }
  int sd = sqrt(sd_sum/19);
  return sd;
}

void loop()
{ 
  static int i = 0;
  uint16_t blocks;
  char buf[32]; 
  
  // grab blocks!
  blocks = pixy.getBlocks();
  
  // If there are detect blocks, print them!
  if (blocks)
  {
    i++;
    
    // do this (print) every 50 frames because printing every
    // frame would bog down the Arduino
    if (i%15==0) // Slowing the speed of detecting, for 1. stablising system 
    {

        int current_x = pixy.blocks[0].x;
        Serial.println(pixy.blocks[0].x);
 //       Serial.write(current_x);
 /*
        for(int j = 0; j < 19; j++){
          fire_status_x[j] = fire_status_x[j+1];
          fire_status_y[j] = fire_status_y[j+1];
          fire_status_height[j] = fire_status_height[j+1];
          fire_status_width[j] = fire_status_width[j+1];
        }
        fire_status_x[19] = pixy.blocks[0].x;
        fire_status_y[19] = pixy.blocks[0].y;
        fire_status_height[19] = pixy.blocks[0].height;
        fire_status_width[19] = pixy.blocks[0].width;


       // If anything comes in Serial (USB),
      //Serial1.write(current_x);  // read it and send it out Serial1 (pins 0 & 1)

/*
        for(int k = 0; k < 19; k++){
          Serial.print(fire_status_x[k]);
          Serial.print(" ");
        }
        Serial.print("\nFire y position");
        for(int k = 0; k < 19; k++){
          Serial.print(fire_status_y[k]);
          Serial.print(" ");
        }
        Serial.print("\nFire height");
        for(int k = 0; k < 19; k++){
          Serial.print(fire_status_height[k]);
          Serial.print(" ");
        }
        Serial.print("\nFire width");
        for(int k = 0; k < 19; k++){
          Serial.print(fire_status_width[k]);
          Serial.print(" ");
        }
*/

    }
  }  
}

