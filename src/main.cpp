#include <Arduino.h>
#include "/Users/rick/Documents/PlatformIO/Projects/ACreader/src/utilities.cpp"
#include <SPI.h>
#include <SD.h>
#include <time.h>
#define LED_amarillo 3
#define LED_rojo 4
#define LED_verde 5
#define SD_CS_PIN 10
bool resiv_Sig=false;
LEDController led(LED_rojo, LED_verde, LED_amarillo);
File myFile;
bool signal (float(read)) {
    if (read!=0) {
      return true;
    }
    else {
      return false;
    }
  };
void setup() {
  Serial.begin(115200);
  led.begin();
  SD.begin(SD_CS_PIN);
  myFile=SD.open("data.txt", FILE_WRITE);
  if (myFile) {
    Serial.println("File opened successfully");
    //turn on LED?

    //----------
    //write headers
    myFile.println("Voltage,Timestamp ");
    Serial.println("Voltage,Timestamp ");
    myFile.close();

  } else {
    Serial.println("Error opening file");
    myFile.close();
        //----------
        //write headers
  } 
};
void loop(){
  float(read);
  resiv_Sig=signal(read);
  led.updatestate(resiv_Sig);
  led.TURNLED();
  myFile=SD.open("data.txt", FILE_WRITE);
  String message = map(analogRead(A0),0,1023,0,5) + "," + millis();
  Serial.println(message);
  myFile.println(message);
  myFile.close();
  //float voltage= read* (5.0/1023.0);
   
  
  
}