#include <stdio.h>
#include <stdbool.h>
#include "assert.h"
#include "stack.h"

int main()
{

  // last in first out
  // filo
  Stack stack;
  StackNew(&stack);

  //printf("Logical:    %d\n", stack.logicalLen);
  //printf("Allocated:  %d\n", stack.allocLen);
  puts("\nLogical | Allocated");
  puts("--------|----------");
  printf("%4d%5s%6d\n", stack.logicalLen, "|", stack.allocLen);

  int i;
  for (i = 0; i < 50000; i++) {
    StackPush(&stack, i);
  }

  printf("%4d%5s%6d\n", stack.logicalLen, "|", stack.allocLen);

  for (i = 0; i < 50000; i++) {
    //printf("Last popped: %d\n", StackPop(&stack));
    StackPop(&stack);
  } //putchar('\n');

  printf("%4d%5s%6d\n", stack.logicalLen, "|", stack.allocLen);

  // free the memory
  puts("\nAbout to dispose\n");
  StackDispose(&stack);

  puts("Logical | Allocated");
  puts("--------|----------");
  printf("%4d%5s%6d\n", stack.logicalLen, "|", stack.allocLen);
  puts("");

  return 0;
}

