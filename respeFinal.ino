#include <Wtv020sd16p.h>

#include <VirtualWire.h>
uint8_t message[VW_MAX_MESSAGE_LEN];
uint8_t messageLength = VW_MAX_MESSAGE_LEN;
int resetPin = 2;  // The pin number of the reset pin.
int clockPin = 3;  // The pin number of the clock pin.
int dataPin = 4;  // The pin number of the data pin.
int busyPin = 5;  // The pin number of the busy pin.
int uno=6;
int dos=7;
int tres=8;
int cuatro=9;
int cinco=10;
int seis=12;
int siete=13;

Wtv020sd16p wtv020sd16p(resetPin, clockPin, dataPin, busyPin);
void setup()
{
  pinMode(uno,OUTPUT);
  pinMode(dos,OUTPUT);
  
  pinMode(tres,OUTPUT);
  pinMode(cuatro,OUTPUT);
  pinMode(cinco,OUTPUT);
  pinMode(seis,OUTPUT);
  pinMode(siete,OUTPUT);
  wtv020sd16p.reset();
  vw_setup(2000);
  vw_set_rx_pin(11);
  vw_rx_start();
  //Serial.begin(9600);
}
void loop()
{

  if (vw_get_message(message, &messageLength))
  {

    char temp = message[0];
    if (temp == '1') {
      //Serial.print("1");
      reproducir(1,uno);
    }
    else if (temp == '2') {
      //Serial.print("2");
      reproducir(2,dos);
    }
    else if (temp == '3') {
    //  Serial.print("3");
      reproducir(3,tres);
    }
    else if (temp == '4') {
     // Serial.print("4");
      reproducir(4,cuatro);
    }
    else if (temp == '5') {
    //  Serial.print("5");
      reproducir(5,cinco);
    }
    else if (temp == '6') {
     // Serial.print("6");
      reproducir(6,seis);
    }
    else if (temp == '7') {
      //Serial.print("7");
      reproducir(7,siete);
    }

  }
}
void reproducir(int num,int led) {
  digitalWrite(led,HIGH);
  wtv020sd16p.reset();
  wtv020sd16p.playVoice(0);
  wtv020sd16p.asyncPlayVoice(num);
  delay(4000);
  digitalWrite(led,LOW);
  wtv020sd16p.reset();
}
