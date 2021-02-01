# Smart-Home-Automation
Smart home automation via ARM M7 Based processor running RT-Thread OS

# Description
Smart automation systems are a combination of sensors and controllers which monitor the controlling of lights & appliances as per the requirement. The controller controls the lights via a relay which can control the switching of the AC loads via a DC signal.

# Sensor Implementation
Passive infrared sensors sense the radiations emitted by the living object.
PIRs are made of a pyroelectric sensor (which you can see below as the round metal can with a rectangular crystal in the centre), which can detect levels of infrared radiation. 

When the sensor is idle, both slots detect the same amount of IR, the ambient amount radiated from the room or walls or outdoors. When a warm body like a human or animal passes by, it first intercepts one half of the PIR sensor, which causes a positive differential change between the two halves.

# Hardware Framework
The Controller used in this project is STM32 F722ZE-RE which has ARM CORTEX – M7 as the CPU with 512kb of flash memory and 32 kHz internal clock

# Software Framework
The OS used for this project is RT-Thread RTOS
The program is written in primarily C language

# Wiring
RED LED P(A, 14)
BLUE LED P(A, 7)
Passive Infrared Sensor P(D, 7)
Relay P(A, 6)

# Block Diagram


PIR Sensor  -> STM32F7 -> Relay




INPUT            ->        OUTPUT

