#include <stdio.h>

main() {
  int celsius, fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;
  while(fahr <= upper) {
    fahr = ((9 * celsius) / 5 ) + 32;
    printf("%d \t %d \n", celsius, fahr);
    celsius = celsius + step;
  }
}

