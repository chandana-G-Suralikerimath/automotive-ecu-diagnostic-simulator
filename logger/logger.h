#ifndef LOGGER_H
#define LOGGER_H

#include "../include/vehicle_data.h"
#include "../include/ecu_status.h"

/*---------------------------------------------------------
 * Logger Module
 *
 * Logs the current vehicle data and ECU status.
 *--------------------------------------------------------*/

/* Display current vehicle and ECU information */
void logVehicleData(const VehicleData *vehicle,
                    const ECUStatus *status);

/* Log important ECU events */
void logEvent(const char *event);

#endif