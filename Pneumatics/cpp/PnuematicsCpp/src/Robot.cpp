/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>
#include <WPILib.h>

void Robot::RobotInit() {
	joystick = new Joystick(0);
	solenoid = new DoubleSolenoid(0, 1);
	compressor = new Compressor();
	compressor.Start();
	compressor.SetClosedLoopControl(true);

}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() {
	if (joystick.GetRawButton(5))

	{
		solenoid.Set(DoubleSolenoid::Value::kForward); //air goes thru tube 1
	} else if (joystick.getRawButton(6)) {
		solenoid.Set(DoubleSolenoid::Value::kReverse); //air goes thru tube 2

	} else {
		solenoid.Set(DoubleSolenoid::Value::kOff);
	}

}

START_ROBOT_CLASS(Robot)
