#pragma once
#ifndef ___IntStack
#define ___IntStack

typedef struct{
	int max_size;
	int ptr;
	int* stk;
} IntStack;

int Initialize(IntStack* stack, int max);

int Push(IntStack* stack, int num);

int Pop(IntStack* stack, int* num);

int Peek(const IntStack* stack, int* x);

void Clear(IntStack* stack);

int Capacity(const IntStack* stack);

int Size(const IntStack* stack);

int IsEmpty(const IntStack* stack);

int IsFull(const IntStack* stack);

int Search(const IntStack* stack, int num);

void Print(const IntStack* stack);

void Terminate(IntStack* stack);

#endif
