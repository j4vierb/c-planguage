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

## 2.8 Operadores de incremento y decremento

Se pueden utilizar como operadores `prefix | postfix`. En ambos casos el efecto es incrementar `n`. Sin embargo, prefix incrementa el valor antes de que su valor es usado, mientras que postfix lo incrementa despues. La función `strcat(s,t)` concatena una cadena  a otra y devuelve un puntero a la misma. 

## 2.9 Operadores `bitwise`
Se pueden aplicar a operadores integrales como char, short, int y long, sean con signo o sin signo.

- & AND
- | OR
- ^ XOR
- `<<` left shift
- `>>` right shift
- ~ complemento a uno

Los operadores de desplazamiento realizan desplazamientos en el operando de la izquierda tantas veces como el de la derecha lo indique, no puede ser negativo. Por tanto, x << 2 desplaza el valor de x en 2 posiciones, llenando los vacios con 0.

El operador unario `~` produce el complemento a uno de un entero, es decir, convierte 1's en 0's y viceversa. 

```c
x = x & ~077 // ~077 = ~(111111)_2 = 000000
    // por tanto x = x & 000000
```

### Enmascarar bits

Esto se refiere a utilizar una mascara para seleccionar, limpiar o modificar bits especificos de una variable. Se puede:

- Limpiar bits
- Seleccionar bits
- Invertir bits

Con mascara de bits se refiere a una secuencia de bits para manipular o extraer ciertos bits de otro valor.

Es necesario notar que `x & ~077` es independiente de la longitud de la palabra. Y la longitud de la palabra se refiere a la cantidad de bits que una unidad de datos puede manejar en un arquitectura de computadora.  

> [!Ya entendí]
> Lo que hace `x = x & ^077` y lo que hace `x = x & ^0177700` es distinto.
> El primero mantiene los primeros 6 bits ya que `077 = 111111`. El segundo
> limpia los primeros 6 bits, es decir, los borra al realizar la operación AND. 
> La principal diferencia se debe a que el segundo para funcionar asume que x es una
> variable de 16 bits, para mantener estos primeros 10 bits. Mientras que el segundo
> solo mantiene los primeros 6 bits independientes de la longitud de la palabra.

### Ejercicios

1. Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
2. Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
3. Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions.

## 2.10 Operadores de asignación y expresiones

### Complemento a 2

Es una manera en la que cada computador utiliza para representar enteros. 

Para obtener la notación de complemento a 2 negativa de un entero, se escribe el número binario, se invierten los digitos y se añade uno al resultado. Por ejemplo, se quiere escribir `-28` en notación de complemento a 2.

1. Escribir 28 en su forma binaria: `0 0 0 1 1 1 0 0` (suponer que se trabaja con cantidades de 8 bits).
2. Invertir los bits: `0 0 1 1 1 0 0 0`. 
3. Sumar 1: `0 0 1 1 1 0 0 1`

Esto es -28 en binario de 8 bits. 

#### Para convertir un número desde complemento 2

El número `0xFFFFFFFF` en binario es `1111 1111 1111 1111 1111 1111 1111 1111`. El número que se encuentra más a la izquierda es 1, por tanto es negativo. Hacer complemento y añadir 1. Luego, la forma negativa de 0xFFFFFFFF es 0x00000001, más comúnmente conocido como 1. Por tanto, 0xFFFFFFFF es -1. 

#### Para convertir un número a complemento 2

Si se tiene -30 y se quiere representar en complemento a 2, se toma toma la representación del 30:

1. `0 0 0 1 1 1 1 0`
2. `1 1 1 0 0 0 0 1`
3. `FFFFFF` `1 1 1 0 | 0 0 1 0` (esta es la representación binaria de -30 en complemento a 2)

En este caso un entero es de 32 bits.

#### Realizar operaciones en complemento a 2
Es sencillo, 

- `1 + 1 = 0` y se lleva `1`
- `1 + 0 = 1`.
- `0 + 0 = 0`

Para realizar restas `69 - 12 = 69 + (-12)`, por lo cual solo es necesario representar a 12 como negativo en complemento a 2 y luego sumar bits. 

### Ejercicio 2.9

En un sistema númerico de complemento a 2, `x &= (x-1)` elimina el bit 1 que se encuentra más a la derecha. ¿Por qué?

Primero que todo, algunas pruebas con 8 bits para facilidad. Si `x = 10 = 0000 1010`, luego, `x - 1 = 9 = 0000 1001`. Por tanto, `0000 1010 & 0000 1001 = 0000 1000`. 
Ahora, si `x = 8 = 0000 1000`, entonces `x - 1 = 7 = 0000 0111` y por tanto `0000 1000 & 0000 0111 = 0000 0000`.

Sin embargo, la anterior observación no utiliza complemento a 2.

```c
int better_bitcount(int n) {
    int b;
    while(n != 0)
    {
        n &= (n - 1);
        b++;
    }

    return b;
}

```

En teoria, el anterior algoritmo es mejor que bitcount original ya que este solo cuenta los bits 1. 

## 2.11 Expresiones condicionales

```c
if(a > b)
    z = a;
else
    z = b;


z = (a > b) ? a : b;
```

## 2.12 Orden de evaluación
N.A

