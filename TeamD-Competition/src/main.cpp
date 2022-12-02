#include "vex.h"

#include "math.h"

using namespace vex;

competition Competition;

motor frontRight = motor(PORT1, gearSetting::ratio18_1, true);
motor backRight = motor(PORT2, gearSetting::ratio18_1, true);
motor_group rightDrive = motor_group(frontRight, backRight);

motor frontLeft = motor(PORT10, gearSetting::ratio18_1);
motor backLeft = motor(PORT9, gearSetting::ratio18_1);
motor_group leftDrive = motor_group(frontLeft, backLeft);

drivetrain drive = drivetrain(leftDrive, rightDrive, 4.125 * M_PI, 14.25, 12.0, distanceUnits::in);

controller control = controller(controllerType::primary);

void pre_auton(void) {

}

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

void usercontrol(void) {
  while (true) {
    drive.arcade(control.Axis3.position(), control.Axis1.position());
    wait(20, msec);
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
