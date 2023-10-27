#include <Arduino.h>

#include <AccelStepper.h>
#include <Button.h>

class StepperMotor
{
    public:
        StepperMotor(uint8_t dir, uint8_t step, int maxSpeed = 200, int accelTime = 2, uint8_t limitSwitchPin, bool limitSwitchReversed = false, bool limitSwitchPullUp = true);
        void setup();
        void moveTo(int pos);
        void loop();
        AccelStepper stepper = AccelStepper(AccelStepper::DRIVER, 0, 0);
        Button limitSwitch = Button(0);
};
