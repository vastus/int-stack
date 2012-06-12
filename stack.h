#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define DEFAULTSIZE 4

typedef struct
{
  int *elems;
  int alloclen;
  int logicallen;
} Stack;

void StackNew(Stack *);
void StackPush(Stack *, int);
int  StackPop(Stack *);
void StackDispose(Stack *);
bool isFull(Stack *);

void StackNew(Stack *s)
{
  s->logicallen = 0;
  s->alloclen = DEFAULTSIZE;
  s->elems = malloc(s->alloclen * sizeof(int));
  assert(s->elems != NULL);
}

void StackPush(Stack *s, int value)
{
  if (isFull(s)) {
    s->alloclen += DEFAULTSIZE;
    s->elems = realloc(s->elems, (s->alloclen * sizeof(int)));
  } 

  assert(s->elems != NULL);
  s->elems[s->logicallen] = value;
  s->logicallen += 1;
}

int StackPop(Stack *s)
{
  assert(s->logicallen > 0);
  s->logicallen -= 1;
  return s->elems[s->logicallen];
}

void StackDispose(Stack *s)
{
  s->logicallen = 0;
  s->alloclen = 0;
  free(s->elems);
}

bool isFull(Stack *s)
{
  if (s->logicallen == s->alloclen) {
    return true;
  }

  return false;
}

