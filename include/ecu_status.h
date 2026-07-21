#ifndef ECU_STATUS_H
#define ECU_STATUS_H

#include <stdbool.h>

typedef struct
{
    bool cooling_fan_on;
    bool engine_overheat_warning;
    bool low_fuel_warning;
    bool battery_warning;
    bool door_open_warning;

} ECUStatus;

#endif