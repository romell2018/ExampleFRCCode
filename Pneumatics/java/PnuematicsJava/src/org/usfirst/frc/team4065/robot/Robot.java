/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package org.usfirst.frc.team4065.robot;

import edu.wpi.first.wpilibj.IterativeRobot;
import edu.wpi.first.wpilibj.Joystick;
import edu.wpi.first.wpilibj.Compressor;
import edu.wpi.first.wpilibj.DoubleSolenoid;

public class Robot extends IterativeRobot {

	private Joystick joystick;
	private DoubleSolenoid solenoid;
	private Compressor compressor;
	
	@Override
	public void robotInit() {
		joystick = new Joystick(0);
		solenoid = new DoubleSolenoid(0,1);
		compressor = new Compressor();
		compressor.start();
		compressor.setClosedLoopControl(true);
	}

	@Override
	public void teleopPeriodic() {
		if(joystick.getRawButton(5))
			 
		 {
			 solenoid.set(DoubleSolenoid.Value.kForward);//air goes thru tube 1
		 }else if(joystick.getRawButton(6))
		 {
			 solenoid.set(DoubleSolenoid.Value.kReverse);//air goes thru tube 2
			 
		 }else{
			 solenoid.set(DoubleSolenoid.Value.kOff);
		 }
	}

}
