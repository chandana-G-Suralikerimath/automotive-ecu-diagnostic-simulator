#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "../include/vehicle_data.h"
#include "../include/ecu_status.h"

void dashboard_display(const VehicleData *vehicle,
                       const ECUStatus *status);

#endif