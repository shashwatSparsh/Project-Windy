/** @file task_read_speeds.cpp
 * This file contains code for two tasks which will be used to collect Hall effect sensor readings of
 * wind speed and rotor speed
 * 
 * @author Jacob Brooks
 * @date 2023-Nov-30 Original File
 */

#include <Arduino.h>
#include <task_read_speeds.h>

// Declare GPIO Pins for two Hall effect sensors
const uint8_t wind_pin = 35;
const uint8_t rotor_pin = 13;

// Create two queue arrays which can hold 100 speed data readings from both hall effect sensors
Queue<float> wind_readings (100, "Wind Data");
Queue<float> rotor_readings (100, "Rotor Data");

/** @brief Task which reads wind speed and adds it to the wind_readings queue.
 * @param p_params An unused pointer to nonexistent parameters
 */ 

void task_read_wind_speed (void* p_params)
{
    pinMode(wind_pin, INPUT_PULLUP);
    uint8_t current_value = 1;
    uint8_t previous_value = 1;
    uint8_t repeat_counter = 0;
    uint8_t starting_time = millis();
    uint8_t rotations = 0;

    for(;;)
    { 
        current_value = digitalRead(wind_pin);
        Serial << current_value << endl;
        if (current_value == previous_value)
        {
            repeat_counter++;
        }
        else if ((current_value != previous_value) && repeat_counter > 8)
        {
            rotations++;
            repeat_counter = 0;
        }
        else
        {
            repeat_counter = 0;
        }
        previous_value = current_value;
        if(millis() - starting_time >= 60000) // after 1 minute has passed
        {
            wind_readings.put(rotations);
            Serial << "1 minute has passed with rotations: " << rotations << endl;
            starting_time = millis();
            rotations = 0;
        }
        vTaskDelay(50);
    }
}

/** @brief Task which reads rotor speed and adds it to the rotor_readings queue.
 * @param p_params An unused pointer to nonexistent parameters
 */ 

void task_read_rotor_speed (void* p_params)
{
    pinMode(rotor_pin, INPUT_PULLUP);
    uint8_t current_value = 1;
    uint8_t previous_value = 1;
    uint8_t repeat_counter = 0;
    uint8_t starting_time_2 = millis();
    uint8_t rotations = 0;

    for(;;)
    { 
        current_value = digitalRead(rotor_pin);
        if (current_value == previous_value)
        {
            repeat_counter++;
        }
        else if ((current_value != previous_value) && repeat_counter > 8)
        {
            rotations++;
            repeat_counter = 0;
        }
        else
        {
            repeat_counter = 0;
        }
        previous_value = current_value;
        if(millis() - starting_time_2 >= 60000) // after 1 minute has passed
        {
            rotor_readings.put(rotations);
            starting_time_2 = millis();
        }
        vTaskDelay(50);
    }
}