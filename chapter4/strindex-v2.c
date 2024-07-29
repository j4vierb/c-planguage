# include <stdio.h>

int strindex(char s[], char t[]);

int main()
{
  char s[] = "papayopapayo";
  char t[] = "payo";
  int r = strindex(s, t);
  while(s[r] != '\0')
  {
    putchar(s[r++]);
  }
  printf("\n%d\n", r);
  return 0;
}

int strindex(char s[], char t[])
{
  int i, j, k;
  int max = -1;
  for(i = 0; s[i] != '\0'; i++)
  {
    for(j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++)
      ;

    if(k > 0 && t[k] == '\0') {
      max = k;
      k = 0;
    }
  }

  if(max >= 0)
    return max;

  return -1;
}

