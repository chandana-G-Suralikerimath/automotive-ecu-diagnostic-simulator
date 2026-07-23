#ifndef ECU_STATUS_H
#define ECU_STATUS_H

#include <stdbool.h>

/*---------------------------------------------------------
 * ECU Output Status
 *
 * These flags represent decisions made by the ECU after
 * processing the vehicle sensor data.
 *--------------------------------------------------------*/
typedef struct
{
    bool cooling_fan_on;            // Cooling fan control

    bool engine_overheat_warning;   // Engine temperature too high

    bool low_fuel_warning;          // Fuel below safe level

    bool battery_warning;           // Battery voltage too low

    bool door_open_warning;         // Door open while vehicle is moving

} ECUStatus;

#endif