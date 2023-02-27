# Smoke-detector
<hr>

<br>
<img width="450" alt="image" src="https://user-images.githubusercontent.com/68846562/206907669-76e25bbd-0210-47be-8764-59712371f6b7.png">

<br>

<p>
This is a prototype for an iot based smoke detector which measures the amount of Carbon monoxide, lpg and smoke present. We display the output on the serial monitor as well as the lcd display. We will use the serial plotter to plot the results.
Purpose: To design a working model to detect smoke and give readings about the contents of the smoke such as carbon monoxide, smoke percent, lpg, etc
Requirements: The model should measure all the major components of smoke and give an analysis graph. The results should be stored on the cloud using thingspeak and esp8266. All the hardware requirements are mentioned below.


</p>

## Components
1. Arduino uno
2. MQ2 sensor
3. jumper cables
4. LCD 16X2 display module
5. I2C module
6. esp8266 wifi module
7. usb type B connector
8. screwdriver
9. pins
10. soldering machine

## Analysis and research
The following are the reaseach papers referenced: <br>
https://ieeexplore.ieee.org/document/8712773 <br>
https://ieeexplore.ieee.org/document/7724514 <br>
https://www.instructables.com/Smoke-Detector/ <br>

<b>MQ2 datasheet</b> <br>
<img width="278" alt="image" src="https://user-images.githubusercontent.com/68846562/206907632-8200fbc5-e6cb-4169-a269-64d16c0fef2f.png">

## Phases of the project
Phase 1: Collection of hardware. Sourced from amazon

Phase 2: Basic integration. Here we checked whether the sensor is working or not by simply checking its power supply and its ability to detect smoke.

Phase 3: Connection of arduino uno with mq2 sensor

Phase 4: Soldering the pins on the lcd display and then integrating the lcd with i2c with the entire setup. (Soldering was a tricky part)

Phase 5: Uploading code and integrating the right libraries

Phase 6: Testing with incense sticks and burning paper.

Phase 7: Using esp8266 wifi module to use the cloud service on thingspeak.


## Precautions taken care of:

1. Proper safety while soldering
2. Always connect 3.3V to the esp pin. If 5v power supply is used then the esp will be fried.
3. Always disconnect the arduino while changing pins on the board.

## Block diagram

<img width="470" alt="image" src="https://user-images.githubusercontent.com/68846562/206908157-17d7da56-bc3d-4800-8943-acac6b5fdd43.png">


## Circuit diagram
<img width="250" alt="image" src="https://user-images.githubusercontent.com/68846562/206908504-92af92fd-2b4e-496c-85b5-6ce410023f8b.png">


## Difficulties encountered
MQ2 sensor showing 0 values:
We adjusted the connections to the breadboard using jumper cables and verified the pins to be connected. After checking the values, we made use of a stronger source of smoke. This solved the problem as it turned out that the carbon monoxide present in incense sticks is too little to be detected


Soldering:
We asked for help from the racing department of our college to help solder the lcd pins.


LCD display not showing values despite being powered on:
Turns out, this problem had an easy solution. After days of researching, we simply used a screwdriver and turned the screw of the potentiometer on the I2C module. As a result, the reading on the lcd were displayed properly.


## Testing:
Following things can be used for testing:
1. Incense stick
2. A paper set on fire
3. Plastic set on fire
4. A burning cigarette stub



## Plotting:
<img width="199" alt="image" src="https://user-images.githubusercontent.com/68846562/206908347-57556308-d47b-4ecd-a71b-f519d7bd1afb.png">


## Future scope:
We aim to upload the reading on the thingspeak interface with cloud. Note that, arduino uno by itself does not have any wifi capabilities. So we need to take help of the esp8266 wifi module chip. However due to connection issues with the esp8266 and an error in thingspeak interface, we weren't able to complete the cloud service on time.


