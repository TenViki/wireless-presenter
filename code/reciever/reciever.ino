#include <Arduino.h>
#include <VirtualWire.h>

void setup()
{
  pinMode(1, OUTPUT);
  digitalWrite(1, HIGH);

  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(PIN0);
  vw_setup(4000); // Bits per sec
  vw_rx_start();  // Start the receiver PLL running

  // DigiKeyboard.update();
  // DigiKeyboard.delay(5000);
}

void loop()
{

  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen))
  {
    if (buf[0] == '1')
    {
      DigiKeyboard.sendKeyStroke(KEY_RIGHT_ARROW);
    }
    if (buf[0] == '2')
    {
      DigiKeyboard.sendKeyStroke(KEY_LEFT_ARROW);
    }
  }
}