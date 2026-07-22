#include "sensors.h"

/*---------------------------------------------------------
 * Vehicle State Definition
 *--------------------------------------------------------*/
typedef enum
{
    ENGINE_OFF,
    ENGINE_IDLE,
    ACCELERATING,
    CRUISING

} VehicleState;

/*---------------------------------------------------------
 * Internal Simulation Variables
 *--------------------------------------------------------*/
static VehicleState currentState = ENGINE_OFF;

static int speed = 0;
static int rpm = 0;

static float coolant_temperature = 25.0f;
static float fuel_level = 75.0f;
static float battery_voltage = 12.6f;

static int gear = 0;

static bool engine_running = false;
static bool door_open = false;
static bool abs_active = false;
static bool airbag_ok = true;

/*---------------------------------------------------------
 * Update Vehicle Data
 *--------------------------------------------------------*/
void updateVehicleData(VehicleData *vehicle)
{
    switch (currentState)
    {
        case ENGINE_OFF:

            /* Vehicle is completely OFF */

            speed = 0;
            rpm = 0;
            gear = 0;

            engine_running = false;

            break;

        case ENGINE_IDLE:

            /* Engine ON but vehicle not moving */

            speed = 0;
            rpm = 800;
            gear = 0;

            engine_running = true;

            break;

        case ACCELERATING:

            /* We will implement this later */

            break;

        case CRUISING:

            /* We will implement this later */

            break;
    }

    /* Copy simulated values into VehicleData */

    vehicle->speed_kmph = speed;
    vehicle->engine_rpm = rpm;

    vehicle->coolant_temperature = coolant_temperature;
    vehicle->fuel_level = fuel_level;
    vehicle->battery_voltage = battery_voltage;

    vehicle->gear = gear;

    vehicle->engine_running = engine_running;
    vehicle->door_open = door_open;
    vehicle->abs_active = abs_active;
    vehicle->airbag_ok = airbag_ok;
}