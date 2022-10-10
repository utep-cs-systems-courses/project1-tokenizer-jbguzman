#include <stdio.h>

#define LIMIT 50
int main()  
{
  char str[LIMIT];
  printf("$ ");
  fgets(str, LIMIT, stdin);
  printf("str is: %s\n", str);
  
  return 0;
    }


