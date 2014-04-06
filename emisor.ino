#include <VirtualWire.h>
const int uno = 2;
const int dos = 3;
const int tres = 4;

void setup()
{
  pinMode(uno, INPUT);
  pinMode(dos, INPUT);
  pinMode(tres, INPUT);
  vw_setup(2000);
  vw_set_tx_pin(12);
  //Serial.begin(9600);
}
void loop()
{
  if (digitalRead(uno) == LOW && digitalRead(dos) == LOW && digitalRead(tres) == LOW)
  {
    send("1");
    //Serial.print("1");
  }
  else if (digitalRead(uno) == LOW && digitalRead(dos) == LOW && digitalRead(tres) == HIGH)
  {
    send("2");
   // Serial.print("2");
  }
  else if (digitalRead(uno) == LOW && digitalRead(dos) == HIGH && digitalRead(tres) == LOW)
  {
    send("3");
    //Serial.print("3");
  }
  else if (digitalRead(uno) == LOW && digitalRead(dos) == HIGH && digitalRead(tres) == HIGH)
  {
    send("4");
    //Serial.print("4");
  }
  else if (digitalRead(uno) == HIGH && digitalRead(dos) == LOW && digitalRead(tres) == LOW)
  {
    send("5");
    //Serial.print("5");
  }
  else if (digitalRead(uno) == HIGH && digitalRead(dos) == LOW && digitalRead(tres) == HIGH)
  {
    send("6");
   // Serial.print("6");
  }
  else if (digitalRead(uno) == HIGH && digitalRead(dos) == HIGH && digitalRead(tres) == LOW)
  {
    send("7");
    //Serial.print("7");
  }

}

void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx();
}

