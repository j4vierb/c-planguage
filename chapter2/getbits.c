# include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, unsigned y, int p, int n);

int main()
{
  unsigned x = 86; // ... 0101 0110

  int p = 4, n = 4;
  unsigned bits = getbits(x, p, n);
  printf("getbits function result: %d\n", bits);
  
  unsigned x_test = 225, y_test = 15;
  unsigned b = setbits(x_test, y_test, p, n);
  printf("setbits function result: %d\n", b);

  return 0;
}

/**
  * get n bits from position p
  * we assume that position 0 is at the right end
  * the position p
  */ 
unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p + 1 - n)) & ~(~0 << n);
}

/**
  * set n bits from position p in x from y.
  * 
  * example: 
  * x = 1110 0001 = 225
  * y = 0000 1111 = 15
  * p = 4, n = 4 
  *
  * setbits(x, y, p, n) returns 1111 1111 = 255
  * this means, put the 4 first bits from y (1111) in the
  * position 4 in x (from left to right). 
  */
unsigned setbits(unsigned x, unsigned y, int p, int n)
{
  if(p < 0 || n < 0)
    return -1;

  // clean n bits from position p in x
  x = ~((~(~0 << n)) << (p-n+1)) & x;
  printf("[LOG<setbits>] x after the cleaning is: %d\n", x);

  // isolate n bits of y
  y = ~(~0 << n) & y;
  printf("[LOG<setbits>] y after the isolation is: %d\n", y);
  // move y bits (p - n + 1) times
  y = y << (p - n + 1);
  printf("[LOG<setbits>] y after shift left is: %d\n", y);
  return x | y;
}

