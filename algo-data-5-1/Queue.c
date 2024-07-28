#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
#include "BinTree.h"

int Initialize(Queue* queue, int max){
    queue->num = queue->front = queue->rear = 0;
    queue->que = calloc(max, sizeof(BinNode));
    if(queue->que == NULL){
        queue->max = 0;
        return -1;
    }
    queue->max = max;
    return 0;
}

int Enque(Queue* queue, BinNode data){
    if (queue->num >= queue->max){
        return -1;
    }
    else {
        queue->num++;
        queue->que[queue->rear++] = data;

        if (queue->rear == queue->max){
            queue->rear = 0;
        }
        return 0;
    }
}

int Deque(Queue* queue, BinNode* data){
    if (queue->num <= 0){
        return -1;
    }
    else {
        queue->num--;
        *data = queue->que[queue->front++];
        if (queue->front == queue->max){
            queue->front = 0;
        }
    }
    return 0;
}

int IsEmpty(Queue* queue){
    if (queue->num <= 0){
        return 1;
    }
    else {
        return 0;
    }
    return 0;
}

void Terminate(Queue* queue){
    if (queue->que != NULL){
        free(queue->que);
    }
    queue->max = queue->num = queue->front = queue->rear = 0;
}