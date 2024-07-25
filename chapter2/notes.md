# Notas capitulo 2

## Sección 2.1

No se pueden utilizar palabras reservadas como nombres de variables. Se puede utilizar `_`. 

## Sección 2.2

Tipos de datos basicos en C son `char`, `int`, `float` y `double`. Existen varios `qualifiers` que pueden ser añadidos a los tipos básicos. En el caso de `short | long` proveen diferentes longitudes de enteros. Se sigue que `short` e `int` son de al menos 16 bits, `long` es de al menos `32` bits, y `short` no es mayor que `int` e `int` no es mayor que `long`. 

```c
short int sh;
long int counter;
```

Los valores de `signed char` van de -128 a 127, mientras que `unsigned char` va de 0 a 255. 

## Sección 2.3

Un `long` se escribe con una `l` final (`123L`). Un entero muy grande como para ser un entero se toma como un long. Constantes sin signo se escriben con una u final, y el sufijo ul indica unsigned long. 

Un 0 en un entero constante significa octal, un 0x significa hexadecimal. Un caracter constante es un entero. El valor es un valor númerico del caracter en el conjunto de caracteres de la maquina. 

Una expresión constante es una expresión que involucra solo constantes. Las expresiones son evaluadas en tiempo de compilación y no en tiempo de ejecución. Una cadena de caracteres es una secuencia de 0 o más caracteres. Constantes de string pueden ser concatenadas en tiempo de compilación:

```c
"hello, " "x" <-> "hello, x"
```

La representación interna de una cadena tiene un caracter nulo `\0` al final. 


```c
int strlen(char s[])
{
    int i;

    while(s[i] != '\0')
        ++i;

    return i;
}
```

Diferenciar entre `'x' & "x"`, la primera es un número representando un caracter del conjunto de caracteres de la maquina mientras que el segundo es un arreglo de caracteres que contiene 2 letras `{'x', '\0'}`. 

Existe otro tipo de constantes, las constantes de enumeración. 

```c
enum boolean { NO, YES };
```

## Sección 2.4 

El calificador const se añade a la declaración de cualquier variable para especificar que su valor no puede cambiar. 

## Sección 2.6

