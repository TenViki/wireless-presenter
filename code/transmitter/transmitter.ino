#include <Arduino.h>
#include <VirtualWire.h>

void setup()
{

  vw_set_ptt_inverted(true);
  vw_set_tx_pin(3);
  vw_setup(4000); // speed of data transfer Kbps

  pinMode(10, OUTPUT);
  pinMode(15, INPUT);
  Serial.begin(9600);
}

boolean state = false;

void loop()
{
  // put your main code here, to run repeatedly:
  // controller = "1";
  // vw_send((uint8_t *)controller, strlen(controller));
  // vw_wait_tx(); // Wait until the whole message is gone
  // digitalWrite(10, 1);
  // // digitalWrite(3, 1);

  // delay(500);
  // controller = "0";
  // vw_send((uint8_t *)controller, strlen(controller));
  // vw_wait_tx(); // Wait until the whole message is gone
  // digitalWrite(10, 0);
  // // digitalWrite(3, 0);
  // delay(500);

  if (digitalRead(15) && !state)
  {
    state = true;
    digitalWrite(10, 1);
    Serial.println("Sending!!!");
    sendMessage("1");
  }

  if (!digitalRead(15) && state)
  {
    state = false;
    digitalWrite(10, 0);
    // controller = "Off";
    // vw_send((uint8_t *)controller, strlen(controller));
  }
}

void sendMessage(char *msg)
{
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx(); // Wait until the whole message is gone
}