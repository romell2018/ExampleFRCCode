/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
//test
#pragma once

#include <string>
#include <cstdlib>
#include <ctre/phoenix.h>
#include <WPILib.h>

#include <IterativeRobot.h>
#include <SmartDashboard/SendableChooser.h>

class Robot : public frc::IterativeRobot {
public:
	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

private:
	// Declaration
	Joystick *joystick;
	TalonSRX *FL, *FR;// frontLeftMotor,frontRightMotor using joysticks axis
	TalonSRX *joyButton;// if joystick button is pressed use motor
};
