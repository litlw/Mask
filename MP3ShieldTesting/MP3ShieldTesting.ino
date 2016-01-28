
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
int myPins[5] = {1, 10, 5, 4, 3, 2};
int button = myPins[1];
int temp;


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

}

void loop() {
  // put your main code here, to run repeatedly:

}
