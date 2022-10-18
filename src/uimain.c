#include <stdio.h>
#include "tokenizer.h"

#define LIMIT 50
int main()  
{
  char str[LIMIT];
  printf("$ ");
  fgets(str, LIMIT, stdin);
  printf("str is: %s\n", str);

  char **token = tokenize(str);
  return 0;
    }


