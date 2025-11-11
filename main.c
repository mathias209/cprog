#include <stdio.h>

int Control(int altitude) {
  int thruster = 0;

  if (altitude <= 100 && altitude > 0)
      thruster = 1;

  return thruster;
}

void Test(int altitude) {
  int thruster = Control(altitude);
  int behaviorCorrect = (altitude > 100 && thruster == 0) ||
                        (altitude <= 100 && altitude > 0 && thruster == 1) ||
                        (altitude <= 0 && thruster == 0);
  char *behaviorCorrectIcon = behaviorCorrect ? " OK " : "FAIL";
  printf("For altitude %3d, your thruster is %d |%s|\n", altitude, thruster,
         behaviorCorrectIcon);
}

int main(void) {
  Test(150);
  Test(100);
  Test(50);
  Test(0);
  Test(-1);
}
