  #include "LedControl.h"
  
int trigPin = 13;
int echoPin = 3;
int val;

LedControl lc=LedControl(12,11,10,1);

unsigned long delaytime=500;

byte A[8]={B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000};
byte B[8]={B00000000,B00000000,B00111100,B00111100,B00111100,B00111100,B00000000,B00000000};
byte C[8]={B00000000,B01111110,B01111110,B01111110,B01111110,B01111110,B01111110,B00000000};
byte D[8]={B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};
byte E[8]={B11111111,B11111111,B11100011,B11010011,B11001011,B11000111,B11111111,B11111111};
byte F[8]={B10000000,B01000000,B00111100,B00111100,B00111100,B00111100,B00000010,B00000001};

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT);   

  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

void onestep(){
  lc.setRow(0,7,A[0]);
  lc.setRow(0,6,A[1]);  
  lc.setRow(0,5,A[2]);
  lc.setRow(0,4,A[3]);
  lc.setRow(0,3,A[4]);
  lc.setRow(0,2,A[5]);
  lc.setRow(0,1,A[6]);
  lc.setRow(0,0,A[7]);
  delay(100);
}
void twostep(){
  lc.setRow(0,7,B[0]);
  lc.setRow(0,6,B[1]);
  lc.setRow(0,5,B[2]);
  lc.setRow(0,4,B[3]);
  lc.setRow(0,3,B[4]);
  lc.setRow(0,2,B[5]);
  lc.setRow(0,1,B[6]);
  lc.setRow(0,0,B[7]);
  delay(100);
}
void threestep(){
  lc.setRow(0,7,C[0]);
  lc.setRow(0,6,C[1]);
  lc.setRow(0,5,C[2]);
  lc.setRow(0,4,C[3]);
  lc.setRow(0,3,C[4]);
  lc.setRow(0,2,C[5]);
  lc.setRow(0,1,C[6]);
  lc.setRow(0,0,C[7]);
  delay(100);
}
void fourstep(){
  lc.setRow(0,7,D[0]);
  lc.setRow(0,6,D[1]);
  lc.setRow(0,5,D[2]);
  lc.setRow(0,4,D[3]);
  lc.setRow(0,3,D[4]);
  lc.setRow(0,2,D[5]);
  lc.setRow(0,1,D[6]);
  lc.setRow(0,0,D[7]);
  delay(100);
}
void laststep(){
  lc.setRow(0,7,E[0]);
  lc.setRow(0,6,E[1]);
  lc.setRow(0,5,E[2]);
  lc.setRow(0,4,E[3]);
  lc.setRow(0,3,E[4]);
  lc.setRow(0,2,E[5]);
  lc.setRow(0,1,E[6]);
  lc.setRow(0,0,E[7]);
  delay(300);
  lc.setRow(0,7,F[0]);
  lc.setRow(0,6,F[1]);
  lc.setRow(0,5,F[2]);
  lc.setRow(0,4,F[3]);
  lc.setRow(0,3,F[4]);
  lc.setRow(0,2,F[5]);
  lc.setRow(0,1,F[6]);
  lc.setRow(0,0,F[7]);
  delay(300);
}
void loop() {
  long duration, distance;    
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);          
  digitalWrite(trigPin, HIGH);   
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  val = duration * 17 / 100;
  if(val<1000){
    Serial.println(val);
    delay(10);
  }

  if(val>500){
    onestep();
  } else if(val>410){
    twostep();
  } else if(val>280){
    threestep();
  } else if(val>150){
    fourstep();
  } else {
    laststep();
  }
}
