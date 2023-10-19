#include <Arduino.h>

#include "StepperMotor.h"

StepperMotor::StepperMotor(uint8_t dir, uint8_t step, uint8_t limitSwitchPin, bool limitSwitchReversed = false, bool limitSwitchPullUp = false)
{
	stepper = AccelStepper(AccelStepper::DRIVER, dir, step);
	limitSwitch = Button(limitSwitchPin, limitSwitchReversed, limitSwitchPullUp);
}

/**
 * Setup the StepperMotor
 */
void StepperMotor::setup()
{
	stepper.setMaxSpeed(200.0);
	stepper.setAcceleration(100.0);
	stepper.moveTo(-1000);
	while (!limitSwitch.getValue())
	{
		stepper.run();
	}
	stepper.stop();
}

void StepperMotor::move(int speed)
{
	if (speed > 0)
	{
		forward(speed);
	}
	if (speed < 0)
	{
		backward(-speed);
	}
}

void StepperMotor::forward(int speed)
{
	
}

void StepperMotor::backward(int speed)
{
	
}

void StepperMotor::loop()
{
	stepper.run();
}