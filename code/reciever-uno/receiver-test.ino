#include <Arduino.h>
#include <VirtualWire.h>

void setup()
{
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(8);
  vw_setup(4000); // Bits per sec
  vw_rx_start();  // Start the receiver PLL running
  // pinMode(0, INPUT);
  // pinMode(1, INPUT);
  // pinMode(2, INPUT);
  Serial.begin(9600);
  // pinMode(8, INPUT);
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  // Serial.println("Waiting for message...");
  if (vw_get_message(buf, &buflen))
  {
    Serial.println(buf[0]);

    for (int i = 0; i < buflen; i++)
    {
      char c = buf[i];
      Serial.print(c);
      Serial.print(" ");
    }

    Serial.println();

    // if (buf[0] == '1')
    // {
    //   DigiKeyboard.sendKeyStroke(KEY_0);
    // }
    // if (buf[0] == '0')
    // {
    //   DigiKeyboard.sendKeyStroke(KEY_1);
    // }
  }

  // delay(1000);
  // // DigiKeyboard.sendKeyStroke(KEY_A);

  // Serial.println(digitalRead(8));
}