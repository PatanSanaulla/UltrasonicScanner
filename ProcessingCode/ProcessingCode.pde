import processing.serial.*;

Serial port;
String result="";
float angle=0;


void setup() {
  size(200, 200);
  background(255);
  smooth();
  noStroke();
  port = new Serial(this, "COM6", 9600);
  port.bufferUntil('\n');
  surface.setResizable(true);
}

void serialEvent(Serial myPort){      //method to read the input on the COM port
    result = myPort.readStringUntil('\n'); 
    int index = result.indexOf(' ');
    angle = Float.parseFloat((result.substring(0,index)).trim());  // getting the angle value
    result = result.substring(index).trim();                       // getting the status of obstacle
}

void draw() {
    if (result.equals("Yes")){
      fill(255, 0, 0);     // coloring the range as red when there is obstacle
    }else{
      fill(0,0,0);          // coloring the range as black when there is no obstacle
    }
    text("Red is obstacle, Black is free space", 0, 140);
    pushMatrix();
    translate(100, 100);
    rotate(-radians(angle));
    rect(0, 0, 80, 10);
    popMatrix();
}
