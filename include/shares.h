/** @file shares.h
 *  This file contains the definition of the external data queue that shares angle info between tasks
 * 
 *  @author Shashwat Sparsh
 * 
*/

#include "taskqueue.h"
#include "taskshare.h"


// Queue that cointains the angles being sent to the system to check against
extern Queue<float> angle_queue;
