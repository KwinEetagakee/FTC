#include <vex.h>
#include <odometry.h>

  void recal() {
    Inertial.calibrate();
    while (Inertial.isCalibrating())
    {
      wait(3,sec);
    }  
  }

void drivePID(double setpoint, double err, double kp, double ki, double kd) {
  Left.resetPosition();
  Right.resetPosition();
  double r1 = Left.position(turns);
  double r2 = Right.position(turns);
  double avg = (r1 + r2)/2;

  double inches = M_PI * 3.25 * avg;

  double vel = 0;

  double error = setpoint - inches;

  double totalerror = error;

  double integral = 0;

  double preverr = 0;
  
  double deriv = 0;

  while(fabs(error) > err) {

    integral = totalerror;

    deriv = error-preverr;

    vel = error*kp+integral*ki+deriv*kd;

    if((vel<5)&&(vel>0)) {
      vel=2.5;
    }

    if((vel<-5)&&(vel<0)) {
      vel=-2.5;
    }

    LB.spin(forward, vel, percent);
    LF.spin(forward, vel, percent);
    RB.spin(forward, vel, percent);
    RF.spin(forward, vel, percent);

    r1 = Left.position(turns);
    r2 = Right.position(turns);
    avg = (r1 + r2)/2;

    inches = M_PI * 3.25 * avg;

    error = setpoint - inches;

    preverr = error;

    totalerror+=error;

    printf("Error: %f ", error);
    printf("    Traveled: %f ", inches);
    printf("    Intelgral: %f ", integral);
    printf("    IC: %f ", integral*ki);
    printf("    Velocity: %f \n", vel);
  }
  LB.stop();
  LF.stop();
  RB.stop();
  RF.stop();
}

void turnPID(double setpoint, double err, double kp, double ki, double kd) {

  Brain.Timer.reset();

  double avg = callocturn();
  avg = avg+Inertial.heading(degrees);

  if (avg > 180) {
    avg -= 360;
  }

  double vel = 0;

  double error = setpoint - avg;

  double totalerror = error;

  double integral = 0;

  double preverr = 0;
  
  double deriv = 0;

  while(fabs(error) > err) {

    integral = totalerror;

    deriv = error-preverr;

    vel = error*kp+integral*ki+deriv*kd;

    if((vel<5)&&(vel>0)) {
      vel=2.5;
    }

    else if((vel>(0-5))&&(vel<0)) {
      vel=-2.5;
    }

    LB.spin(forward, vel, percent);
    LF.spin(forward, vel, percent);
    RB.spin(reverse, vel, percent);
    RF.spin(reverse, vel, percent);

    avg = Inertial.heading(degrees);

    error = setpoint - avg;

    preverr = error;

    totalerror+=error;

    if(error<0){
      printf("error: %f ", error);
    }
    else{
      printf("Error: %f ", error);
    }
    printf("    Turned: %f ", avg);
    printf("    Intelgral: %f ", integral);
    printf("    IC: %f ", integral*ki);
    printf("    Velocity: %f \n", vel);
    wait(25, msec);
    if(Brain.Timer.value()>5){
      break;
    }
  }
  LB.stop();
  LF.stop();
  RB.stop();
  RF.stop();
}