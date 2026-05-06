# Solar-Sun-Tracking-Project
IoT-based dual-axis solar tracking system using ESP32, LDR sensors, and Blynk for real-time monitoring and improved efficiency.
# ☀️ IoT-Based Dual-Axis Sun Tracking Solar Panel

##  Overview

This project presents an **IoT-enabled dual-axis solar tracking system** that automatically aligns a solar panel with the sun to maximize energy generation. The system uses **LDR sensors, servo motors, and an ESP32 microcontroller** to track sunlight in both horizontal and vertical directions, while providing **real-time monitoring through the Blynk IoT platform**.

---

##  Problem Statement

Fixed solar panels do not maintain optimal alignment with the sun throughout the day, leading to reduced efficiency.

This project solves the problem by:

* Automatically adjusting panel orientation
* Providing real-time monitoring using IoT
* Improving overall energy efficiency

---

##  Objectives

* Develop a **dual-axis tracking mechanism**
* Implement **IoT-based real-time monitoring**
* Measure and analyze **power generation efficiency**
* Create a **low-cost and reliable system**

---

##  System Architecture

### 🔹 Modules Used:

* **Sensing Module** → LDR sensors detect sunlight intensity
* **Processing Module** → ESP32 processes sensor data
* **Actuation Module** → Servo motors adjust panel position
* **Monitoring Module** → Sensors measure voltage, current, temperature
* **Communication Module** → Data sent to Blynk via Wi-Fi

---

##  Hardware Components

| Component         | Quantity | Function                      |
| ----------------- | -------- | ----------------------------- |
| ESP32             | 1        | Controller + IoT              |
| LDR Sensors       | 4        | Sunlight detection            |
| Servo Motors      | 2        | Dual-axis movement            |
| DHT22             | 1        | Temperature & humidity        |
| INA219            | 1        | Voltage & current measurement |
| Solar Panel (20W) | 1        | Energy source                 |

---

##  Software Used

* Arduino IDE
* Blynk IoT Platform

---

##  Working Principle

* Four LDRs detect sunlight intensity from different directions
* ESP32 compares sensor values
* Servo motors rotate panel toward maximum light
* System continuously adjusts for optimal alignment
* Data is sent to Blynk dashboard for monitoring

---

##  Algorithm Flow

1. Initialize sensors and Wi-Fi
2. Read LDR values
3. Compare light intensity
4. Adjust servo motors (X & Y axis)
5. Measure voltage, current, temperature
6. Upload data to Blynk
7. Repeat continuously

---

##  Results & Performance

*  Efficiency Improvement:** ~30% higher than fixed panel
*  Tracking Accuracy:** ±5° deviation
*  IoT Delay:** < 3 seconds
*  System Stability:** No vibration or drift

---

## Performance Insight

The graph (Page 27 in report) shows:

* Increasing power output throughout the day
* Tracking panel consistently outperforming fixed panel

---

##  IoT Dashboard (Blynk)

| Parameter      | Description          |
| -------------- | -------------------- |
| Voltage        | Solar output voltage |
| Current        | Measured via INA219  |
| Power          | Calculated (V × I)   |
| Temperature    | Environmental data   |
| Servo Position | Panel orientation    |

---

##  Challenges Faced

* Servo jitter at mid-light levels
* IoT delay issues (resolved with retry logic)
* Synchronization between sensors and motors

---

##  Limitations

* Wi-Fi range limitations
* Servo torque not suitable for large panels
* Slight power consumption by IoT module

---

##  Future Scope

* AI-based sunlight prediction
* Battery management system
* GPS-based tracking
* Large-scale solar farm implementation

---

##  Conclusion

The system successfully demonstrates how **IoT, embedded systems, and renewable energy** can be integrated to create an efficient and intelligent solar tracking solution, achieving up to **30% improvement in energy output**.

---

##  Team Members

* Ansh Jolly
* Ayush Jangra
* Daksh Sharma
* Ashu Garg

---

##  Keywords

IoT | Solar Tracking | ESP32 | Renewable Energy | Embedded Systems | Blynk

---
