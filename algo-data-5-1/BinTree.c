#include<stdio.h>
#include<stdlib.h>
#include "BinTree.h"

static BinNode *AllocBinNode(void){
    return calloc(1, sizeof(BinNode));
}

static void SetBinNode(BinNode *n, const int *x, BinNode *left, BinNode *right){
    n->data = *x;
    n->left = left;
    n->right = right;
}

BinNode *Add(BinNode *p, const int *x){
    if (p == NULL){
        p = AllocBinNode();
        SetBinNode(p, x, NULL, NULL);
    }else if (*x < p->data){
        p->left = Add(p->left, x);
    }else if (*x > p->data){
        p->right = Add(p->right, x);
    }else{
        printf("The data is already exist.\n");
    }
    return p;
}

void FreeTree(BinNode *p) {
    if (p != NULL) {
        FreeTree(p->left);
        FreeTree(p->right);
        free(p);
    }
    p = NULL;
}
