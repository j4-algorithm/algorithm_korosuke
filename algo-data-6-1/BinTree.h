#ifndef ___BinTree
#define ___BinTree

typedef struct __Binode {
    int data;
    struct __Binode *left;
    struct __Binode *right;
} BinNode;

BinNode *Add(BinNode *p, int x);
void FreeTree(BinNode *p);
void PrintPreorder(BinNode *p, int *counter);
void PrintInorder(BinNode *p, int *counter);
void PrintPostorder(BinNode *p, int *counter);

#endif