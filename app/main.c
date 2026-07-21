#include <stdio.h>

#include "../include/vehicle_data.h"
#include "../include/ecu_status.h"

#include "../sensors/sensors.h"
#include "../ecu/ecu.h"
#include "../dashboard/dashboard.h"

int main(void)
{
    VehicleData vehicle;
    ECUStatus status = {0};      // Initialize all warnings to false

    updateVehicleData(&vehicle);

    processECU(&vehicle, &status);

    dashboard_display(&vehicle, &status);

    return 0;
}