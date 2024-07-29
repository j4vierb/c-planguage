# Notas capitulo 3

## Secciones 3.1, 3.2, 3.3 y 3.4

Definen las siguientes condicionales:

```c

if(expression)
    statement
else if(expression)
    statement
else
    statement

switch(expression) {
    case const-expr: statements
    case const-expr: statements
    default: statements
}

switch(c)
{
    case '0': case '1': 
        ndigit[c - '0']++;
        break;
    case ' ':
        nwhite++;
        break;
    default:
        other++;
        break;
}
```

Al utilizar switch si no se ubica un break entre casos la ejecución el programa seguirá entre ellos hasta llegar al default.

## Sección 3.5 bucles, 3.6 do-While

Las comas que separan los argumentos de una función, declaración de variables no son el operador coma. Un par de expresiones separadas por coma son evaluadas de izquierda a derecha y el tipo y valor del resultado son el tipo y valor del operando de la derecha.

```c
do
    statement
while(expression);
```

## Sección 3.7 Break y Continue

La declaración `break` produce una salida temprana de un for, while y un do-while. La siguiente función elimina espacios, tabs y saltos de linea en una cadena de caracteres recorriendola desde el final hasta el inicio.

```c
int trim(char s[])
{
    int n;
    for(n = strlen(s) - 1; n >= 0; n--)
        if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;

    s[n+1] = '\0';
    return n;
}
```

La declaración continue es relacionada a break, causa la siguiente iteración de un bucle. Esto quiere decir que la siguiente instrucción que es ejecutada es la evaluación de bucle. 

```c
for(i = 0; i < n; i++)
    if(a[i] < 0)
        continue;
    ... /* do positive elements */
```

## Instrucción GOTO

Por lo general, el código escrito con uno de estos puede ser escrito sin esta instrucción.

Una etiqueta tiene la misma forma que el nombre de una variable y es seguido por dos puntos. 

```c
for(i = 0; i < n; i++)
    for(j = 0; j < m; j++)
        if(a[i] == b[j])
            goto found;

found:
    /* got one: a[i] == b[j] */
```

