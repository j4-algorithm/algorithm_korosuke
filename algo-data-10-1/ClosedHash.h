#ifndef ___ClosedHash
#define ___ClosedHash

typedef enum {
    Occupied, Empty, Deleted
}Status;

typedef struct {
    int data;
    Status stat;
}Bucket;

typedef struct {
    int size;
    Bucket *table;
}ClosedHash;

int Initialize(ClosedHash *h, int size);

Bucket *Search(const ClosedHash *h, int data);

int Add(ClosedHash *h, int data);

int Remove(ClosedHash *h, int data);

void Dump(const ClosedHash *h);

void Clear(ClosedHash *h);

void Terminate(ClosedHash *h);

#endif