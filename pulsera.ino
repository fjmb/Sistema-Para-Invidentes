#include <Wtv020sd16p.h>

#include <VirtualWire.h>
uint8_t message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
uint8_t messageLength = VW_MAX_MESSAGE_LEN; // the size of the messc
int resetPin = 2;  // The pin number of the reset pin.
int clockPin = 3;  // The pin number of the clock pin.
int dataPin = 4;  // The pin number of the data pin.
int busyPin = 5;  // The pin number of the busy pin.

Wtv020sd16p wtv020sd16p(resetPin, clockPin, dataPin, busyPin);
void setup()
{
  wtv020sd16p.reset();
  vw_setup(2000); // Bits per sec
  vw_set_rx_pin(11);
  vw_rx_start(); // Start the receiver

}
void loop()
{
  if (vw_get_message(message, &messageLength)) // Non-blocking
  {
    char temp = message[0];
    if (temp == 'v') {
      reproducir(1);
    }
    else if (temp == 'a') {
      reproducir(2);
    }
    else if (temp == 'r') {
      reproducir(3);
    }
  }
}
void reproducir(int num) {
  wtv020sd16p.reset();
  wtv020sd16p.playVoice(0);
  wtv020sd16p.asyncPlayVoice(num);
  delay(4000);
  wtv020sd16p.reset();
}



