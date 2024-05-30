#include <stdio.h>
#include <stdlib.h>
#include "algo-data-3-2.h"

typedef enum{
	enque = 1,
	deque, // 2
	peek, // 3
	print_queue, // 4
	clear_Print, // 5
	que_Capacity, // 6
	que_Size, // 7
	is_Empty, // 8
	is_Full, // 9
	search, // 10
	finish // 11
}Mode;

int InitQueue(IntQueue* queue, int max){
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

void ClearQueue(IntQueue* queue){
	queue->curr_num_data = queue->front = queue->rear = 0;
}

int GetQueueCapacity(const IntQueue* queue){
	return queue->max_size;
}

int GetQueueSize(const IntQueue* queue){
	return queue->curr_num_data;
}

int IsEmptyQueue(const IntQueue* queue){
	return queue->curr_num_data <= 0;
}

int IsFullQueue(const IntQueue* queue){
	return queue->curr_num_data >= queue->max_size;
}

int SearchQueue(const IntQueue* queue, int num){
	for (int i = 0; i < queue->curr_num_data; i++){
		if (queue->que[(i + queue->front) % queue->max_size] == num){
			return i;
		}
	}
	return -1;
}

void PrintQueue(const IntQueue* queue){
	for (int i = 0; i < queue->curr_num_data; i++){
		printf("%d\n", queue->que[(i + queue->front) % queue->max_size]);
	}
}

void TerminateQueue(IntQueue* queue){
	if (queue->que != NULL){
		free(queue->que);
	}
	queue->max_size = queue->curr_num_data = queue->front = queue->rear = 0;
}


int main(void){
	IntQueue queue;
	if (InitQueue(&queue, 10000) == -1){
		puts("Failed to create queue.");
		return 1;
	}
	Mode mode = enque;
	int num = 0;
	while (mode != finish){
		scanf("%d", (int*)&mode);
		if (mode == enque){
			scanf("%d", &num);
			//printf("enque:");
			Enque(&queue, num);
			printf("%d\n", num);
		}
		else if (mode == deque){
			scanf("%d", &num);
			//printf("deque:");
			Deque(&queue, &num);
			printf("%d\n", num);
		}
		else if (mode == peek){
			//printf("peek:");
			Peek(&queue, &num);
			//printf("%d\n", num);
		}
		else if (mode == print_queue){
			//printf("printQueue:\n");
			PrintQueue(&queue);
		}
		else if (mode == clear_Print){
			//printf("clear_Print:\n");
			ClearQueue(&queue);
			num = GetQueueSize(&queue);
			printf("%d\n", num);
		}
		else if (mode == que_Capacity){
			//printf("que_Capacity:");
			num = GetQueueCapacity(&queue);
			printf("%d\n", num);
		}
		else if (mode == que_Size){
			//printf("que_Size:");
			num = GetQueueSize(&queue);
			printf("%d\n", num);
		}
		else if (mode == is_Empty){
			//printf("is_Empty:");
			num = IsEmptyQueue(&queue);
			printf("%d\n", num);
		}
		else if (mode == is_Full){
			//printf("is_Full:");
			num = IsFullQueue(&queue);
			printf("%d\n", num);
		}
		else if (mode == search){
			scanf("%d", &num);
			//printf("search:");
			num = SearchQueue(&queue, num);
			printf("%d\n", num);
		}
		else if (mode == finish){
			printf("finish\n");
			TerminateQueue(&queue);
		}
		else {
			printf("Invalid mode.");
		}
	}
	
	return 0;
}
