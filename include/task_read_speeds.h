/** @file task_read_speeds.h
 * This file contains code for two tasks which will be used to collect Hall effect sensor readings of
 * wind speed and rotor speed
 * 
 * @author Jacob Brooks
 * @date 2023-Nov-30 Original File
 */

#include "PrintStream.h"
#include "taskqueue.h"

// A queue which will be used to store Hall effect wind speed readings
extern Queue<float> wind_readings;

// A queue which will be used to store Hall effect rotor speed readings
extern Queue<float> rotor_readings;

// Two task function calls used in the task_read_speed.cpp file
void task_read_wind_speed (void* p_params);
void task_read_rotor_speed (void* p_params);