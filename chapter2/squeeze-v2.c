# include <stdio.h>
# include <string.h>

void squeeze(char s1[], char s2[]);
void del(char s1[], int n);
int any(char s1[], char s2[]);

int main()
{
  char s1[] = "avocado";
  char s2[] = "dv";
  int min_position = any(s1, s2);
  printf("Min: %d\n", min_position);
  return 0;
}

int any(char s1[], char s2[])
{
  int i, j;
  int min_position = strlen(s1);

  for(i = strlen(s2) - 1; i >= 0; i--)
    for(j = strlen(s1) - 1; j >= 0; j--)
      if(s1[j] == s2[i] && j < min_position)
        min_position = j;

  if(min_position == strlen(s1))
    return -1;

  return min_position;
}

void del(char s1[], int n)
{
  n++;
  while(s1[n] != '\0')
  {
    s1[n-1] = s1[n];
    n++;
  }
  s1[n-1] = s1[n]; // write '\0'
}

/**
 * No funciona del todo bien :(
 ***/
void squeeze(char s1[], char s2[])
{
  int i, j;
  i = 0;

  for(i; i < strlen(s1); i++)
  {
    char c = s1[i];
    j = 0;

    for(j; j < strlen(s2); j++)
    {
      char k = s2[j];
      // si hay un caracter en s2 que es igual a s1
      // se elimina
      if(c == k) {
        del(s1, i);
        break;
      }
    }
  }
}

