//Initial Definitions and Setup
//Libary Inclusion
#include <Joystick.h>

//Define and Allocate Input Pins to memorable names
#define Rudder A0

//Joystick(Joystick HID ID, Joystick Type, Button Count, Hat Switch Count, Include X, Include Y, Include Z,
//Include Rx, Include Ry, Include Rz, Include Rudder, Include Throttle, Include Accelerator, Include Brake, Include Steering

Joystick_ Joystick(0x12, JOYSTICK_TYPE_JOYSTICK, 0, 0,false,false,false,false,false,false,true,false,false,false,false);


const bool initAutoSendState = true;

int rudder_ =0;

void setup() {
  // put your setup code here, to run once:
    Joystick.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  //Axis Runtime
  rudder_ = analogRead(Rudder);
  rudder_ = map(rudder_, 0, 1023, 0, 255);
  Joystick.setRudder(rudder_);

//Pole Delay/Debounce
//To reduce unessecary processing, the frequency of the reading loop is delayed. The value(in ms) can be changed to match requirement
  delay(10);
}
