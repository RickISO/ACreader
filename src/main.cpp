#include <Arduino.h>
#include "/Users/rick/Documents/PlatformIO/Projects/ACreader/src/utilities.cpp"
#define LED_amarillo 3
#define LED_rojo 4
#define LED_verde 5
bool laststate = false; // para detectar la caida de la señal senosuidal
float frequency=0.0;
unsigned long lastfall = 0; // para medir el periodo de la señal senosuidal
LEDController leds(LED_rojo, LED_verde, LED_amarillo);


void setup() {
  ADMUX = 0b01100000; //A0 ref de 5V para el sensor, ajustado a 8bits
  ADCSRA= 0b11000111; //Habilita el ADC, sin interrupciones, con prescaler de 128 (divisor de frequencia entre mas bajo mas rapido y menos preciso y mas alto menos lecturas pero menos preciso)
  //modo continuo, sin interrupcion, 
  
  Serial.begin(115200);
  leds.begin();

}
void loop () {
  // iniciar conversión
  ADCSRA |= (1 << ADSC);
  // esperar a que termine
  while (ADCSRA & (1 << ADSC));
  // leer valor (8 bits porque ADLAR=1 y usamos conversion a 8 bits)
  int value = ADCH;
  bool currentstate= (value > 128); // umbral por 8 bits del Adalar 128 es la mitad de lo max leido
  if (currentstate && !laststate) { // detecta la caida de la señal senosuidal
    unsigned long now = micros();
    unsigned long period= now - lastfall; // calcula el periodo en microsegundos
    lastfall=now;
    if (period > 0) {
      frequency = 1000000.0 / period; // calcula la frecuencia en Hz
      }
  }
  laststate = currentstate; // actualiza el estado para la siguiente iteración
  Serial.println(frequency); // imprime la frecuencia en el monitor serial
  leds.updatestate(frequency); // actualiza el estado de los LEDs segun la frecuencia
  leds.TURNLED(); // enciende el LED correspondiente al estado actual
 


  

}