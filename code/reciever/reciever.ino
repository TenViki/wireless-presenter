#include <Arduino.h>
#include <RH_ASK.h>

#include <Keyboard.h>

RH_ASK driver(4000, 7, 0);

void setup()
{
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);

  Serial.begin(9600);

  if (!driver.init())
    Serial.println("init failed");

  Keyboard.begin();
}

void loop()
{
  // Serial.println(digitalRead(7));
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);
  //     Serial.println("Waiting for message...");

  if (driver.recv(buf, &buflen))
  {
    Serial.println("Got message");
    Serial.println(buf[0]);

    {

      switch (buf[0])
      {

      case '1':
        pressKey(KEY_RIGHT_ARROW);
        break;

      case '2':
        pressKey(KEY_LEFT_ARROW);
        break;

      case '3':
        pressKey(' ');
        break;

      case '4':
        pressKey(KEY_RIGHT_ARROW);
        break;

      case '5':
        pressKey(KEY_LEFT_ARROW);
        break;

      case '6':
        pressKey(KEY_UP_ARROW);
        break;

      case '7':
        pressKey(KEY_DOWN_ARROW);
        break;
      }
    }
  }
}

void pressKey(int key)
{
  Keyboard.write(key);
}