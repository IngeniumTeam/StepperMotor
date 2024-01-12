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

// StepperMotor::StepperMotor(int step, int dir, int limitSwitchPin, bool limitSwitchReversed = false, bool limitSwitchPullUp = true, int limitSwitchPin2, bool limitSwitchReversed2 = false, bool limitSwitchPullUp2 = true, int maxSpeed = 200, int accelTime = 2)
// {
// 	limitSwitch = Button(limitSwitchPin, limitSwitchReversed, limitSwitchPullUp);
// 	limitSwitch2 = Button(limitSwitchPin2, limitSwitchReversed2, limitSwitchPullUp2);
// 	StepperMotor(dir, step, maxSpeed, accelTime);
// }

/**
 * Setup the StepperMotor
 */
void StepperMotor::setup()
{
	stepper.move(-10000);
	while (limitSwitch.getValue() != HIGH) {
		stepper.setSpeed(-100);
		stepper.runSpeed();
	}
	stepper.stop();
	while (limitSwitch.getValue() != LOW) {
		stepper.setSpeed(75);
		stepper.runSpeed();
	}
	delay(10);
	stepper.stop();
	stepper.setCurrentPosition(stepper.currentPosition());
}

void StepperMotor::moveTo(int pos)
{
	stepper.moveTo(pos);
}

void StepperMotor::loop()
{
	// Serial.print(limitSwitch.getValue());
	// Serial.print(" ");
	// Serial.println(limitSwitch2.getValue());
	if (limitSwitch.getValue() == LOW) {
	// if (limitSwitch.getValue() + limitSwitch2.getValue() == LOW) {
		stepper.run();
	}
	else {
		stepper.stop();
	}
}