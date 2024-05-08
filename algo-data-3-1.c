#include<stdio.h>
#include<stdlib.h>
#include "algo-data-3-1.h"

int Initialize(IntStack *s, int max)
{
    s->ptr = 0;
    if((s->stk = calloc(max,sizeof(int))) == NULL){
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int Push(IntStack *s, int x)
{
    if (s->ptr >= s->max){
        return -1;
    }
    s->stk[s->ptr++] = x;
    return 0;
}

int Pop(IntStack *s, int *x)
{
    if (s->ptr <= 0){
        return -1;
    }
    *x = s->stk[--s->ptr];
    return 0;
}

int Peek(const IntStack *s, int *x)
{
    if (s->ptr <= 0){
        return -1;
    }
    *x = s->stk[s->ptr - 1];
    return 0;
}

void Clear(IntStack *s)
{
    s->ptr = 0;
}





