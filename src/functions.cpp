/** @file Yaw Drive Functions
 *  This file contains functions during the prototyping/sensor testing stage.
 *  None of these are actually used in the demonstration code
*/

#include <Arduino.h>
#include <PrintStream.h>


/** @brief Motor Running Function that disables input 1 to the motor and runs input 2 at some pre-defined speed
 * @param time delay time should be > 10ms and < 1000ms
 * @param speed speed of rotation of the motor range: 0 < speed < 255 (ideally keep lower end)
 * @param motorPinIn1 GPIO Pin controlling the board
 * Note Regarding GPIO Pin: the Pin does not need to be DAC, ADC--signal being sent out is PWM
 * 
*/

/*
void runMotor(uint8_t time, int8_t speed, uint8_t motorPinIn1){
    //uint8_t speed = 100;
    digitalWrite(motorPinIn1, LOW);     // Turn Digital Output Off
    analogWrite(motorPinIn2, speed);    // Send "Analog" (PWM) Signal to Pin In1 with a speed
    delay(time);                        // add a delay 

}
*/

/** @brief Angle Reading Function that reads an analog value from the encoder ranging from 0-4096.
 *          The reading is then divided by a constant 11.78 to produce an angle ranging from -180 to +180 deg.
 *  @param rotarySensor the pin the magnetic encoder is connected to
 *  @param gain the gain the function is 
 * 
 *
*/

/*
float readAngle(uint8_t rotarySensor, float gain){

    float reading = analogRead(rotarySensor);   // Value Ranges from 0 - 4096 (2048 is the midpoint)
    // Convert to angle (degrees)
    // float ratio = 4096/360;
    float angle = (reading - 2048) / 11.78;
    // float angle = (gain * reading) / 360;
    
    return reading;
}
*/