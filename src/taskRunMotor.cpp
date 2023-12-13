/** @file taskRunMotor.cpp
 *  This file contains the runMotor task
 * 
 *  @author Shashwat Sparsh
 *  @date 4 December 2023
*/

#include "runMotor.h"
#include "shares.h"


/** @brief Task that runs Motor
 *  @details The task defines the motor input 1 and 2 pins as const 8bit ints based on the DRV8871 being used for motor control.
 *              The current angle is pulled from the queue and modified by a proportional gain to get a speed to turn the motor.
*               Based on the sign of the angle, either input 1 or 2 are sent a PWM signal with the speed to rotate with the other set to LOW.
                The DRV8871 uses two inputs 1 and 2 as a way of directly controlling the direction of rotation.
                Determining whether to use input 1 or 2 based on the sign (+-) of the angle was done experimentally.
 *  @param p_params An unused pointer for non-existent parameters
*/

void runMotor(void* p_params){
    // Set Motor Pin Input Pins
    const uint8_t motorPinIn1 = 32;
    const uint8_t motorPinIn2 = 33;

    // Ensure Both Input Pins start as LOW
    digitalWrite(motorPinIn1, LOW);     
    digitalWrite(motorPinIn2, LOW);     

    // Loop Indefinitely
    for (;;) {
        
        float currentAngle = angle_queue.get(); // Angle ranges from -180 to 180
        float k_gain = 20;                     // Adjustable proportional gain
        float speed = abs(currentAngle * k_gain);   // Set motor speed to some value based on distance from zero
                                                    // Use abs() to ensure the speed value is not negative as the current angle can be
        
        // If Angle is Negative use MotorPinIn1
        if (currentAngle < 0) {
            digitalWrite(motorPinIn2, LOW);     // Disable Input 2
            analogWrite(motorPinIn1, speed);    // Write to Input 1    
        }
        // If Angle is Positive use MotorPinIn2 for rever
        else {
            digitalWrite(motorPinIn1, LOW);     // Disable Input 1
            analogWrite(motorPinIn2, speed);    // Write to Input 2
        }
        vTaskDelay(10); // add a 10ms delay
    }

}