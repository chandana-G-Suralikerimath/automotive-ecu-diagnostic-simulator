#include "ecu.h"

void processECU(const VehicleData *vehicle, ECUStatus *status)
{
    /* Reset all outputs */
    status->cooling_fan_on = false;
    status->engine_overheat_warning = false;
    status->low_fuel_warning = false;
    status->battery_warning = false;
    status->door_open_warning = false;

    /* Engine Overheat */
    if(vehicle->coolant_temperature > 100.0)
    {
        status->cooling_fan_on = true;
        status->engine_overheat_warning = true;
    }

    /* Low Fuel */
    if(vehicle->fuel_level < 20.0)
    {
        status->low_fuel_warning = true;
    }

    /* Low Battery */
    if(vehicle->battery_voltage < 11.8)
    {
        status->battery_warning = true;
    }

    /* Door Open While Moving */
    if(vehicle->door_open && vehicle->speed_kmph > 0)
    {
        status->door_open_warning = true;
    }
}