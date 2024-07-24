#include <stdio.h>

/**
  * Los parametros son locales de la función
  * y no son visibles para otras funciones.
  *
  * Lo siguiente es un prototipo de función.
  * No son necesarios los nombres de los 
  * parametros.
  */
int power(int base, int n);

int main()
{
  return 0;
}

int power(int base, int n)
{
  int i, p;
  p = 1;
  for(i = 1; i <= n; ++i)
    p = p * base;

  return p;
}

