#### Purpose: 
In this project we are creating a simple alarm system with arduino. The system checks if there is anything within a specified range and a buzzer goes off accordingly. And you can switch off the alarm with a physical switch so nothing happens when an obstacle is in range. Remember to compensate for power

#### Devices needed:
- [Arduino IDE](https://www.arduino.cc/en/Main/Software)
- [Grove Ultrasonic Range Sensor](http://wiki.seeedstudio.com/Grove-Ultrasonic_Ranger/)
- [Piezo buzzer](http://wiki.seeedstudio.com/Grove-Buzzer/)
- [Switch/Rotary Encoder](http://wiki.seeedstudio.com/Grove-Encoder/)
- [Arduino Uno](https://store.arduino.cc/usa/arduino-uno-rev3)
- [Arduino helishun relay 4 channel stack](https://www.seeedstudio.com/Relay-Shield-v3.0-p-2440.html)

#### Layout:
Stack the arduino relay on top of the uno then make the following connections.
- Ultrsonic sensor GND wire to relay GND pin
- Ultrsonic sensor VCC wire to relay 3v pin
- Ultrsonic sensor SIG wire to relay pin 6
- Switch GND wire to relay pin GND
- Switch VCC wire to relay 5v pin
- Switch SIG wire to relay pin 7
- Piezo buzzer GND wire to relay NC channel1 
- Piezo buzzer VCC wire to relay NO channel1 
- Piezo buzzer SIG wire to relay COM1 channel1 

![closeup](https://user-images.githubusercontent.com/15314851/44922321-2023c880-ad13-11e8-800b-4193045a8187.JPG)

![setup2](https://user-images.githubusercontent.com/15314851/44922334-29ad3080-ad13-11e8-9dc1-71d02e930097.JPG)

![setup](https://user-images.githubusercontent.com/15314851/44922441-6711be00-ad13-11e8-865d-aab604a6a9c4.JPG)

#### Issues:
The wiring is a bit naive there are better ways to do it but this way will help you understand the project a lot better, after that you can improve the wiring. For example instead of using the 5v and 3v ports we can just wire the two devices in parallel, that way they save sapce on the board without compromising voltage.
Also the loudness of the buzzer is dependent on the voltage coming thorugh it. So you can make it louder by adding a battery inbetween.

#### Notes:
In with the specific relay used here pin 7 is the input pin for channel1, pin 6 is the input pin for channel2, pin 5 is the input pin for channel2, pin 5 is the input pin for channel3, and pin 4 is the input pin for channel5.

You can control volume of alarm with rotary encoder, that why it is better than a simple binary switch

#### To use:
Set up all the specified connections, open your IDE, pick your arduino and port, Upload rangeBuzzer.ino program and use your device.

For Linux users you need to give the arduino permission to access your computers port.

If you run Arduino IDE on Ubuntu, most possibly you cannot upload to Arduino board, caused by the error:

`avrdude: ser_open(): can't open device "/dev/ttyACM0": Permission denied
ioctl("TIOCMGET"): Inappropriate ioctl for device`

To fix it, enter the command:

`sudo usermod -a -G dialout <username>`

`sudo chmod a+rw /dev/ttyACM0`

Where `/dev/ttyACM0` is the specified port

you're going to need to do this everytime you disconnect the arduino so you can make a shorter alias for the command with the commands:

`alias <new-command-name>="sudo usermod -a -G dialout <username>`

`alias <new-command-name>="sudo chmod a+rw /dev/ttyACM0`



