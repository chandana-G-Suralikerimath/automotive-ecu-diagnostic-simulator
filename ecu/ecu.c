#include "ecu.h"

void processECU(const VehicleData *vehicle, ECUStatus *status)
{
    /*---------------------------------------------
     * Reset ECU Outputs
     *--------------------------------------------*/
    status->cooling_fan_on = false;
    status->engine_overheat_warning = false;
    status->low_fuel_warning = false;
    status->battery_warning = false;
    status->door_open_warning = false;

    /*---------------------------------------------
     * Cooling Fan Control
     *--------------------------------------------*/
    if (vehicle->coolant_temperature >= 90.0f)
    {
        status->cooling_fan_on = true;
    }

    /*---------------------------------------------
     * Engine Overheat Warning
     *--------------------------------------------*/
    if (vehicle->coolant_temperature >= 105.0f)
    {
        status->engine_overheat_warning = true;
    }

    /*---------------------------------------------
     * Low Fuel Warning
     *--------------------------------------------*/
    if (vehicle->fuel_level <= 15.0f)
    {
        status->low_fuel_warning = true;
    }

    /*---------------------------------------------
     * Battery Warning
     *--------------------------------------------*/
    if (vehicle->battery_voltage <= 11.8f)
    {
        status->battery_warning = true;
    }

    /*---------------------------------------------
     * Door Open Warning
     *--------------------------------------------*/
    if (vehicle->door_open && vehicle->speed_kmph > 0)
    {
        status->door_open_warning = true;
    }
}