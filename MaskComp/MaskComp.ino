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

const int led = 10; // these are gonna light up the box
const int led2 = 3; // this will be the "eyes" of the thing
const int button = 4; // the obvious button
const int servo = 2; // rotates the head. 
int val = 0; //placeholder
int x = 0; //program start
int audiostart = 0; //start sound
int servostart = 0; //start servo motor
// i'll use this placeholder later. this is the key component. the magic stuff.
int pos = 0; //where the servo is


long timer = 0;//keeping track of time. not sure if ill use it.
const long ret = 310;    //difference between ret and go is duration the mouth will be open
const long go = 100;
const long talk = 300;


byte result;
// this turns our command into bytes, so the shield knows what do/
byte temp;
//for debugging.

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button, INPUT);
  result = sd.begin(SD_SEL, SPI_HALF_SPEED);
   result = MP3player.begin();
  myservo.attach(servo);
  Serial.begin(9600); // unsure why the serial is this high
  //tells the shield to boot up

 
  //tells the sheild it's a mp3 player now.

}



/////////////-------------------------/////////////////////




void loop() {
  val = digitalRead(button);
  
 if (timer == ret) {
    x = 0;
    timer = 0;
    pos = 0;
 }
  if ((val == HIGH) && (timer == 0)) {
    x = 1;
  }
  
  myservo.write(pos);

  

  if (x == 1) {
    timer ++;  // the timer begins if the program started. woot.
      delay(10);
  }

  //I have seperated the start times of the audio and the machine. I was having problems with the two processes running at the same time.

  if (timer > go)  { //I took out the second half of the IF statement, since i solved it earlier in the program. 
   // audiostart = 1; // the audio will start if this is true.
   analogWrite(led2, 100);
         result = MP3player.playTrack(1);
          delay (40);
          MP3player.stopTrack();
  }


  if (timer > talk) { //makes the program wait some time before the button makes the mouth move. worth noting, the numbers are different for a reason.
   // servostart = 1; // the mouth will move open
      pos = 100;
    } else {}
}

