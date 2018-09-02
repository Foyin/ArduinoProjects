#### Purpose: 

To create the ability for multiple store fronts on the same network to use a nodejs chat app to chat between stores easily and efficiently. To tackle the simple problems of using tools like this on multiple storefronts we will using a range sensor. So while an employee is at a register (node in the network) the chat app is running but if they are away for longer than 15 minutes, the app closes. The same thing is being done with a doodling app in two ways. A scalable way and a less scalable way.

#### Devices needed:
- Arduino IDE
- Ultrasonic range sensor
- Arduino Uno

#### Layout:
Make the following connections
- Ultrasonic sensor GND wire to relay GND pin
- Ultrasonic sensor VCC wire to relay 3v pin
- Ultrasonic sensor SIG wire to relay pin 7

#### Notes:
You would need to download and install the following tools
- nodejs
- npm
- Express
- p5js
- shelljs
- serialportjs (version 4)
- socket.io

#### To use:
To run, upload the grove ulrtrasonic range finder program and:
- To run chat server with sensor run "node rangeChat.js"
- To run whiteboard (more scalable) with sensor run "node rangeWhiteboard-p.js"
- To run whiteboard (less scalable) with sensor run "node rangeWhiteboard.js"

