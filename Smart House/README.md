# Work developed for Embedded Systems course

The goal is to build a smart house, capable of detecting movement within a room, get temperature readings and light intensity.
It should still be possible to change the state of a light through an android app, as well as choose the 'autonomous home' option.

### Functional Requirements
- [x] Turn on the light if someone enters a room
- [x] Turn off the light if someone leaves a room
- [x] Change each light status with the android app
- [x] Get temperature values
- [x] Get light intensity values
- [x] Turn on the house lights in case the light intensity is lower than a certain threshold

### Materials
* 2 GP2Y0A60SZLF
* 3 hc-sr04 ultrasonic sensor
* 1 DHT11 sensor
* 5 leds
* 1 Tinkerkit Shield
  * 1 LDR sensor
* Jumper wire
* Bread board

### Hardware Shematic
#### Sensors
![sensor_schematic_bb](https://user-images.githubusercontent.com/17826603/40629700-16d809a0-62c5-11e8-986f-0db821455949.jpg)

#### Actuators
![actuators](https://user-images.githubusercontent.com/17826603/40630217-a916bf48-62c8-11e8-9a61-7504367543fb.jpg)

### Commands
* `led1_ON` | `led1_OFF` 
> Specify the division that we want to change the status of the light

* `temperature` 
> Return the temperature reading in celsius

* `luminosity` 
> Return the light intensity value

* `house_auto_ON` 
> Set the house in 'autonomous mode'

* `house_auto_OFF` 
> Remove the 'autonomous mode' 

* `house_threshold_(0-1023)` 
> Sets a threshold, below which the lights in the house should be turned on.
		This value is set in the android app.

* `house_settings` 
> Return the threshold and the 'autonomous mode' values

* `leds_STATUS` 
> Get the status off all the led's in the house, and other variables


  


