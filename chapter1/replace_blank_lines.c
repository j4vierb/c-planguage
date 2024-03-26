#include <stdio.h>

main() {
  // Write a program to copy its input to its output, replacing each wtring of one or more blanks by a single blank.
  int c, number_blanks;

  number_blanks = 0;
  while((c = getchar()) != EOF) {
    if(c == ' ' && number_blanks == 0) {
      putchar(c);
      ++number_blanks;
    } else if(c != ' ' && number_blanks > 0) {
      putchar(c);
      number_blanks = 0;
    } else if(c != ' ' && number_blanks == 0) {
      putchar(c);
    }
  }
}
