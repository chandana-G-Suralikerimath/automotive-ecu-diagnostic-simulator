#ifndef VEHICLE_DATA_H
#define VEHICLE_DATA_H

#include <stdbool.h>

typedef struct
{
    int speed_kmph;
    int engine_rpm;

    float coolant_temperature;
    float fuel_level;
    float battery_voltage;

    int gear;

    bool engine_running;
    bool door_open;
    bool abs_active;
    bool airbag_ok;

} VehicleData;

#endif