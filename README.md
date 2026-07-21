# Automotive ECU Dashboard & Diagnostic Simulator

A modular Embedded C project that simulates the core functionality of an Automotive Electronic Control Unit (ECU). The project is designed to demonstrate embedded software architecture by separating sensor acquisition, ECU decision-making, and dashboard display into independent modules.

---

## Project Overview

This simulator mimics how an automotive ECU processes vehicle sensor data, evaluates system conditions, and updates the dashboard with vehicle status and warnings.

The project is implemented entirely in **Embedded C** using a modular software architecture similar to real automotive firmware.

---

## Features (Current)

- Modular project architecture
- Simulated vehicle sensor data
- ECU decision-making module
- Dashboard display
- Vehicle status structure
- ECU status structure
- Clean separation between modules

---

## Project Structure

```
Automotive_ECU/
│
├── app/
│   └── main.c
│
├── include/
│   ├── vehicle_data.h
│   └── ecu_status.h
│
├── sensors/
│   ├── sensors.c
│   └── sensors.h
│
├── ecu/
│   ├── ecu.c
│   └── ecu.h
│
├── dashboard/
│   ├── dashboard.c
│   └── dashboard.h
│
├── logger/
│
├── README.md
│
└── CMakeLists.txt
```

---

## Module Description

### Sensor Module

Generates simulated vehicle sensor values.

Current sensor parameters:

- Vehicle Speed
- Engine RPM
- Coolant Temperature
- Fuel Level
- Battery Voltage
- Gear Position
- Engine Status
- Door Status
- ABS Status
- Airbag Status

---

### ECU Module

Processes sensor data and determines vehicle status.

Current ECU decisions:

- Cooling Fan Status
- Engine Overheat Warning
- Low Fuel Warning
- Battery Warning
- Door Open Warning

---

### Dashboard Module

Displays vehicle information and ECU status in a console dashboard.

Example output:

```
=============================================
      AUTOMOTIVE ECU DASHBOARD
=============================================

Speed        : 0 km/h
RPM          : 0
Gear         : 0
Fuel         : 75.0 %
Battery      : 12.6 V
Coolant Temp : 25.0 C

Engine       : OFF
Door         : CLOSED
ABS          : INACTIVE
Airbag       : READY

----------- ECU STATUS -----------

Cooling Fan  : OFF
Overheat     : NO
Low Fuel     : NO
Battery Warn : NO
Door Warning : NO

=============================================
```

---

## Technologies Used

- C
- GCC
- Git
- CMake

---

## Software Architecture

```
               +------------------+
               |  Sensor Module   |
               +------------------+
                        |
                        |
                VehicleData
                        |
                        v
               +------------------+
               |    ECU Module    |
               +------------------+
                        |
                        |
                 ECUStatus
                        |
                        v
              +-------------------+
              | Dashboard Module  |
              +-------------------+
```

---

## Current Workflow

```
main()

↓

updateVehicleData()

↓

processECU()

↓

dashboard_display()
```

---

## Future Enhancements

- Dynamic sensor simulation
- Real-time dashboard updates
- Event Logger
- CAN Bus message simulation
- Diagnostic Trouble Codes (DTC)
- Fault Injection
- Engine Start/Stop Simulation
- Gear Shift Logic
- Fuel Consumption Simulation
- Unit Testing

---

## Author

**Chandana G Suralikerimath**
