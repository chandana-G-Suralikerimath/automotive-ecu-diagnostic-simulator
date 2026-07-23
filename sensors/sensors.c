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
 * State Counter
 *--------------------------------------------------------*/
static int stateCounter = 0;

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
        /*---------------------------------------------*/
        case ENGINE_OFF:

            speed = 0;
            rpm = 0;
            gear = 0;

            engine_running = false;

            stateCounter++;

            if (stateCounter >= 3)
            {
                currentState = ENGINE_IDLE;
                stateCounter = 0;
            }

            break;

        /*---------------------------------------------*/
        case ENGINE_IDLE:

            speed = 0;
            rpm = 800;
            gear = 0;

            engine_running = true;

            coolant_temperature += 0.2f;

            stateCounter++;

            if (stateCounter >= 5)
            {
                currentState = ACCELERATING;
                stateCounter = 0;
            }

            break;

        /*---------------------------------------------*/
        case ACCELERATING:

            engine_running = true;

            speed += 20;

            if (speed <= 20)
            {
                gear = 1;
                rpm = 1800;
            }
            else if (speed <= 40)
            {
                gear = 2;
                rpm = 2200;
            }
            else if (speed <= 60)
            {
                gear = 3;
                rpm = 2500;
            }
            else if (speed <= 80)
            {
                gear = 4;
                rpm = 2800;
            }
            else
            {
                gear = 5;
                rpm = 3000;
            }

            fuel_level -= 0.5f;
            coolant_temperature += 0.5f;
            battery_voltage = 13.8f;

            if (speed >= 80)
            {
                currentState = CRUISING;
            }

            break;

        /*---------------------------------------------*/
        case CRUISING:

            engine_running = true;

            speed = 80;
            gear = 5;
            rpm = 2200;

            fuel_level -= 0.2f;

            if (coolant_temperature < 95.0f)
            {
                coolant_temperature += 0.2f;
            }

            stateCounter++;

            if (stateCounter >= 5)
            {
                currentState = ACCELERATING;
                stateCounter = 0;

                speed = 40;
            }

            break;
    }

    /*-------------------------------------------------
     * Safety Limits
     *------------------------------------------------*/
    if (fuel_level < 0.0f)
    {
        fuel_level = 0.0f;
    }

    if (battery_voltage < 11.8f)
    {
        battery_voltage = 11.8f;
    }

    /*-------------------------------------------------
     * Copy Simulation Data to Vehicle Structure
     *------------------------------------------------*/
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