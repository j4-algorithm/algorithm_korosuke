#ifndef ___IntQueue
#define ___IntQueue

typedef struct{
	int max_size;
	int curr_num_data;
	int front;
	int rear;
	int* que;
}IntQueue;

int InitQueue(IntQueue* queue, int max);

int Enque(IntQueue* queue, int num);

int Deque(IntQueue* queue, int* num);

int Peek(const IntQueue* queue, int* num);

void ClearQueue(IntQueue* queue);

int GetQueueCapacity(const IntQueue* queue);

int GetQueueSize(const IntQueue* queue);

int IsEmptyQueue(const IntQueue* queue);

int IsFullQueue(const IntQueue* queue);

int SearchQueue(const IntQueue* queue, int num);

void PrintQueue(const IntQueue* queue);

void TerminateQueue(IntQueue* queue);

#endif
