#ifndef ___BinTree
#define ___BinTree

typedef struct __Binode {
    int data;
    struct __Binode *left;
    struct __Binode *right;
} BinNode;

BinNode *Add(BinNode *p, int x);
void FreeTree(BinNode *p);

#endif