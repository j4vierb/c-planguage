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

Para compilar y cargar distintos archivos de código fuente en UNIX es `cc file1.c file2.c ...`, esto compila los tres archivos y los ubica en 3 archivos de código objeto con extensión .o, y luego los carga todos en un archivo ejecutable a.out. 

