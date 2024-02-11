#include <Arduino.h>

#include "StepperMotor.h"

StepperMotor::StepperMotor(int step, int dir, int maxSpeed = 200, int accelTime = 2)
{
	stepper = AccelStepper(AccelStepper::DRIVER, step, dir);
	stepper.setMaxSpeed(maxSpeed);
	stepper.setAcceleration(maxSpeed / accelTime);	
}

StepperMotor::StepperMotor(int step, int dir, int limitSwitchPin, bool limitSwitchReversed = false, bool limitSwitchPullUp = true, int maxSpeed = 200, int accelTime = 2)
{
	stepper = AccelStepper(AccelStepper::DRIVER, step, dir);
	stepper.setMaxSpeed(maxSpeed);
	stepper.setAcceleration(maxSpeed / accelTime);
	limitSwitch = Button(limitSwitchPin, limitSwitchReversed, limitSwitchPullUp);
	// StepperMotor(step, dir, maxSpeed, accelTime);
}

StepperMotor::StepperMotor(int step, int dir, int limitSwitchPin, bool limitSwitchReversed = false, bool limitSwitchPullUp = true, int limitSwitchPin2, bool limitSwitchReversed2 = false, bool limitSwitchPullUp2 = true, int maxSpeed = 200, int accelTime = 2)
{
	stepper = AccelStepper(AccelStepper::DRIVER, step, dir);
	stepper.setMaxSpeed(maxSpeed);
	stepper.setAcceleration(maxSpeed / accelTime);
	limitSwitch = Button(limitSwitchPin, limitSwitchReversed, limitSwitchPullUp);
	limitSwitch2 = Button(limitSwitchPin2, limitSwitchReversed2, limitSwitchPullUp2);
}

/**
 * Setup the StepperMotor
 */
void StepperMotor::setup()
{
	while (limitSwitch.getValue() != HIGH) {
		stepper.setSpeed(-100);
		stepper.runSpeed();
	}
	stepper.stop();
	while (limitSwitch.getValue() != LOW) {
		stepper.setSpeed(75);
		stepper.runSpeed();
	}
	delay(15);
	stepper.stop();
	stepper.setCurrentPosition(0);
}

void StepperMotor::moveTo(int pos)
{
	stepper.moveTo(pos);
	while (stepper.distanceToGo() != 0)
	{
		loop();
	}
}

void StepperMotor::loop()
{
	if (limitSwitch.getValue() == LOW) {
		stepper.run();
	}
	else {
		stepper.stop();
	}
}