#include <Arduino.h>
#include "/Users/rick/Documents/PlatformIO/Projects/ACreader/src/utilities.cpp"
#define LED_amarillo 3
#define LED_rojo 4
#define LED_verde 5
void setup() {
  ADMUX = 0b01100000; //A0 ref de 5V para el sensor, ajustado a 8bits
  ADCSRA= 0b11000111; //Habilita el ADC, sin interrupciones, con prescaler de 128 (divisor de frequencia entre mas bajo mas rapido y menos preciso y mas alto menos lecturas pero menos preciso)
  //modo continuo, sin interrupcion, 
  
  Serial.begin(115200);

}
void loop () {
  // iniciar conversión
  ADCSRA |= (1 << ADSC);
  // esperar a que termine
  while (ADCSRA & (1 << ADSC));
  // leer valor (8 bits porque ADLAR=1 y usamos conversion a 8 bits)
  int value = ADCH;
  float frequency ;


  

}