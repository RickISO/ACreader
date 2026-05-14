#include <Arduino.h>
#include "/Users/rick/Documents/PlatformIO/Projects/ACreader/src/utilities.cpp"
#define LED_amarillo 3
#define LED_rojo 4
#define LED_verde 5


void setup() {

  Serial.begin(115200);

  // ---------- ADC CONFIG ----------

  ADMUX = 0b01100000;
  // REFS0 = 1 -> referencia AVcc (5V)
  // ADLAR = 1 -> resultado ajustado a izquierda
  // MUX = 0000 -> A0

  ADCSRA = 0b11100111;
  // ADEN  = 1 -> habilita ADC
  // ADSC  = 1 -> inicia conversion
  // ADATE = 1 -> modo free running
  // prescaler 128

  ADCSRB = 0b00000000;
  // free running mode

  DIDR0 = 0b00000001;
  // deshabilita entrada digital en A0
}

void loop() {

  while (!(ADCSRA & (1 << ADIF)));
  // espera conversión

  ADCSRA |= (1 << ADIF);
  // limpia bandera

  uint8_t value = ADCH;

  unsigned long t = micros();

  // CSV falta indegrar
  Serial.print(t);
  Serial.print(",");
  Serial.println(value);
}