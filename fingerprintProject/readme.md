
# Finger Print Verification

#### Purpose: 
In this project we are creating alarm system with certain specifications to be use at home or in businesses. A light sensor will check if how bright the room is and a range sensor checks if anyone is at the entrance. The idea is to check if we have an intruder after closing hours. If the room is dark and no one is at the entrance and the lights are off the the buzzer stays on, else if any of these conditions are broken it would go off. The only way to shut it off is by using your finger print. Only registered fingerprints would shut it off for five mins. Its just a simple case that could be scaled up really well.

#### Devices needed:
- [Arduino Mega](https://www.arduino.cc/en/Main/arduinoBoardMega/)
- [Ultrasonic range sensor](http://wiki.seeedstudio.com/Ultra_Sonic_range_measurement_module/)
- [Piezo buzzer](http://wiki.seeedstudio.com/Grove-Buzzer/)
- [Fingerprint sensor (model: GT-511C3/GT-511C1R)](https://github.com/Foyin/ArduinoProjects/tree/master/Fingerprint_Scanner_TTL)
- [Light sensor](http://wiki.seeedstudio.com/Grove-Light_Sensor/)

#### Layout:
Look for each components schematics on their respective company websites for the proper hook uk for your device
https://www.digikey.ca/en/maker/projects/aad2459ecf4b493f996656cfdd1e5464 - this is a useful link

![img_0349](https://user-images.githubusercontent.com/15314851/44921680-3d579780-ad11-11e8-8a9e-0113b0e7f188.JPG)

![img_0350](https://user-images.githubusercontent.com/15314851/44921683-421c4b80-ad11-11e8-9baf-b693018e66d6.JPG)

![img_0351](https://user-images.githubusercontent.com/15314851/44921696-47799600-ad11-11e8-97c2-58d406c35d7b.JPG)

#### Notes:
- The GT-511C1R fingerprint sensor can store only 20 records, also it has been retired. It does not store the pictures taken. It uses and irreversible algorithm to convert the picture into a less human friendly form. Similar to how websites store passwords.
- The arduino mega has more than one serial port so this example works. It may not work on the uno because the FPS uses the serial port communicate and the uno has only one serial port.

#### To use:
- Add the arduino Fingerprint_Scanner_TTL file to your arduino libraries
- Make necessary connections to your arduino
- Use enroll file to register fingerprints
- Use range_light_buzzer_FPS.ino file to test device

