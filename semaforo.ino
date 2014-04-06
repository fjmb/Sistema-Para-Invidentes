#include <VirtualWire.h>

const int verde = 2; 
const int amarillo = 3;
const int rojo = 4; 

void setup() {
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);
  vw_setup(2000); // Bits per sec
  vw_set_tx_pin(12);                // pin 3 is used as the transmit data out into the TX Link module, change this as per your needs
}
void loop() {
  send("v");
  activo(verde, 10000); //36 seg
  parpadeo(verde);
  parpadeo(verde);
  parpadeo(verde);
  parpadeo(verde);
  send("a");
  activo(amarillo, 3000);//3 seg
  send("r");
  activo(rojo, 10000);//40 sg
}
void parpadeo(int pin) {
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
  delay(500);
}
void activo(int pin, int tiempo) {
  digitalWrite(pin, HIGH);
  delay(tiempo);
  digitalWrite(pin, LOW);
  delay(500);
}
void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
}

