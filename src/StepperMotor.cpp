#include <Arduino.h>

#include "StepperMotor.h"

StepperMotor::StepperMotor(uint8_t dir, uint8_t step, int maxSpeed = 200, int accelTime = 2, uint8_t limitSwitchPin, bool limitSwitchReversed = false, bool limitSwitchPullUp = true)
{
	stepper = AccelStepper(AccelStepper::DRIVER, dir, step);
	stepper.setMaxSpeed(maxSpeed);
	stepper.setAcceleration(maxSpeed / accelTime);	
	limitSwitch = Button(limitSwitchPin, limitSwitchReversed, limitSwitchPullUp);
}

/**
 * Setup the StepperMotor
 */
void StepperMotor::setup()
{
	stepper.move(-10000);
	while (limitSwitch.getValue() == HIGH) {
		stepper1.run();
	}
	stepper.stop();
	stepper.setCurrentPosition(stepper.currentPosition());
	stepper.moveTo(10);
}

void StepperMotor::moveTo(int pos)
{
	stepper.moveTo(pos);
}

void StepperMotor::loop()
{
	stepper.run();
}