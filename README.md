# smart-home-automation
Smart home automation via ARM M7 Based processor running RT-Thread OS

# Description
Smart automation systems are a combination of human radition detection sensors and controllers which monitor the controlling of lights & appliances.The controller control the lights via relay which can control the switching of the AC loads via a DC signal.

# Sensor Implementation
PIR sensors allow you to sense motion, almost always used to detect whether a human has moved in or out of the sensors range. They are small, inexpensive, low-power, easy to use and don't wear out. For that reason they are commonly found in appliances and gadgets used in homes or businesses. They are often referred to as PIR, "Passive Infrared", "Pyroelectric", or "IR motion" sensors.

# Hardware Framework
The Controller used in this project is STM32 F722ZE-RE which has ARM CORTEX – M7 as the CPU with 512kb of flash memory and 32 kHz internal clock

# Software Framework
The OS used for this project is RT-Thread RTOS
The program is written in c the only work of the main function is to activate the three threads.

Wiring
RED LED P(A, 14)
BLUE LED P(A, 7)
Passive Infrared Sensor P(D, 7)
Relay P(A, 6)
