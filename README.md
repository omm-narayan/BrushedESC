# BrushedESC Project - ATTiny ESC

## Project Overview
This project is a brushed DC motor ESC using an ATTiny microcontroller.  
It reads PWM input signals and controls motor speed and direction via an H-bridge MOSFET setup.  
The project demonstrates motor control, PWM-to-analog conversion, and bidirectional driving using a microcontroller.

---

## Component Images

### 1. Brushed Motor with ESC
![Brushed Motor and ESC setup](brushed_motor_esc.jpg)  
*Shows the brushed motor connected to the ESC for testing.*

### 2. ATTiny PWM Circuit
![ATTiny PWM to Analog Circuit](attiny_pwm_circuit.jpg)  
*ATTiny microcontroller reading PWM input and outputting control signals to the H-bridge.*

### 3. H-Bridge MOSFET Setup
![H-Bridge MOSFET on Breadboard](hbridge_breadboard.jpg)  
*H-bridge on breadboard using 2 N-channel + 2 P-channel MOSFETs for motor control.*

---

## Pinouts & Wiring
- **OUT1**: Motor terminal 1 (connect to H-bridge output)  
- **OUT2**: Motor terminal 2 (connect to H-bridge output)  
- **IN**: PWM input from RC receiver or microcontroller  
- **ATTiny**: Reads PWM input and controls H-bridge MOSFETs  
- **H-Bridge MOSFET**: Converts ATTiny PWM signals into bidirectional motor drive  

---

## Understanding the H-Bridge
An H-Bridge allows a DC motor to be driven forward or backward by reversing the voltage across it.  
Its name comes from the four switches and motor layout forming an "H" shape.

### Operation
- **Forward:** Activating switches 1 and 4 spins the motor clockwise  
- **Reverse:** Activating switches 2 and 3 spins the motor counter-clockwise  
- **Safety:** Never activate switches on the same side (1+2 or 3+4) to avoid a short circuit  

### Using MOSFETs
Switches are replaced with transistors (2 N-channel + 2 P-channel MOSFETs).  
Diodes protect against voltage spikes. The ATTiny drives the MOSFETs using PWM signals.

### Speed Control with PWM
PWM rapidly switches motor voltage on and off.  
Duty cycle determines effective voltage → higher duty cycle = faster rotation.

### Types of H-Bridge Drivers
Breadboard H-bridges are good for learning, but ICs like **L293D** or **DRV8873** are more efficient and protected.  

[Video Reference: How H-Bridge Motor Drivers Work! (Robonyx)](https://youtu.be/6HUs4ERsVkE)

---

## Suggested Images to Capture
- `brushed_motor_esc.jpg` → Motor + ESC connections  
- `attiny_pwm_circuit.jpg` → ATTiny PWM wiring  
- `hbridge_breadboard.jpg` → H-bridge MOSFETs on breadboard  

---

## License
MIT License – free to use and modify
