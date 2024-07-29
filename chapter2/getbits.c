# include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, unsigned y, int p, int n);
unsigned invert(unsigned x, int p, int n);
unsigned char rightrot(unsigned char x, int n);

int main()
{
  unsigned x = 86; // ... 0101 0110

  int p = 4, n = 4;
  unsigned bits = getbits(x, p, n);
  printf("getbits function result: %d\n", bits);
  
  unsigned x_test = 225, y_test = 15;
  unsigned b = setbits(x_test, y_test, p, n);
  printf("setbits function result: %d\n", b);

  unsigned x_to_invert = 28;
  unsigned bi = invert(x_to_invert, p, 3);
  printf("invert function result: %d\n", bi);

  unsigned char x_to_rot = 2;
  int n_rotations = 2;
  unsigned char res = rightrot(x_to_rot, n_rotations);
  printf("rigthrot function result: %d\n", res);
  printf("rightrow function with x = 16, n = 4 produces %d\n", rightrot((unsigned char) 16, 4));
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
  x = ~((~(~0 << n)) << (p - n + 1)) & x;
  printf("[LOG<setbits>] x after the cleaning is: %d\n", x);

  // isolate n bits of y
  y = ~(~0 << n) & y;
  printf("[LOG<setbits>] y after the isolation is: %d\n", y);
  // move y bits (p - n + 1) times
  y = y << (p - n + 1);
  printf("[LOG<setbits>] y after shift left is: %d\n", y);
  return x | y;
}

/**
  * do the complement of n bits from position p
  *
  * example:
  * x = 0001 1100 = 28
  * p = 4, n = 3
  *
  * invert(x, p, n) returns 0000 0000 because the next
  * n bits from position 4 are 1, and doing the complement
  * produces 0-bits in each position.
  **/
unsigned invert(unsigned x, int p, int n)
{
  // prepare bit mask
  unsigned r = ~(~0 << n) << (p - n + 1);
  return x ^ r;
}

/**
  * returns the value of the unsigned integer x rotated to the
  * right by n positions. 
  *
  * example 1:
  * x = (0000 0010) = 2
  * n = 2
  *
  * rightrot(x, n) produces 1000 0000
  *
  * example 2:
  *
  * x = (0001 0000) = 16
  * n = 4
  *
  * rightrot(x, n) produces 0000 0001
  **/
unsigned char rightrot(unsigned char x, int n) { 
  int status;
  while(n > 0) {
    status = x & 1; // 1 if both has 1-bit first at all, 0 if not
    x >>= 1;
    if(status)
      x = x | (~0 << 7);
    n--;
  }

  return x;
}

