#pragma config(Motor,  port2,           RightMotor,    tmotorServoContinuousRotation, openLoop, driveRight)
#pragma config(Motor,  port3,           LeftMotor,     tmotorServoContinuousRotation, openLoop, driveLeft)
#pragma config(Motor,  port4,           CanMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           MannequinServoLeft, tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           MannequinServoRight, tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
	* TO-DO:
	* - button map
	* - fix arm toggle issues
	* - modify tank drive toggle to one button
	*/


task main() {
	// boolean variable to control the tank drive state
	bool forward = true;
	bool armUp = true;

	while (true) {

		// controls the paint can apparatus
		if (vexRT[Btn6U]){
			motor[CanMotor] = 127; // pull in paint cans
		}
		else if (vexRT[Btn6D]){
			motor[CanMotor] = -127; // push cans back out
		}
		else {
			motor[CanMotor] = 0; // sets motor to neutral state
		}

		// sets tank drive state
		if (vexRT[Btn7U]){
			forward = true; // forward state
		}
		else if (vexRT[Btn7D]){
			forward = false; // backward state
		}

		// control tank drive
		if (forward){
			// drive forward with full power on both motors
			motor[RightMotor] = vexRT[Ch2];
			motor[LeftMotor] = vexRT[Ch3];
		}
		else {
			// drive reverse with full power on both motors;
			motor[RightMotor] = -1 * vexRT[Ch3];
			motor[LeftMotor] = -1 * vexRT[Ch2];
		}

		// mannequin arm controls
		// non-inverted controls: U -> raises the arm
		// 										D -> lowers the arm
		if (vexRT[Btn5U]) {
			// set both servos to full power forward
			motor[MannequinServoRight] = 127;
			motor[MannequinServoLeft] = 127;
		}
		else if (vexRT[Btn5D]) {
			// set both servos to full power reverse
			motor[MannequinServoRight] = -127;
			motor[MannequinServoLeft] = -127;
		}
		else {
			// set both servos to neutral
			// default state is full up
			motor[MannequinServoRight] = 127;
			motor[MannequinServoLeft] = 127;
		}
	}
}
