/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>
#include <Phoenix.h>
#include <WPILib.h>
using namespace ctre::phoenix::motorcontrol::can;

/*
 * The typical Game Controller has the following features: 2 joysticks - left
 * and right 4 primary or face buttons on the right hand 2 or 3 game mode
 * buttons in the center (back, start) left and right bumper buttons left and
 * right analog triggers Point of View (POV) rocker control or D-pad
 */
//test

void Robot::RobotInit() {
	joystick = new Joystick(0); // Input 0
	FL = new TalonSRX(0); // Talon ID[?]
	FR = new TalonSRX(0); // Talon ID[?]
	joyButton = new TalonSRX(0); // Talon ID[?]

}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() {
	// Get Speed and Turn
	double left = -1 * joystick->GetRawAxis(1); // inverts left side as going forward requires a negative value on one
												// side and positive on the other
	double right = joystick->GetRawAxis(5);

	// takes absolute value to make calculations easier.
	if (fabs(left) > 0.1 || fabs(right) > 0.1) {
		// sets motors to values of joysticks
		FL->Set(ControlMode::PercentOutput, left);
		FR->set(ControlMode::PercentOutput, left);
		FL->set(ControlMode::PercentOutput, right);
		FR->set(ControlMode::PercentOutput, right);
	} else {
		FL->set(ControlMode::PercentOutput, 0);
		FR->set(ControlMode::PercentOutput, 0);

	}

	// Button
	if (joystick.GetRawButton(1)) {				// if button [1] is pressed

		joyButton.Set(ControlMode.PercentOutput, 0.3);		// forward motor

	} else if (joystick.GetRawButton(2)) {			// if button [2] is pressed

		joyButton->Set(ControlMode::PercentOutput, -0.3);		// reverse motor

	} else {												// if not pressed

		joyButton->Set(ControlMode::PercentOutput, 0.0);				// stop
	}

	// D-pad
	if (joystick.GetPOV() == 90) {

		System.out.println("POV = 90");

	} else if (joystick.GetPOV() == -90) {

		System.out.println("POV = -90");

	} else if (joystick.GetPOV() == 180) {

		System.out.println("POV = 180");

	} else {

		System.out.println("POV = 0");
	}
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot)
