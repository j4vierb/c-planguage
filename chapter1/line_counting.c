#include <stdio.h>

main() {
  int c;
  int nl, nt, nb;

  // Exercise 1-8: Write a program to count blanks, tabs and newlines.
  nl = 0;
  nt = 0;
  nb = 0;
  while((c = getchar()) != EOF) {
    if(c == '\n')
      ++nl;
    else if(c == '\t')
      ++nt;
    else if(c == ' ')
      ++nb;
  }

  printf("The number of lines is %d\n", nl);
  printf("The number of tabs is %d\n", nt);
  printf("The number of blanks is %d\n", nb);
}
