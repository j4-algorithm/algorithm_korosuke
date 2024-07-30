#include<stdio.h>
#include<stdlib.h>
#include"ClosedHash.h"

static int hash(int key, int size){
    return key % size;
}

static int rehash(int key, int size){
    return (key + 1) % size;
}

static void SetBucket(Bucket *n, int data, Status stat){
    n->data = data;
    n->stat = stat;
}

int Initialize(ClosedHash *h, int size){
    h->size = size;
    if((h->table = calloc(size, sizeof(Bucket))) == NULL){
        h->size = 0;
        return 0;
    }
    for(int i = 0; i < size; i++){
        h->table[i].stat = Empty;
    }
    return 1;
}

Bucket *Search(const ClosedHash *h, int data){
    int key = hash(data, h->size);
    Bucket *p = h->table[key];
    for(int i = 0; p->stat != Empty && i < h->size; i++){
        if(p->stat == Occupied && p->data == data){
            return p;
        }
        key = rehash(key, h->size);
        p = &h->table[key];
    }
    return NULL;
}

int Add(ClosedHash *h, int data){
    int key = hash(data, h->size);
    Bucket *p = &h->table[key];
    if(Search(h, data) != NULL){
        return 1;
    }
    for(int i = 0; i < h->size; i++){
        if(p->stat == Empty || p->stat == Deleted){
            SetBucket(p, data, Occupied);
            return 0;
        }
        key = rehash(key, h->size);
        p = &h->table[key];
    }
    return 2;
}

int Remove(ClosedHash *h, int data){
    Bucket *p = Search(h, data);
    if(p == NULL){
        return 1;
    }
    p->stat = Deleted;
    return 0;
}

void Dump(const ClosedHash *h){
    for(int i = 0; i < h->size; i++){
        printf("%02d ", i);
        if(h->table[i].stat == Occupied){
            printf("%d\n", h->table[i].data);
        }else if(h->table[i].stat == Empty){
            printf("Empty\n");
        }else{
            printf("Deleted\n");
        }
    }
}

void Clear(ClosedHash *h){
    for(int i = 0; i < h->size; i++){
        h->table[i].stat = Empty;
    }
}

void Terminate(ClosedHash *h){
    Clear(h);
    free(h->table);
    h->size = 0;
}
