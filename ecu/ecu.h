#ifndef ECU_H
#define ECU_H

#include "../include/vehicle_data.h"
#include "../include/ecu_status.h"

void processECU(const VehicleData *vehicle, ECUStatus *status);

#endif