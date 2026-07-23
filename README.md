# 🚗 Automotive ECU Diagnostic Simulator

A modular Automotive ECU (Electronic Control Unit) Diagnostic Simulator developed in **Embedded C**. The project simulates vehicle sensor data, processes it through an ECU module, displays the vehicle status on a dashboard, and logs important ECU events.

This project demonstrates fundamental embedded software concepts such as modular programming, state machines, sensor simulation, ECU decision making, and diagnostic logging.

---

## 📌 Features

- Simulates vehicle operating states:
  - Engine OFF
  - Engine IDLE
  - Vehicle ACCELERATING
  - Vehicle CRUISING

- Simulates real-time vehicle parameters:
  - Vehicle Speed
  - Engine RPM
  - Gear Position
  - Fuel Level
  - Coolant Temperature
  - Battery Voltage

- ECU Diagnostic Functions:
  - Cooling Fan Control
  - Engine Overheat Detection
  - Low Fuel Warning
  - Battery Voltage Warning
  - Door Open Warning

- Console Dashboard displaying:
  - Live Vehicle Data
  - ECU Status
  - Warning Indicators

- Diagnostic Logger for:
  - Vehicle Information
  - ECU Events

---

# 📂 Project Structure

```
automotive-ecu-diagnostic-simulator/
│
├── app/
│   └── main.c
│
├── dashboard/
│   ├── dashboard.c
│   └── dashboard.h
│
├── ecu/
│   ├── ecu.c
│   └── ecu.h
│
├── sensors/
│   ├── sensors.c
│   └── sensors.h
│
├── logger/
│   ├── logger.c
│   └── logger.h
│
├── include/
│   ├── vehicle_data.h
│   └── ecu_status.h
│
└── README.md
```

---

# ⚙️ Software Architecture

```
        Sensors Module
              │
              ▼
        VehicleData Structure
              │
              ▼
          ECU Module
              │
              ▼
        ECUStatus Structure
              │
      ┌───────┴────────┐
      ▼                ▼
 Dashboard Module   Logger Module
```

---

# 🧩 Module Description

## Sensors Module

Simulates various vehicle sensor values including:

- Speed
- Engine RPM
- Gear Position
- Fuel Level
- Coolant Temperature
- Battery Voltage

It uses a simple state machine to simulate different vehicle operating conditions.

---

## ECU Module

Processes the simulated sensor values and generates ECU outputs such as:

- Cooling Fan ON/OFF
- Engine Overheat Warning
- Low Fuel Warning
- Battery Warning
- Door Open Warning

---

## Dashboard Module

Displays:

- Vehicle Parameters
- Engine Status
- ECU Warning Indicators

using a formatted console dashboard.

---

## Logger Module

Logs:

- Vehicle Information
- ECU Diagnostic Events

to assist in debugging and diagnostics.

---

# 🚀 State Machine

```
ENGINE OFF
      │
      ▼
ENGINE IDLE
      │
      ▼
ACCELERATING
      │
      ▼
CRUISING
      │
      └───────────────┐
                      ▼
               ACCELERATING
```

---

# 🛠 Technologies Used

- Embedded C
- GCC (MinGW)
- Git
- GitHub
- Visual Studio Code

---

# ▶️ Build Instructions

Compile using GCC:

```bash
gcc app/main.c dashboard/dashboard.c sensors/sensors.c ecu/ecu.c logger/logger.c -Iinclude -o ecu_dashboard
```

Run:

```bash
./ecu_dashboard
```

or on Windows:

```bash
ecu_dashboard.exe
```

---

# 📷 Sample Output

```
=============================================
      AUTOMOTIVE ECU DASHBOARD
=============================================

Speed        : 80 km/h
RPM          : 2200
Gear         : 5

Fuel         : 72.8 %
Battery      : 13.8 V
Coolant Temp : 88.5 C

Engine       : ON
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

# 💡 Embedded Concepts Demonstrated

- Modular Programming
- Header File Organization
- Structures
- Pointers
- State Machine Design
- Sensor Simulation
- ECU Decision Logic
- Diagnostic Logging
- Console Dashboard
- Embedded Software Architecture

---

# 🔮 Future Improvements

- CAN Bus Message Simulation
- UART-Based Serial Console
- Fault Injection Module
- Sensor Noise Simulation
- EEPROM Configuration Storage
- FreeRTOS Task-Based Implementation
- File-Based Logging
- Unit Testing

---

# 👩‍💻 Author

**Chandana G Suralikerimath**

Embedded Systems Engineer

- **GitHub:** https://github.com/chandana-G-Suralikerimath
- **LinkedIn:** https://www.linkedin.com/in/chandana-g-suralikerimath
---

## ⭐ If you found this project useful, consider giving it a star!