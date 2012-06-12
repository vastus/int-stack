#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define DEFAULTSIZE 4

typedef struct
{
  int *elems;
  int logicalLen;
  int allocLen;
} Stack;

void StackNew(Stack *);
void StackPush(Stack *, int);
int  StackPop(Stack *);
void StackDispose(Stack *);

bool isFull(Stack *);

void StackNew(Stack *s)
{
  s->allocLen = 0;
  s->logicalLen = DEFAULTSIZE;
  s->elems = malloc(s->logicalLen * sizeof(int));
  assert(s->elems != NULL);
}

void StackPush(Stack *s, int value)
{
  if (isFull(s)) {
    s->logicalLen += DEFAULTSIZE;
    s->elems = realloc(s->elems, (s->logicalLen * sizeof(int)));
    // int size = DEFAULTSIZE * sizeof(int) + s->logicalLen;
    // s->logicalLen += DEFAULTSIZE;
    // s->elems = realloc(s->elems, size);
  } 

  assert(s->elems != NULL);
  s->elems[s->allocLen] = value;
  s->allocLen += 1;
}

int StackPop(Stack *s)
{
  assert(s->allocLen > 0);
  s->allocLen -= 1;
  return s->elems[s->allocLen];
}

void StackDispose(Stack *s)
{
  s->allocLen = 0;
  s->logicalLen = 0;
  free(s->elems);
}

bool isFull(Stack *s)
{
  if (s->allocLen == s->logicalLen) {
    return true;
  }

  return false;
}

