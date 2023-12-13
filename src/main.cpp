/** @file main.cpp
 *  
 *  This file contains the program demonstration of the two task functions ReadAngle and RunMotor.
 *  Read Angle reads the angle of wind with respect to the angle of the nacelle and queues the value.
 *  This queued value is shared with the RunMotor function which rotates the motor based on the angle.
 * 
 *  @author Shashwat Sparsh
 *  @date 4 December 2023
*/

#include <Arduino.h>    // Use the Arduino Framework
#include <PrintStream.h>  // Ensures that the ME 507 Support Lib. works as intended
#include "taskshare.h"  // Task Share Header
#include "taskqueue.h"  // Task Queue Header
#include "shares.h"     // Shares Header
#include "readAngle.h"  // readAngle Header
#include "runMotor.h"   // runMotor Header

Queue<float>angle_queue(100, "Angles"); // Angle Queue


/** @brief Setup function that sets up tasks
 *  @details  Initializes the Serial Monitor
 *            Creates the readAngle Task with prio 5
 *            Creates the runMotor Task with prio 4
*/
void setup() {
  // put your setup code here, to run once:
  //int result = myFunction(2, 3);
  Serial.begin(115200);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(39, INPUT);
  //Serial.print("DRV8871 Test");



  ///*
  xTaskCreate(readAngle,        // Task Function
              "Angle Reading",  // Name
              1024,             // Stack Size
              NULL,             // Pointer
              5,                // Priority
              NULL);            // Don't save task obj pointer

  xTaskCreate(runMotor,         // Task Function
              "Running Motor",  // Name
              1024,             // Stack Size
              NULL,             // Pointer
              4,                // Priority
              NULL);            // Don't save task obj pointer

  //vTaskStartScheduler();
  //*/
}

/** @brief Arduino loop function
 *  @details Unused Arduino Loop Function
 * 
*/
void loop() {
  
  //digitalWrite(32, LOW);
  //analogWrite(33, 200);
  //Serial.print("Turning");
  //delay(10);
  //float angle = (analogRead(27) - 2048) / 11.37778;
  //float angle = (1/360) * (analogRead(27) - 2048);
  //Serial.println(angle);
  //delay(1000);
  //Serial.print("HelloWorld");
}
