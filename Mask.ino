#include <Servo.h>
Servo myservo; //this is my servo
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


const int led = 10;
const int button = 4;
int val = 0; //placeholder
int oldval = 0; // delay placeholder
int x = 0; 
// i'll use this placeholder later. this is the key component. the magic stuff. 
int pos = 0; //where the servo is

long timer = 0; 
//keeping track of time. not sure if ill use it. 
const long ret = 119;    //difference between ret and go is duration the mouth will be open
const long go = 100;
const long talk = 50;


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
  Serial.begin(115200); // unsure why the serial is this high
  result = sd.begin(SD_SEL, SPI_HALF_SPEED);
  //tells the shield to boot up

  result = MP3player.begin(); 
  //tells the sheild it's a mp3 player now. 

}



/////////////-------------------------/////////////////////




void loop() {
  val = digitalRead(button);

  if ((val == HIGH) && (oldval == LOW) && (timer < ret)) {

    x = 1 - x;
  } else {}

  oldval = val;


  if (x == 1) {
    timer ++;
    delay(10);
    digitalWrite(led, HIGH);
    

  } else {}
  
  Serial.println(val, timer); // for debugging the button's functionality

  if (timer < ret && timer > go ) {
    pos = 100;
  } else {}
  if (timer == talk){
     result = MP3player.playTrack(1);
  } else {}

  if (timer == ret) { // makes the timer reset, and makes the servo return
    timer = 0;
    pos = 0;
    x = 0;
    MP3player.stopTrack();
  } else {}

  myservo.write(pos);  // must be at the end

}
