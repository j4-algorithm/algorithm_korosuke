#ifndef ___IntQueue
#define ___IntQueue

typedef struct{
	int max_size;
	int curr_num_data;
	int front;
	int rear;
	int* que;
}IntQueue;

int Initialize(IntQueue* queue, int max);

int Enque(IntQueue* queue, int num);

int Deque(IntQueue* queue, int* num);

int Peek(const IntQueue* queue, int* num);

void Clear(IntQueue* queue);

int Capacity(const IntQueue* queue);

int Size(const IntQueue* queue);

int IsEmpty(const IntQueue* queue);

int IsFull(const IntQueue* queue);

int Search(const IntQueue* queue, int num);

void Print(const IntQueue* queue);

void Terminate(IntQueue* queue);

#endif
