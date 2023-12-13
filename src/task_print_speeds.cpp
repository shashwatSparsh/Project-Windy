/** @file task_print_speeds.cpp
 * This file contains code for two tasks which will be used to print Hall effect sensor readings of
 * wind speed and rotor speed
 * 
 * @author Jacob Brooks
 * @date 2023-Dec-12 Original File
 */

#include <task_read_speeds.h>
#include <task_print_speeds.h>

/** @brief Task which takes from wind and rotor speed queues and Serial prints their data values
 * @param p_params An unused pointer to nonexistent parameters
 */ 
void task_print_speeds (void* p_params)
{
    Serial << "Wind Speed (rpm) : Rotor Speed (rpm)" << endl;

    for(;;)
    {
        Serial << wind_readings.get() << " : " << rotor_readings.get() << endl;
        vTaskDelay(100);
    }
}
