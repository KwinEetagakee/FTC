/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Left                 rotation      5               
// Right                rotation      8               
// LB                   motor         1               
// LF                   motor         10              
// RB                   motor         11              
// RF                   motor         14              
// Inertial             inertial      3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "functions.h"
#include "pid.h"
#include "odometry.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  
  recal();
  // ..........................................................................
  // Insert autonomous user code here.
  // .........................................................................
  for(int i = 0; i < 8; i++) {
    drivePID(10, 0.025, 8, 0, 170);
    turnPID(87, 0.1, 1, 0.000, 0);
    drivePID(10, 0.025, 8, 0, 170);
    turnPID(-87, 0.1, 1, 0.000, 0);
    recal();
  }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  Left.resetPosition();
  Right.resetPosition();
  recal();
  while (1) {
    calloc();
    LB.spin(forward, Controller1.Axis3.value(), percent);
    LF.spin(forward, Controller1.Axis3.value(), percent);
    RB.spin(forward, Controller1.Axis2.value(), percent);
    RF.spin(forward, Controller1.Axis2.value(), percent);

    double rth = r2h();

    if(Controller1.ButtonA.pressing()){
      turnPID(0, 0.1, 0.5, 0, 25);
    }
    if(Controller1.ButtonB.pressing()){
      recal();
      Left.resetPosition();
      Right.resetPosition();
    }
    if(Controller1.ButtonY.pressing()){
      returnHome(0.25, rth);
    }
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

//printf("%d", int);
//printf("%f", double);
//printf("%d, %f", int, double);