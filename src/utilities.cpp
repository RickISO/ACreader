#include <Arduino.h>
#ifndef UTILITIES_H
#define UTILITIES_H


class LEDController {
    public:
    enum Gridstate {
        Nosignal, //red
        Abnormal, //yellow
        Normal, //green
    };
  private:
    int redPin;
    int greenPin;
    int yellowPin;
    int SD_CS_PIN;
    Gridstate state;
  
  public:
    LEDController(int r, int g, int y) {
      redPin = r;
      greenPin = g;
      yellowPin = y;
    }
    void begin() {
      pinMode(redPin, OUTPUT);
      pinMode(greenPin, OUTPUT);
      pinMode(yellowPin, OUTPUT);
    }
    void updatestate(bool signal) {
        Gridstate state;
      if (signal == false) {
        state = Nosignal;
      }
     /* else if () {
        state = Abnormal;
      } */
      else if (signal == true) {
        state = Normal;
      }
    }
    void TURNLED (){
        if (state == Nosignal){
            digitalWrite(redPin, HIGH);
            digitalWrite(greenPin, LOW);
            digitalWrite(yellowPin, LOW);
        }
        else if (state==Abnormal){
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(yellowPin, HIGH);
        }
        else if (state == Normal){
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, HIGH);
            digitalWrite(yellowPin, LOW);
        }

    }
};
#endif