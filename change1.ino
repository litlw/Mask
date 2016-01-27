#include <Servo.h>
Servo myservo; //this is my servo


const int led = 10;
const int button = 4;
int val = 0; //placeholder
int oldval = 0; // outdated placeholder
int x = 0; // this is the key component
int pos = 0; //where the servo is
long timer = 0; //keeping track of time
const long ret = 300;
const long go = 100;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  myservo.attach(5);
}



/////////////-------------------------/////////////////////




void loop() {
  val = digitalRead(button);

  if ((val == HIGH) && (oldval == LOW) && (timer < ret)) {

    x = 1 - x;
  }

  oldval = val;


  if (x == 1) {
    timer ++;
    delay(10);
    digitalWrite(led, HIGH);

    if (timer < ret && timer > go ) {
      pos = 100;
    }
    else{
      timer = 0;
      pos = 0;
      x = 0;
    }
  }

  myservo.write(pos);

}
