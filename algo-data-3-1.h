#pragma once
#ifndef ___IntStack
#define ___IntStack

typedef struct{
	int max_size;
	int ptr;
	int* stk;
} IntStack;

int InitStack(IntStack* stack, int max);

int Push(IntStack* stack, int num);

int Pop(IntStack* stack, int* num);

int Peek(const IntStack* stack, int* x);

void ClearStack(IntStack* stack);

int GetStackCapacity(const IntStack* stack);

int GetStackSize(const IntStack* stack);

int IsEmptyStack(const IntStack* stack);

int IsFullStack(const IntStack* stack);

int SearchStack(const IntStack* stack, int num);

void Print(const IntStack* stack);

void TerminateStack(IntStack* stack);

#endif
