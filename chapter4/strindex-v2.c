# include <stdio.h>

int strindex(char s[], char t[]);
int strindex_v2(char [], char []);

int main()
{
  char s[] = "aaaa aaaa aaaa";
  char t[] = "h";
  int r = strindex(s, t);
  int r2 = strindex_v2(s, t);
  printf("answer 1: %d\nanswer 2: %d\n", r, r2);
  return 0;
}

int strindex(char s[], char t[])
{
  int i, j, k;

  for(i = 0; s[i] != '\0'; i++)
  {
    for(j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++)
      ;

    if(k > 0 && t[k] == '\0')
      return i;
  }

  return -1;
}

int strindex_v2(char s[], char t[])
{
  int i, j, k;
  int max = -1;
  for(i = 0; s[i] != '\0'; i++)
  {
    for(j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++)
      ;

    if(k > 0 && t[k] == '\0') {
      max = i;
      k = 0;
    }
  }

  return max;
}

