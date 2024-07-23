#include <stdio.h>

void copy_v1() {
  int c;
  c = getchar();
  while(c != EOF) {
    putchar(c);
    c = getchar();
  }
}

void copy_v2() {
  int c;
  while((c = getchar()) != EOF) {
    putchar(c);
  }
}

void print_EOF_value() {
  char c = EOF;
  printf("Char is %c\n", c);
}

// EOF: Ctrl + D
int count_chars_num() {
  int nc;

  nc = 0;

  // while(getchar() != EOF)
  //  ++nc;

  for(nc; getchar() != EOF; ++nc)
    ;

  return nc;
}

/*
 * Code to word counting
 *
 * the following definitions is to avoid magic
 * numbers. 
 * */
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
void count_lines_words_chars() {
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while((c = getchar()) != EOF) {
    ++nc;

    if(c == '\n')
      ++nl;

    if(c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if(state == OUT) {
      state = IN;
      ++nw;
    }
  }

  printf("[+] number of lines: %d\n", nl);
  printf("[+] number of words: %d\n", nw);
  printf("[+] number of chars: %d\n", nc);
}

void print_word_perline() {
  int c, state;

  int newline = 10;

  state = OUT;
  while((c = getchar()) != EOF) {
    if(c != ' ' && state == OUT) {
      putchar(c);
      state = IN;
    } else if(state == IN && c == ' ') {
      putchar(c);
      putchar(newline);
      state = OUT;
    } else {
      putchar(c);
    }
  }
}

int main() {
  // copy_v1();
  // print_EOF_value();
  // printf("number of chars: %d\n", count_chars_num());
  
  // representa un valor numerico igual
  // "character constant"
  // otra manera de escribir un "small integer"
  printf("%d\n", 'A' - 10);
  printf("%c\n", 65);

  // count_lines_words_chars();
  print_word_perline();
  return 0;
}

