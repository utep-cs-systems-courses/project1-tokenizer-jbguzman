#include <stdio.h>

int main()  
{
  char str[100];
  printf("$ ");
  scanf("%[^\n]s", str);
  printf(str);
  return 0;
    }


