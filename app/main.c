#include <stdio.h>

#include "../include/vehicle_data.h"
#include "../include/ecu_status.h"

#include "../sensors/sensors.h"
#include "../ecu/ecu.h"
#include "../dashboard/dashboard.h"
#include "../logger/logger.h"

int main(void)
{
    VehicleData vehicle;
    ECUStatus status = {0};

    /* Run simulator for 20 cycles */
    for (int i = 0; i < 20; i++)
    {
        updateVehicleData(&vehicle);

        processECU(&vehicle, &status);

        dashboard_display(&vehicle, &status);

        logVehicleData(&vehicle, &status);

        if (status.cooling_fan_on)
            logEvent("Cooling Fan ON");

        if (status.engine_overheat_warning)
            logEvent("Engine Overheat Warning");

        if (status.low_fuel_warning)
            logEvent("Low Fuel Warning");

        if (status.battery_warning)
            logEvent("Battery Warning");

        if (status.door_open_warning)
            logEvent("Door Open While Moving");

        printf("\n---------------------------------------------\n");
        printf("Simulation Cycle: %d\n", i + 1);
        printf("Press Enter to continue...");
        getchar();
    }

    printf("\n=========================================\n");
    printf(" Automotive ECU Simulation Completed\n");
    printf("=========================================\n");

    return 0;
}