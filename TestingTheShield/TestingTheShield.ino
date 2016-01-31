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

byte temp;
byte result;

int tim = 0;
int go = 110;
int ret = 5000;
  char trackName[] = "track001.mp3";


void setup() {
  // put your setup code here, to run once:

 Serial.begin(115200);
  
   result = sd.begin(SD_SEL, SPI_HALF_SPEED);
  
  //boot up the MP3 Player Shield
  result = MP3player.begin();
  //check result, see readme for error codes.
  if(result != 0) {
    Serial.print("Error code: ");
    Serial.print(result);
    Serial.println(" when trying to start MP3 player");
    

    }


}

void loop() {


while(tim < ret){
  tim ++;
}

if (tim > go){
result = MP3player.playTrack(1); 
//Picks first file from directory.  dont actually put file name. The program wiggs out. 

delay(8000);

Serial.write(tim);

} else {}
  if (tim == ret){
    MP3player.stopTrack();
    tim = 0;
    
  }else {
}

  
  // put your main code here, to run repeatedly:

}
