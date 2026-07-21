#include "sensors.h"
void updateVehicleData(VehicleData *vehicle)
{
    vehicle->speed_kmph = 0;
    vehicle->engine_rpm = 0;

    vehicle->coolant_temperature = 25.0;
    vehicle->fuel_level = 75.0;
    vehicle->battery_voltage = 12.6;

    vehicle->gear = 0;

    vehicle->engine_running = false;
    vehicle->door_open = false;
    vehicle->abs_active = false;
    vehicle->airbag_ok = true;
}