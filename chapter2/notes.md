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

Los condicionales se evaluan de izquierda a derecha. Lo anterior quiere decir que si tengo la condición `i < lim - 1 && (c = getchar()) != '\n'`, la primera condición se evalua, y si esta es falsa la siguiente ni se mira. 

La precedencia de los operadores lógicos de o e y son mayores que los de cantidad. Por tanto, la expresión que se dio en el ejemplo anterior no necesita parentesis. 

## Sección 2.7
Cuando un operador tiene distintos tipos se convierten en un tipo de dato común según el menor número de reglas. En general, las unicas conversiones automaticas son aquellas que convierten un operador `narrower` en uno `wider`. 

```c
int atoi(char s[])
{
    int i, n;

    n = 0;
    for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = n * 10 + (s[i] - '0');
    return n;
}

int lower(int c)
{
    if(c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
```

La cabecera estandar `<ctype.h>`, descrita en el apendice B, define una familia de funciones que proveen pruebas y conversiones que son independientes del conjunto de caracteres. Provee funciones tales como `tolower` e `isdigit`. En general, si un operador como "+" toma dos operandos de diferentes tipos, el tipo menor se convierte en el tipo de dato mayor. 

1. Si alguno es `long double` convertir el otro a este mismo.
2. Si alguno es `double` convertirlo a este.
3. Si alguno es `float` convertir el otro a este.
4. Convertir char y short a int.
5. Si alguno es long, convertir el otro a long.

En la ausencia de un prototipo de función char y short se convierten en int y float en double.

Finalmente, se puede forzar una conversión de tipo en cualquier expresión utilizando el operador unario `cast`. 

```c
(type name) expression // la expresión se convierte al tipo de dato según las reglas arriba

sqrt( (double) n );
```

Si los argumentos son declarados por una función de prototipo, la declaración causa una coerción automatica de cualquier argumento cuando la función es llamada.

## Operadores de incremento y decremento

Se pueden utilizar como operadores `prefix | postfix`. En ambos casos el efecto es incrementar `n`. Sin embargo, prefix incrementa el valor antes de que su valor es usado, mientras que postfix lo incrementa despues. La función `strcat(s,t)` concatena una cadena  a otra y devuelve un puntero a la misma. 

## Operadores `bitwise`
Se pueden aplicar a operadores integrales como char, short, int y long, sean con signo o sin signo.

- & AND
- | OR
- ^ XOR
- `<<` left shift
- `>>` right shift
- ~ complemento a uno


