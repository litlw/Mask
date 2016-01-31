#include <Servo.h>

#include <SPI.h>
//Add the SdFat Libraries
#include <SdFat.h>
#include <SdFatUtil.h>
//and the MP3 Shield Library
#include <SFEMP3Shield.h>

//create and name the library object
SFEMP3Shield MP3player;
SdFat sd;
SdFile file;

Servo myservo; //this is my servo

const int led = 10;
const int button = 4;
int val = 0; //placeholder
int oldval = 0; // delay placeholder
int x = 0;
// i'll use this placeholder later. this is the key component. the magic stuff.
int pos = 0; //where the servo is

long timer = 0;
//keeping track of time. not sure if ill use it.
const long ret = 520;    //difference between ret and go is duration the mouth will be open
const long go = 100;
const long talk = 160;


byte result;
// this turns our command into bytes, so the shield knows what do/
byte temp;
//for debugging.

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  myservo.attach(5);
  Serial.begin(9600); // unsure why the serial is this high
  result = sd.begin(SD_SEL, SPI_HALF_SPEED);
  //tells the shield to boot up

  result = MP3player.begin();
  //tells the sheild it's a mp3 player now.

}



/////////////-------------------------/////////////////////




void loop() {
  val = digitalRead(button);

  while (timer == 0) {
    if ((val == HIGH) && (oldval == LOW)) {

      x = 1 - x;
    } else {}

  }

  oldval = val;


  if ((timer < ret) && (x == 1)) {
    timer ++;
    delay(10);
    if (timer > go) {
      result = MP3player.playTrack(1);
      digitalWrite(led, HIGH);
      pos = 0;
    } else if ((timer > go) && (timer > talk)) {

      pos = 100;
    } else {
      pos = 0;
    }
  } else if ((timer >= ret) && (x == 1)) {
    timer = 0;
    x = 0;
    MP3player.stopTrack();
    digitalWrite (led, LOW);
    }


  myservo.write(pos);  // must be at the end

}
