#include <pid.h>
#include <vex.h>

void calloc(){
  static double x=0;
  static double y=0;
  static double theta = 0;
  static double left_turns = 0;
  static double right_turns = 0;

  double dleft = Left.position(turns);
  double dright = Right.position(turns);

  dleft -= left_turns;
  dright -= right_turns;

  left_turns += dleft;
  right_turns += dright;

  double leftDist = dleft*M_PI*3.25;
  double rightDist = dright*M_PI*3.25;
  double dtheta = (leftDist - rightDist)/(2*7);

  double dist = (rightDist + leftDist)/2;
  double dy = dist*cos(theta+dtheta/2);
  double dx = dist*sin(theta+dtheta/2);

  x += dx;
  y += dy;

  theta += dtheta;
  if(theta > 2*M_PI) {
    theta -= 2*M_PI;
  }
  if(theta <- 2*M_PI) {
    theta += 2*M_PI;
  }
  //printf("%f, %f, %f, %f\n", x, y, theta*180/M_PI, Inertial.heading(degrees));
}

double callocturn(){
  static double x=0;
  static double y=0;
  static double theta = 0;
  static double left_turns = 0;
  static double right_turns = 0;

  double dleft = Left.position(turns);
  double dright = Right.position(turns);

  dleft -= left_turns;
  dright -= right_turns;

  left_turns += dleft;
  right_turns += dright;

  double leftDist = dleft*M_PI*3.25;
  double rightDist = dright*M_PI*3.25;
  double dtheta = (leftDist - rightDist)/(2*7);

  double dist = (rightDist + leftDist)/2;
  double dy = dist*cos(theta+dtheta/2);
  double dx = dist*sin(theta+dtheta/2);

  x += dx;
  y += dy;

  theta += dtheta;
  if(theta > 2*M_PI) {
    theta -= 2*M_PI;
  }
  if(theta <- 2*M_PI) {
    theta += 2*M_PI;
  }

  //printf("%f, %f, %f, %f\n", x, y, theta*180/M_PI, Inertial.heading(degrees));
  return theta;
}

void returnHome(double err, double r2h){
  static double x=0;
  static double y=0;
  static double theta = 0;
  static double left_turns = 0;
  static double right_turns = 0;

  double dleft = Left.position(turns);
  double dright = Right.position(turns);

  dleft -= left_turns;
  dright -= right_turns;

  left_turns += dleft;
  right_turns += dright;

  double leftDist = dleft*M_PI*3.25;
  double rightDist = dright*M_PI*3.25;
  double dtheta = (leftDist - rightDist)/(2*7);

  double dist = (rightDist + leftDist)/2;
  double dy = dist*cos(theta+dtheta/2);
  double dx = dist*sin(theta+dtheta/2);

  x += dx;
  y += dy;

  theta += dtheta;
  if(theta > 2*M_PI) {
    theta -= 2*M_PI;
  }
  if(theta <- 2*M_PI) {
    theta += 2*M_PI;
  }

  turnPID(r2h, 0.1, 0.5, 0, 25);
  drivePID(sqrt(pow(x,2)+pow(y,2)), 0.25, 8, 0, 0);
  printf("TurnTo: %f\n", r2h);
  wait(5, sec);
}

double r2h() {
  static double x=0;
  static double y=0;
  static double theta = 0;
  static double left_turns = 0;
  static double right_turns = 0;

  double dleft = Left.position(turns);
  double dright = Right.position(turns);

  dleft -= left_turns;
  dright -= right_turns;

  left_turns += dleft;
  right_turns += dright;

  double leftDist = dleft*M_PI*3.25;
  double rightDist = dright*M_PI*3.25;
  double dtheta = (leftDist - rightDist)/(2*7);

  double dist = (rightDist + leftDist)/2;
  double dy = dist*cos(theta+dtheta/2);
  double dx = dist*sin(theta+dtheta/2);

  x += dx;
  y += dy;

  printf("%f\n", atan2(y, x)*180/M_PI);

  return atan2(y, x)*180/M_PI;
}