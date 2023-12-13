/** @file taskReadAngle.cpp
 *  This file defines the angleRead task.
 * 
 *  @author Shashwat Sparsh
 * 
*/

#include <Arduino.h>
#include <PrintStream.h>
#include "readAngle.h"
#include "shares.h"


/** @brief Task that reads the angle from the rotary encoder.
 *  @details The rotaryPin is a predefined int.
 *              The state machine is unused as there was not enough time for implementation.
 *              Ideally state 0 would be the automatic rotation (i.e. control loop is active)
 *              State 1 would be a manual override where the motor is disabled/run at a constant speed until
 *              the angle value read is some number (e.g. -10 < angle < 10 deg)
 *              A value ranging from 0-4095 is read from the encoder and then adjusted to read an angle ranging: -180 < angle < +180 deg
 *              This value is then put into a queue which is then shared with the runMotor task.
 *              For the purposes of ensuring that the sensor is reading correctly as the ADC of the ESP32 is a little garbage, the value is printed to Serial.
 *              Ideally this value would be printed to a dynamic website that is hosted by the ESP32
 *  @param p_params An unused pointer for nonexistent parameters
*/

void readAngle(void* p_params){

    const uint rotaryPin = 39;
    uint8_t state = 0;  // State 0: Automatic Rotation
                        // State 1: Manual Override via PushButton Toggle
    pinMode(rotaryPin, INPUT);  // Pin 8 is the rotary encoder input
    //pinMode(5, INPUT);  // Pin 5 is the pushbutton input

    // Loop Indefinitely
    for (;;) {
        
        if(state == 0 ) {
            float reading = analogRead(rotaryPin);   // Value Ranges from 0 - 4095 (2048 is the midpoint)
            // Convert to angle (degrees)
            // 11.37778 is the conversion factor to convert 2048 to 180 degrees
            float angle = (reading - 2048) / 11.37778;  // Value is now ranging from roughly -180 to +180 deg.
            angle_queue.put(angle);
            Serial << angle; 
        }
        else if(state == 1 ) {  // Disregard me
            // Do nothing
        }

        vTaskDelay(10);    // Add 10ms delay

    }
    
}

