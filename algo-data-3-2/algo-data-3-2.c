#include <stdio.h>
#include <stdlib.h>
#include "algo-data-3-2.h"

int Initialize(IntQueue* queue, int max){
    queue->curr_num_data = queue->front = queue->rear = 0;
    if((queue->que = calloc(max, sizeof(int))) == NULL){
        queue->max_size = 0;
        return -1;
    }
    queue->max_size = max;
    return 0;
}

int Enque(IntQueue* queue, int num){
    if (queue->curr_num_data >= queue->max_size){
        return -1;
    }
    else {
        queue->curr_num_data++;
        queue->que[queue->rear++] = num;

        if (queue->rear == queue->max_size){
            queue->rear = 0;
        }
        return 0;
    }
}

int Deque(IntQueue* queue, int* num){
    if (queue->curr_num_data <= 0){
        return -1;
    }
    else {
        queue->curr_num_data--;
        *num = queue->que[queue->front++];
        if (queue->front == queue->max_size){
            queue->front = 0;
        }
    }
    return 0;
}

int Peek(const IntQueue* queue, int* num){
    if (queue->curr_num_data <= 0){
        return -1;
    }
    else {
        *num = queue->que[queue->front];
    }
    return 0;
}

void Clear(IntQueue* queue){
    queue->curr_num_data = queue->front = queue->rear = 0;
}

int Capacity(const IntQueue* queue){
    return queue->max_size;
}

int Size(const IntQueue* queue){
    return queue->curr_num_data;
}

int IsEmpty(const IntQueue* queue){
    if (queue->curr_num_data <= 0){
        return 1;
    }
    else {
        return 0;
    }
    return 0;
}

int IsFull(const IntQueue* queue){
    if (queue->curr_num_data >= queue->max_size){
        return 1;
    }
    else {
        return 0;
    }
}

int Search(const IntQueue* queue, int num){
    int i;
    for (i = 0; i < queue->curr_num_data; i++){
        if (queue->que[i] == num){
            return i;
        }
    }
    return -1;
}

void Print(const IntQueue* queue){
    int i;
    for (i = 0; i < queue->curr_num_data; i++){
        printf("%d\n", queue->que[(i + queue->front) % queue->max_size]);
    }
}

void Terminate(IntQueue* queue){
    if (queue->que != NULL){
        free(queue->que);
    }
    queue->max_size = queue->curr_num_data = queue->front = queue->rear = 0;
}

int main(void){
    IntQueue q;
    Initialize(&q, 10000);
    int mode = 0;
    int num= 0;
    while (mode !=11){
        scanf("%d", &mode);
        if(mode == 1){
            scanf("%d", &num);
            Enque(&q, num);
            printf("%d\n", num);
        }
        else if (mode == 2){
            Deque(&q, &num);
            printf("%d\n", num);
        }
        else if (mode == 3){
            Peek(&q, &num);
            printf("%d\n", num);
        }
        else if (mode == 4){
            Print(&q);
        }
        else if (mode == 5){
            Clear(&q);
            num = Size(&q);
            printf("%d\n", num);
        }
        else if (mode == 6){
            num = Capacity(&q);
            printf("%d\n", num);
        }
        else if (mode == 7){
            num = Size(&q);
            printf("%d\n", num);
        }
        else if (mode == 8){
            num = IsEmpty(&q);
            printf("%d\n", num);
        }
        else if (mode == 9){
            num = IsFull(&q);
            printf("%d\n", num);
        }
        else if (mode == 10){
            scanf("%d", &num);
            num = Search(&q, num);
            printf("%d\n", num);
        }
    }
    
    return 0;   
}
