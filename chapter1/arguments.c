#include <stdio.h>

// todas los argumentos se pasan `by value`.
// Esto quiere decir que la función que se llama
// se le dan los valores de los argumentos
// en variables temporales en lugar de los originales
// en otros lenguajes se tiene acceso al argumento
// original y no a una copia, como si lo hace C. 
void say_char(int c)
{
  printf("%c is a char\n", c);
}

// n es usado como una variable local que se decrementa
// como n en este contexto es una copia de la 
// n original, entonces cualquier cambio 
// no debe afectarla. 
int power(int base, int n)
{
  int p;

  for(p = 1; n > 0; --n)
    p = p * base;


  printf("Value of n in power is %d\n", n);
  return p;
}

// nota importante: si el parametro es un arreglo
// c no hace copia de los valores. En lugar de esto 
// pasa la dirección en la que inicia el arreglo. 
int main()
{
  // say_char(65);
  int N = 4;
  power(2, N);

  printf("Value of N is %d\n", N);
  return 0;
}
