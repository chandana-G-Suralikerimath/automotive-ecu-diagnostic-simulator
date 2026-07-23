#ifndef ECU_H
#define ECU_H

#include "../include/vehicle_data.h"
#include "../include/ecu_status.h"

/*---------------------------------------------------------
 * ECU Processing Function
 *
 * Reads the current vehicle sensor values and updates
 * ECU outputs such as:
 *  - Cooling Fan
 *  - Overheat Warning
 *  - Low Fuel Warning
 *  - Battery Warning
 *  - Door Open Warning
 *--------------------------------------------------------*/
void processECU(const VehicleData *vehicle, ECUStatus *status);

#endif