# include <stdio.h>

int bitcount(unsigned x);
int better_bitcount(int n);

int main()
{
  unsigned int n = 5; // octal: (101)_2
  printf("Result: %d\n", bitcount(n));
  printf("Result 2: %d\n", better_bitcount(n));
  // theory: it returns 1 becuase there's a zero between each 1
  // result: it returns 2 because the condition of the loop is x != 0
  // and x is only 0 when all the rigth shift was performed.
  
  int num;
  num = 0xFFFFFFe2;
  printf("%d\n", num);
  
  int x = 7; // 0000 0000 0000 0000 0000 0000 0000 0111

  x = x & (x - 1);

  return 0;
}

/**
  * straightforward version of bitcount
  **/
int bitcount(unsigned x)
{
  int b; // counts the number of 1-bits in an integer argument
  
  for(b = 0; x != 0; x >>= 1)
    // x & 01 only is true if x has 1-bit
    if(x & 01)
      b++;

  return b;
}

int better_bitcount(int n)
{
  int b;
  while(n != 0)
  {
    n &= (n - 1);
    b++;
  }

  return b;
}

