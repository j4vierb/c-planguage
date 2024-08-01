# include <ctype.h>
# include <stdio.h>

double atof(char s[]);
int atoi(char s[]);
long powr(int b, int e);

int main()
{
  char s[] = "3.1415";
  char s2[] = "1.1e1";
  char s3[] = "1.9E1";
  char s4[] = "27.9e-1";

  printf("%f\n", atof(s));
  printf("%f\n", atof(s2));
  printf("%f\n", atof(s3));
  printf("%f\n", atof(s4));
  return 0;
}

long powr(int b, int e)
{
  int res = 1;

  while(e > 0) {
    res *= b; 
    e--;  
  }

  return res;
}

double atof(char s[])
{
  double val, power;
  int i, sign;

  // delete spaces
  for(i = 0; isspace(s[i]); i++)
    ;

  // determine the number sign
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-')
    i++;
 
  // calculate the first digits
  for(val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  // calculate the floating point digits
  if(s[i] == '.')
    i++;

  for(power = 1.0; isdigit(s[i]); i++)
  {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }

  val = sign * val / power;

  if(s[i] != 'e' && s[i] != 'E')
    return val;
  i++; // delete e | E

  // Extend atof to handle scientific notation of the form
  if(s[i] == '-') {
    sign = 0; // (negative) if I put -1 it's different of false
    i++;
  } else 
    sign = 1;

  // read exponent
  int newVal;
  for(newVal = 0; isdigit(s[i]); i++)
  {
    newVal = 10 * newVal + (s[i] - '0');
  }

  // produce an output
  if(sign) // 1
    return val * powr(10, newVal);

  return val / powr(10, newVal);
}

int atoi(char s[])
{
  double atof(char s[]);

  return (int) atof(s);
}

