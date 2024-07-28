#ifndef __Queue
#define __Queue
#include "BinTree.h"

typedef struct {
    int max;
    int num;
    int front;
    int rear;
    int** que;
} Queue;

int Initialize(Queue* queue, int max, int size);
int Enque(Queue* queue, BinNode* data);
int Deque(Queue* queue, BinNode* data);
int IsEmpty(Queue* queue);
void Terminate(Queue* queue);

#endif