# IOTRICITY 3.0 Project

#Team Name :- CENTURION

## Team

- Member 1: Ankan Kundu — ECE3 — 2nd Year
- Member 2: Aritra Mukherjee — CSE (AI/ML) — 2nd Year
- Member 3: Arpan Kundu — CSE (AI/ML) — 2nd Year
- Member 4: Animesh Maji — CSE (AI/ML) — 2nd Year

## Project

### Smart Water Management and Irrigation System

Our project is a smart water management and irrigation system designed to monitor water availability, water flow, leakage, and water quality.

The system uses sensors connected to an Arduino to collect real-time information. The readings can be displayed on an LCD, and the system can provide warnings when an abnormal condition is detected.

The project can also be extended with a soil-moisture sensor to provide automatic smart irrigation.

## Components

- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- Water Flow Sensor
- Water Leakage Sensor
- pH Sensor
- 16×2 I2C LCD Display
- Relay Module
- Water Pump
- Buzzer
- Green LED
- Yellow LED
- Red LED
- Resistors
- Jumper Wires
- Breadboard
- Power Supply

### Future Component

- Soil Moisture Sensor

## How It Works

The system continuously collects information from different sensors.

First, the ultrasonic sensor checks the water level inside the tank. If the water level becomes low, the system provides a warning and controls the pump according to the programmed condition.

The water-flow sensor checks whether water is actually flowing through the pipe. If the pump is ON but the expected water flow is missing, the system can identify a possible pipe blockage, dry-pump condition, or another water-flow problem.

The water-leakage sensor can detect unwanted water leakage and generate an alert.

The pH sensor checks the water quality by measuring its pH value. The reading can be shown on the LCD along with a quality status such as GOOD, WARNING, or BAD.

In the future, a soil-moisture sensor can be added. When the soil is dry, the system can turn the irrigation pump ON. When the soil has sufficient moisture, the pump can be turned OFF. This helps prevent unnecessary watering and saves water.

## Features

### 1. Water Tank Level Monitoring

An ultrasonic sensor checks how much water is present in the tank.

- Water level low → Warning is shown and pump control is activated according to the programmed condition.
- Water level sufficient → The system continues normal operation.
- Tank full → The system can stop the pump and provide a full-tank warning.

### 2. Water Leakage / Flow Monitoring

A water-flow sensor measures whether water is actually flowing through the pipe.

If the pump is ON but the expected water flow is missing, the system can identify a possible:

- Pipe blockage
- Dry-pump condition
- Leakage
- Water-flow problem

A leakage sensor can also provide a warning when unwanted water is detected.

### 3. Water Quality Monitoring

The system can use water-quality sensors such as:

- pH sensor
- Turbidity sensor
- TDS sensor

The system can display the sensor readings and warn when the water quality is outside the selected range.

### 4. Smart Irrigation — Future Feature

A soil-moisture sensor can be added to check the condition of the soil.

- Soil dry → Pump ON
- Soil sufficiently wet → Pump OFF

This helps prevent unnecessary watering and reduces water wastage.

## Display and Alerts

The LCD can display:

- Water tank level
- Pump status
- pH value
- Water quality status
- Sensor warnings

LEDs and a buzzer can provide additional visual and audio alerts.

## Future Improvements

- Add a soil-moisture sensor for automatic irrigation.
- Add a turbidity sensor for water clarity monitoring.
- Add a TDS sensor for dissolved-solids monitoring.
- Add IoT connectivity for remote monitoring.
- Develop a mobile application for live sensor readings.
- Store sensor data in the cloud.
- Add automatic notifications for leakage or low water level.
- Improve sensor calibration and accuracy.
- Add solar-powered operation.
- Add automatic fault detection and reporting.

## Project Goal

The main goal of this project is to create a smart, sensor-based water management system that can monitor water availability, flow, leakage, and quality while providing a foundation for automatic irrigation.

By adding IoT connectivity and soil-moisture monitoring in the future, the system can become a more complete Smart Irrigation and Water Management System.
