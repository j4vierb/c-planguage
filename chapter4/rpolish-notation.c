# include <stdlib.h>
# include <stdio.h> /* for atof() */

#define MAXOP 100 /* max size operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */

int stack_pointer = 0;
double val[MAXVAL];

int getop(char []);
void push(double);
double pop(void);

/* reverse polish calculator */
int main()
{
  int type;
  double op2;
  char s[MAXOP];

  while((type = getop(s)) != EOF) {
    switch(type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '\n':
        prinf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %d\n", s);
        break;
    }
  }

  return 0;
}

/* push: push f onto value stack */
void push(double f)
{
  if(stack_pointer < MAXVAL9
    val[stack_pointer++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop and return top value from stack */
double pop(void)
{
  if(stack_pointer > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

