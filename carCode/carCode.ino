// Define board outs
#include <Servo.h>
#define in1 5
#define in2 6
#define in3 10
#define in4 11

// Global variables
int state;
int servo = 12;
int pos;

// Instantiate Servo instance
Servo myservo;

void setup() {
  // Set up objects, outputs, and variables
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  servo = 90;
  
  myservo.attach(servo);
  Serial.begin(9600);
}

void loop() {
  // If there's information from the user then read it and decide what to do
  if (Serial.available() > 0) {
    state = Serial.read();

    switch (state) {
      case 'w':
        forward();
        break;
      case 'a':
        left();
        break;  
      case 'd':
        right();
        break;  
      case 's':
        back();
        break;
      case 'q':
        halt();
        break;
      case 'r':
        resetServo();
        break;
    }
  }
}

// Move car forward
void forward() {
  analogWrite(in1, 64);
}

// Turn wheels using servo
void left() {
  pos -= 10;
  // Make sure we don't turn too far
  if (pos >70){
    myservo.write(pos);
  }
}

// Turn wheels using servo
void right() {
  pos += 10;
  // Make sure we don't turn too far
  if (pos < 110){
    myservo.write(pos);
  }
}

// Move car backward
void back() {
  analogWrite(in2, 128);
}

// Stop car
void halt() {
//  myservo.write(90);
  analogWrite(in1, 0);
  analogWrite(in2, 0);
}

// Set servo to default position
void resetServo() {
  pos = 90;
  myservo.write(pos);
}
