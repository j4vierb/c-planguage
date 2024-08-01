# Capitulo 4 - Funciones y estructura de un programa

Las funciones rompen tareas de computación muy largas en partes más pequeñas. Los archivos fuentes pueden ser compilados por separado y cargados juntos. 

## 4.1 Basico de funciones

Hacer un programa como grep de Linux. Una función que retorne el indice desde el cual inica un substring en otro, o -1 si no se encuentra. 

```c
int strindex(char s[], char t[])
{
    int i, j, k;
    for(i = 0; s[i] != '\0'; i++) {
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;

        if(k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
```

Una función minima es:

```c
dummy() {}
```

Para compilar y cargar distintos archivos de código fuente en UNIX es `cc file1.c file2.c ...`, esto compila los tres archivos y los ubica en 3 archivos de código objeto con extensión .o, y luego los carga todos en un archivo ejecutable a.out. 

## 4.2 Funciones que retornan no enteros

¿Qué pasa si una función debe devolver otro tipo de dato? Escribamos una función que reciba por parámetro una cadena de caracteres y retorne su equivalente en punto flotante de doble precisión (double). El encabezado "stdlib.h" declara una función "atof". En nuestro caso, será una extensión de este "atoi".  

Primero, la misma función debe declarar el tipo que retorna, ya que no es int. El tipo debe ir antes del nombre de la función. Segundo, la rutina que lo llame debe saber que la función retorna un valor no entero. Una manera de asegurar esto es declarar atof en la rutina de llamada. 

```c
int main()
{
    double sum, atof(char []);
}
```

Lo anterior indica que la función atof toma un argumento de tipo string y retorna un punto flotante de doble precisión. 

Luego, si la declaración de atof en su propia función y la llamada a la función en la rutina de llamada son inconsistentes en el mismo archivo fuente, el error será detectado por el compilador. 

Si una función que no ha sido previamente definida ocurre en una expresión y es seguida de un parentesis izquierda (el nombre de la función), es declarada por el contexto y retorna int, y no se asume nada sobre sus argumentos.

Si por ejemplo, la declaración de la función no incluye argumentos `double atof()` todos los chequeos de parametros se desactivan, es decir, se le puede pasar cualquier cosa y no va a funcionar. Si la función no espera arugmentos ubica un void.

A este punto hay varias dudas sobre como se guardan números enteros, positivos y negativos, y además, números de coma flotante. 

