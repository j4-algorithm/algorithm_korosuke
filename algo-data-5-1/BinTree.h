#ifndef ___BinTree
#define ___BinTree

typedef struct __Binode {
    void *data;
    struct __Binode *left;
    struct __Binode *right;
} BinNode;

BinNode *Add(BinNode *p, const int *x);
void FreeTree(BinNode *p);

#endif