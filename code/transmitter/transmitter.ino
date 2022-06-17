#include <Arduino.h>
#include <RH_ASK.h>

#define circuit_C1 INPUT

#define debounce 10
#define switched true
#define button_switch 1
#define toggle_switch 2
#define num_switches 7

#define TX_PIN 2

#define button_prev 8
#define button_next 9
#define button_center 3
#define button_right 6
#define button_left 4
#define button_up 7
#define button_down 5

RH_ASK driver(4000, 0, TX_PIN);

void setup()
{
  pinMode(button_left, INPUT);
  pinMode(button_right, INPUT);
  pinMode(button_up, INPUT);
  pinMode(button_down, INPUT);
  pinMode(button_center, INPUT);

  Serial.begin(9600);

  if (!driver.init())
    Serial.println("init failed");
}

bool state0 = false;
bool state1 = false;
bool state2 = false;
bool state3 = false;
bool state4 = false;

void loop()
{

  if (digitalRead(button_left) && !state0)
  {
    state0 = true;
    sendMessage("5");
    delay(100);
  }
  else if (!digitalRead(button_left) && state0)
    state0 = false;

  if (digitalRead(button_right) && !state1)
  {
    state1 = true;
    sendMessage("4");
    delay(100);
    Serial.println("Button right");
  }

  else if (!digitalRead(button_right) && state1)
    state1 = false;

  if (digitalRead(button_up) && !state2)
  {
    state2 = true;
    sendMessage("6");
    delay(100);
  }

  else if (!digitalRead(button_up) && state2)
    state2 = false;

  if (digitalRead(button_down) && !state3)
  {
    state3 = true;
    sendMessage("7");
    delay(100);
  }

  else if (!digitalRead(button_down) && state3)
    state3 = false;

  if (digitalRead(button_center) && !state4)
  {
    state4 = true;
    sendMessage("3");
    delay(100);
  }

  else if (!digitalRead(button_center) && state4)
    state4 = false;

  // for (int sw = 0; sw < num_switches; sw++)
  // {
  //   Serial.print(switches[sw].switch_pin);
  //   Serial.print(" ");
  //   Serial.println(digitalRead(switches[sw].switch_pin));

  //   if (read_switch(sw) == switched)
  //   {
  //     // this switch (sw) has been pressed, so process via a case switch
  //     Serial.print("\nbutton switch ");
  //     Serial.print(sw + 1);
  //     Serial.print(" on digital pin ");
  //     byte button_pin = switches[sw].switch_pin;
  //     Serial.println(button_pin);
  //     // move to switch's associated code section
  //     switch (button_pin)
  //     {
  //     case button_next:
  //       // sendMessage("1");
  //       break;
  //     case button_prev:
  //       // sendMessage("2");
  //       break;
  //     case button_center:
  //       sendMessage("3");
  //       break;
  //     case button_right:
  //       sendMessage("4");
  //       break;
  //     case button_left:
  //       sendMessage("5");
  //       break;
  //     case button_up:
  //       sendMessage("6");
  //       break;
  //     case button_down:
  //       sendMessage("7");
  //       break;
  //     default:
  //       // spurious switch index!  Should never arise as this is controlled
  //       // by the for loop within defined upper bound
  //       break;
  //     }

  //     Serial.flush(); // flush out the output buffer
  //     break;
  //   }
  // }
  // pollng of the switches now complete until next cycle, so do other things here as required...
}

void sendMessage(char *msg)
{
  Serial.println("Sending");
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  Serial.println("Sent");
}