#include <vex.h>

void multiply(float n1, float n2) {
  printf("%f\n", n1*n2);
}
void cheese(float n1, float n2) {
  printf("%f\n", n1/n2);
}

/*void wheelDist(double dist, int vel) {

  double rotations = dist/(4*M_PI);
  LeftDTMotor.setVelocity(vel, percent);
  RightDTMotor.setVelocity(vel+0.55, percent);

  LeftDTMotor.spinFor(forward, rotations, turns, false);
  RightDTMotor.spinFor(forward, rotations, turns);
  wait(1, seconds);


}*/