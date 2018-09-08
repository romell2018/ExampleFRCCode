/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package org.usfirst.frc.team4065.robot;

import edu.wpi.first.wpilibj.IterativeRobot;

import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.can.TalonSRX;
import edu.wpi.first.wpilibj.*;

//https://github.com/romell2018/exampleFRCcode.git

public class Robot extends IterativeRobot {
	/*
	 * The typical Game Controller has the following features: 2 joysticks - left
	 * and right 4 primary or face buttons on the right hand 2 or 3 game mode
	 * buttons in the center (back, start) left and right bumper buttons left and
	 * right analog triggers Point of View (POV) rocker control or D-pad
	 */

	// Declaration
	private Joystick joystick;
	private TalonSRX FL, FR;// frontLeftMotor,frontRightMotor using joysticks axis
	private TalonSRX joyButton;// if joystick button is pressed use motor

	@Override
	public void robotInit() {
		// Initialize
		joystick = new Joystick(0);// Input 0
		FL = new TalonSRX(0);// Talon ID[?]
		FR = new TalonSRX(0);// Talon ID[?]
		joyButton = new TalonSRX(0);// Talon ID[?]
	}

	@Override
	public void teleopPeriodic() {

		// Get Speed and Turn
		double left = -1 * joystick.getRawAxis(1);// inverts left side as going forward requires a negative value on one
													// side and positive on the other
		double right = joystick.getRawAxis(4);

		// takes absolute value to make calculations easier.
		if (Math.abs(left) > 0.1 || Math.abs(right) > 0.1) {

			// sets motors to values of joysticks
			FL.set(ControlMode.PercentOutput, left);
			FR.set(ControlMode.PercentOutput, left);
			FL.set(ControlMode.PercentOutput, right);
			FR.set(ControlMode.PercentOutput, right);
		} else {
			FL.set(ControlMode.PercentOutput, 0);
			FR.set(ControlMode.PercentOutput, 0);

		}

		// Button
		if (joystick.getRawButton(1)) {// if button [1] is pressed

			joyButton.set(ControlMode.PercentOutput, 0.3);// forward motor

		} else if (joystick.getRawButton(2)) {// if button [2] is pressed

			joyButton.set(ControlMode.PercentOutput, -0.3);// reverse motor

		} else {// if not pressed

			joyButton.set(ControlMode.PercentOutput, 0.0);// stop
		}

		// D-pad
		if (joystick.getPOV() == 90) {

			System.out.println("POV = 90");

		} else if (joystick.getPOV() == -90) {

			System.out.println("POV = -90");

		} else if (joystick.getPOV() == 180) {

			System.out.println("POV = 180");

		} else {

			System.out.println("POV = 0");
		}
	}
}
