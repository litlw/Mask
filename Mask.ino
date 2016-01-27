#include <Servo.h>
Servo myservo; 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
const int led = 9;

const int button = 7;
int val=0;
  int oldval=0;
int status=0;
int x = 0;
int pos = 0;
long time = 0;
const long ret = 300;
const long go = 100;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  myservo.attach(5);
}

// the loop routine runs over and over again forever:
void loop() {
val = digitalRead(button);
  
  if((val == HIGH)&&(oldval == LOW)&&(time < ret)){
    
    x = 1 - x;
  } else {}
  
  oldval = val;
  
  
  if(x == 1 && time > go ){
    time ++;
    delay(10);
    pos = 100;
    digitalWrite(led, HIGH);
  } else {
  pos = 0;
  digitalWrite(led, LOW);
  }
 
  myservo.write(pos);

}
