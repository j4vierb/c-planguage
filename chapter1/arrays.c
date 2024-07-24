#include <stdio.h>

void count_digits_others()
{
  int c, nother, i = 0;
  int ndigit[10]; // declarar un arreglo con 
  // 10 posiciones
  
  nother = 0;

  for(i = 0; i < 10; i++)
    ndigit[i] = 0;

  while((c = getchar()) != EOF)
  {
    if(c >= '0' && c <= '9')
      ++ndigit[c-'0'];
    else 
      ++nother;
  }

  printf("digits =");
  for(i = 0; i < 10; i++)
  {
    printf(" %d", ndigit[i]);
  }

  putchar('\n');
}

# define CHAR 26

/**
 * Write a program to print a histogram of 
 * the frequencies of different characters
 * in its input
 **/  
void histogram_frequencies()
{
  int c, i;
  int hist[CHAR];
  for(i = 0; i < CHAR; i++)
  {
    hist[i] = 0;
  }

  while((c = getchar()) != EOF)
  {
    int i = c - 'a';
    if(i >= 0 && i <= 25)
      hist[i]++;
  }

  // print hist if each index is different of 0
  for(i = 0; i < CHAR; i++)
  {
    if(hist[i])
    {
      char character = 'a' + i;
      int ocurrencies = hist[i];
      printf("- %c : %d \n", character, ocurrencies);
    }
  }
}

# define IN 1
# define OUT 0

void histogram_lengths()
{
  int c, i, state = OUT;
  int lengths[10];
  for(i = 0; i < 10; i++)
    lengths[i] = 0;

  int length = 0;
  while((c = getchar()) != EOF)
  {
    if(state == OUT && c != ' ') {
      state = IN;
      length++;
    } else if(state == IN && c == ' ') {
      lengths[length-1]++;
      length = 0;
      state = OUT;
    } else {
      length++;
    }
  }

  // print histogram
  for(i = 0; i < 10; i++)
    if(lengths[i])
      printf("[-] %d : %d\n", i+1, lengths[i]);
}

int main ()
{
  // count_digits_others();
  // histogram_frequencies();
  histogram_lengths();
  return 0;
}

