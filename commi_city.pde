import processing.serial.*;

int lf = 10;
String myString = null;
int val = 0;

Serial port;
PFont font;

void setup() {
  println("Available serial ports:");
  println(Serial.list());
  
  port = new Serial(this, "COM18", 9600); 
  //port = new Serial(this, Serial.list()[0], 9600);  
  
  port.clear();

  myString = port.readStringUntil(lf); 
  myString = null;
  
  size(600,600);
  background(255);
}

void draw() {  if (val > 200) {
    background(0, 255, 0);
    fill(255,0,0);
    rectMode(CENTER);
    rect(width/2,height/2,width-val,height-val);
    
    fill(255); 
    textSize(36);
    textAlign(CENTER);
    text(val, width/2, 80);
    textSize(16);
    text("safe", width/2, 120);
    println("val = " + val);
  
  } else {
    background(255, 0, 180);
    fill(255,0,0);
    rectMode(CENTER);
    rect(width/2,height/2,width-val,height-val);
    
    fill(255);
    textSize(36);
    textAlign(CENTER);
    text(val, width/2, 80);
    textSize(16);
    text("Dangerous", width/2, 120);
    println("val = " + val);
  }
}


void serialEvent(Serial port) { 
    myString = port.readStringUntil(lf);
    
    if (myString != null) { 
      try { 
        val=Integer.parseInt(myString.trim()); 
      } 
      catch (NumberFormatException npe) { 
      }
    }
}
