#include <Arduino.h>

#include <AccelStepper.h>
#include <Button.h>

class StepperMotor
{
    public:
        StepperMotor(int step, int dir, int maxSpeed = 200, int accelTime = 2);
        StepperMotor(int step, int dir, int limitSwitchPin, bool limitSwitchReversed = false, bool limitSwitchPullUp = true, int maxSpeed = 200, int accelTime = 2);
        StepperMotor(int step, int dir, int limitSwitchPin, bool limitSwitchReversed = false, bool limitSwitchPullUp = true, int limitSwitchPin2 = 0, bool limitSwitchReversed2 = false, bool limitSwitchPullUp2 = true, int maxSpeed = 200, int accelTime = 2);
        void setup();
        void moveTo(int pos);
        void loop();
        AccelStepper stepper = AccelStepper(AccelStepper::DRIVER, 0, 0);
        Button limitSwitch = Button(0);
        Button limitSwitch2 = Button(0);
};
