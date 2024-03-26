#include <stdio.h>

main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  // Exercise 1-3: Modify the temperature conversion program to print a heading above the table.
  printf("Temperature conversion from fahrenheit to celsius\n");
  printf("Fahrenheit \t Celsius\n");

  fahr = lower;
  while(fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%3.0f \t %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
