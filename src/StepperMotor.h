#include <Arduino.h>

#include <AccelStepper.h>
#include <Button.h>

class StepperMotor
{
    public:
        StepperMotor(uint8_t dir, uint8_t step, uint8_t limitSwitchPin, bool limitSwitchReversed = false, bool limitSwitchPullUp = false);
        void setup();
        void move(int speed);
        void forward(int speed);
        void backward(int speed);
        void loop();
        AccelStepper stepper = AccelStepper(AccelStepper::DRIVER, 0, 0);
        Button limitSwitch = Button(0);
};
