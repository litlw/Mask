
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

char title[10];
char result;
int myPins[6] = {1, 10, 5, 4, 3, 2}; // these pins work with the shield in use
int button = myPins[1]; // teh button
//char temp = "no"; // this is placeholder of the name of the track

long timer = 0; //keeping track of time
const long ret = 119;    //difference between ret and go is duration the mouth will be open
const long go = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  result = sd.begin(SD_SEL, SPI_HALF_SPEED);
  result = MP3player.begin();

  if(result != 0) {
    Serial.print("Error code: ");
    Serial.print(result);
    Serial.println(" when trying to start MP3 player");
    }

  Serial.println("Hello");
//  temp = "no.wav";

}

void loop() {
  char track[] = "no.wav";
if ((timer < ret)){
  timer ++;
}else if(timer < ret && timer == go){
  timer ++;
  MP3player.playMP3(track);
  delay (100);
  //MP3player.stopTrack(track);
} else {
  timer = 0;
}
  
  // put your main code here, to run repeatedly:

}
