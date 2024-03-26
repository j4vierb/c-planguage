#include <stdio.h>

/**
* Program that counts the number of characters using getchar() meanwhile it is different of EOF
*
* Ctrl + D matches EOF constant from stdio.h
*/
main() {
  long nc;

  for(nc = 0; getchar() != EOF; ++nc)
    ; // null statement

  printf("%ld\n", nc);
}
