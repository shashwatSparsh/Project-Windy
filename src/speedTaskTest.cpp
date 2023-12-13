/** @file main.cpp
 * This file creates the read and print tasks for the wind and rotor speed Hall effect sensors
 * 
 * @author Jacob Brooks
 * @date 2023-Nov-30 Original File
 */

#include <Arduino.h>
#include <task_read_speeds.h>
#include <task_print_speeds.h>

/** @brief Setup function which starts the Serial connection and creates the read and print tasks
 * the wind and rotor speeds
 * 
 * @param p_params An unused pointer to nonexistent parameters
 */ 

void setup() 
{
   Serial.begin(115200);
   delay(5000); // Allow time between starting Serial and running tasks
   
   xTaskCreate(task_read_wind_speed,"Read Wind Speed",2048,NULL,5,NULL);
   //xTaskCreate(task_read_rotor_speed,"Read Rotor Speed",1024,NULL,5,NULL);
   xTaskCreate(task_print_speeds,"Print Speeds",1024,NULL,5,NULL);
}

void loop() {
  // Leave empty
}
