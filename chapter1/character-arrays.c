#include<stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char line[], int length);

int main()
{
  int len;
  // int max;
  // char line[MAXLINE];
  // char longest[MAXLINE];

  // max = 0;
  // while((len = get_line(line, MAXLINE)) > 0)
  // {
  //  if (len > max)
  //  {
  //    max = len;
  //    copy(longest, line);
  //  }
  // }

  // if(max > 0)
    // cuando se imprime con %s espera una cadena
    // de caracteres que finaliza con el caracter nulo
    // printf("Longest string: %s", longest);

  // part 2
  // int longer = 4;
  // char input[10];
  // while((len = get_line(input, 10)) > 0)
  // {
    // each line has \n at the end
  //  if(len > longer)
  //    printf("C says: %s", input);
  // }

  // part 3
  char line[10];
  while((len = get_line(line, 10)) > 0)
  {
    printf("actual line is: %s", line);
    if(len > 0)
      reverse(line, 10);
  }

  return 0;
}

/* getline: read a line into s, return length */
// puede causar un overflow si la cadena es 
// mayor a lim. 
int get_line(char s[], int lim)
{
  int c, i;

  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if(c == '\n')
  {
    s[i] = c;
    ++i;
  }
  // null character: su valor es 0. Denota el final 
  // de la cadena de caracteres.
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}

void reverse(char line[], int length)
{
  int endline;
  int i = 0;
  while(line[i] != '\0')
    ++i;

  char reversed[length];
  int j = 0;
  i--;
  while(i >= 0)
  {
    reversed[j] = line[i];
    ++j;
    --i;
  }

  reversed[j] = '\0';
  printf("%s\n", reversed);
}

