#include <stdio.h>
#include <ctype.h>

int convert_hex(char str[]);
int length(char str[]);
int power(int base, int pow);

int main()
{
  char str[] = "0x7CF";
  int result = convert_hex(str);
  printf("Hexadecimal conversion of %s to %d\n", str, result);
  return 0;
}

int length(char str[])
{
  int i = 0;
  while(str[i] != '\0')
    ++i;
  return i;
}

int power(int base, int pow)
{
  if(!pow)
    return 1;

  int result = 1;

  while(pow > 0) {
    result *= base;
    pow--;
  }

  return result;
}

int convert_hex(char str[])
{
  int len = length(str) - 1;
  int n = 0;
  int result = 0;

  for(len; len >= 0; len--) {
    char c = str[len];

    if(tolower(c) == 'x')
      return result;

    int pow = power(16, n);
    if(isdigit(c))
      result += (c - '0') * pow;
    else {
      result += (10 + (tolower(c) - 'a')) * pow;
    }

    n++;
  }
  return result;
}

