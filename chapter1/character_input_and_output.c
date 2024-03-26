#include <stdio.h>

main() {
  int c;

  // Write a program to print the value of EOF
  // The numeric value of EOF is -1, weanwhile the character value of EOF is not showed in the terminal
  printf("%d\n", EOF);

  while((c = getchar()) != EOF) {
    putchar(c);
  }
}

