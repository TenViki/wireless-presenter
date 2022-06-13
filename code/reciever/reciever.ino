#include <Arduino.h>
#include <VirtualWire.h>
#include <Keyboard.h>

void setup()
{
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);

  // pinMode(7, INPUT);

  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(7);
  vw_setup(4000); // Bits per sec
  vw_rx_start();  // Start the receiver PLL running

  Serial.begin(9600);
}

void loop()
{
  // Serial.println(digitalRead(7));
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  // Serial.println("Waiting for message...");

  if (vw_get_message(buf, &buflen))
  {
    if (buf[0] == '1')
    {
      pressKey(KEY_RIGHT_ARROW);
    }
    if (buf[0] == '2')
    {
      pressKey(KEY_LEFT_ARROW);
    }
  }
}

void pressKey(int key)
{
  Keyboard.press(key);
  delay(10);
  Keyboard.release(key);
}