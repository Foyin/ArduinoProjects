// ITP Networked Media, Fall 2014
// https://github.com/shiffman/itp-networked-media
// Daniel Shiffman

// Keep track of our socket connection
var socket;
var pen;
var bg;
var red;
var blue;
var green;
var white;
var black;
var diameter;

function setup() {
  createCanvas(windowWidth, windowHeight);

  bg = white;
  diameter = 5;
  pen = color(255, 0, 0);
  white = color(255);
  black = color(0);
  red = color(255, 0, 0);
  blue = color(0, 255, 0);
  green = color(0, 0, 255);

  background(255);
  
  // Start a socket connection to the server
  // Some day we would run this server somewhere else
  socket = io.connect('http://localhost:3000');
  
  // We make a named event called 'mouse' and write an
  // anonymous callback function
  socket.on('mouse',
    
    // When we receive data
    function(data) {
      console.log("Got: " + data.x + " " + data.y);
      // Draw a blue circle
      fill(0,0,255);
      noStroke();
      ellipse(data.x, data.y, diameter, diameter);
    }
  );
}

function keyTyped() {
  
  if(key === 'r' || key === 'R' ){ pen = red;}
  if(key === 'g' || key === 'G' ){ pen = green;}
  if(key === 'b' || key === 'B' ){ pen = blue;}
}

function keyPressed(){
  if(keyCode === 'CONTROL' && bg == white){ bg = black;}
  if(keyCode === 'CONTROL' && bg == black){ bg = white;}

}

function mouseDragged() {
  frameRate(200);  

  // Draw some white circles
  fill(pen);
  noStroke();
  ellipse(mouseX,mouseY,diameter,diameter);
  
  // Send the mouse coordinates
  sendmouse(mouseX,mouseY);
}

// Function for sending to the socket
function sendmouse(xpos, ypos) {
  // We are sending!
  console.log("sendmouse: " + xpos + " " + ypos);
  
  // Make a little object with  and y
  var data = {
    x: xpos,
    y: ypos
  };

  // Send that object to the socket
  socket.emit('mouse',data);
}
