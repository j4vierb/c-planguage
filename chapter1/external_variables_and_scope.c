#include <stdio.h>

# define MAX_FILE_SIZE 1000

int get_line(char arr[], int size);
// las variables dentro de main son privadas
// o locales para main. Como estan declaradas en
// este mismo lugar otras funciones no pueden acceder.
// las variables existen unicamente cuando la funcion
// es llamada y desaparecen cuando la función termina
// en otros lenguajes se llaman variables automaticas
// Hay variables que son externas y se pueden acceder
// por cualquier función. Estas variables deben ser
// definidas exactamente una vez. Por otro lado, deben
// ser declaradas en cada función que quiera acceder.
int main()
{
  char arr[MAX_FILE_SIZE];
  get_line(arr, MAX_FILE_SIZE);
  printf("%s\n", arr);
  return 0;
}

int get_line(char arr[], int size)
{
  int c;
  int i = 0;
  char prev; // carries the last character (i - 1)
  int can_write = 1;
  while((c = getchar()) != EOF && i < size - 1)
  {
    if(prev == '/' && c == '/') {
      can_write = 0;
    } else if(c == '\n') {
      printf("%c", c);
      can_write = 1;
      arr[i] = c;
      i++;
    } else if(can_write) {
      arr[i-1] = prev;
      i++;
    } 
    prev = c;

    // printf("index: %d && character: (%c)\n", i, c);
  }
  //arr[i-1] = prev;
  // arr[i] = '\0';
  
  return i;
}
/*
* /* /* /*
*/
// header: colección de declaraciones de variables
// y funciones en un archivo separado, que luego 
// es incluido utilizando `#include` al inicio de
// cada archivo fuente.
// Definición: el lugar donde una variable es creada
// o donde se asigna.
// Declaración: el lugar donde la naturaleza de la 
// variable es indicada pero no se asigna almacenamiento.
//

