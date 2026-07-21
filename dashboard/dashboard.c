#include <stdio.h>
#include "dashboard.h"

void dashboard_display(const VehicleData *vehicle,
                       const ECUStatus *status)
{
    printf("=============================================\n");
    printf("      AUTOMOTIVE ECU DASHBOARD\n");
    printf("=============================================\n\n");

    printf("Speed        : %d km/h\n", vehicle->speed_kmph);
    printf("RPM          : %d\n", vehicle->engine_rpm);
    printf("Gear         : %d\n", vehicle->gear);

    printf("Fuel         : %.1f %%\n", vehicle->fuel_level);
    printf("Battery      : %.1f V\n", vehicle->battery_voltage);
    printf("Coolant Temp : %.1f C\n", vehicle->coolant_temperature);

    printf("Engine       : %s\n",
           vehicle->engine_running ? "ON" : "OFF");

    printf("Door         : %s\n",
           vehicle->door_open ? "OPEN" : "CLOSED");

    printf("ABS          : %s\n",
           vehicle->abs_active ? "ACTIVE" : "INACTIVE");

    printf("Airbag       : %s\n",
           vehicle->airbag_ok ? "READY" : "FAULT");

    printf("\n----------- ECU STATUS -----------\n");

    printf("Cooling Fan  : %s\n",
           status->cooling_fan_on ? "ON" : "OFF");

    printf("Overheat     : %s\n",
           status->engine_overheat_warning ? "YES" : "NO");

    printf("Low Fuel     : %s\n",
           status->low_fuel_warning ? "YES" : "NO");

    printf("Battery Warn : %s\n",
           status->battery_warning ? "YES" : "NO");

    printf("Door Warning : %s\n",
           status->door_open_warning ? "YES" : "NO");

    printf("\n=============================================\n");
}