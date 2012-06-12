#include <stdio.h>
#include <stdbool.h>
#include "assert.h"
#include "stack.h"

int main()
{
  // LIFO
  Stack stack;
  StackNew(&stack);

  char *dataFormat = "%7d%2s%8d\n";

  puts("\nLogical | Allocated");
  puts("--------|----------");
  printf(dataFormat, stack.logicallen, "|", stack.alloclen);

  int i;
  for (i = 0; i < 50000; i++) {
    StackPush(&stack, i);
  }

  printf(dataFormat, stack.logicallen, "|", stack.alloclen);

  for (i = 0; i < 50000; i++) {
    StackPop(&stack);
  }

  printf(dataFormat, stack.logicallen, "|", stack.alloclen);

  // free the memory
  puts("\nAbout to dispose\n");
  StackDispose(&stack);

  puts("Logical | Allocated");
  puts("--------|----------");
  printf(dataFormat, stack.logicallen, "|", stack.alloclen);
  printf("\n");

  return 0;
}

