#include<stdio.h>
#include<stdlib.h>
#include "BinTree.h"

static BinNode *AllocBinNode(void){
    return calloc(1, sizeof(BinNode));
}

static void SetBinNode(BinNode *n, int x, BinNode *left, BinNode *right){
    n->data = x;
    n->left = left;
    n->right = right;
}

BinNode *Add(BinNode *p,int x){
    if (p == NULL){
        p = AllocBinNode();
        SetBinNode(p, x, NULL, NULL);
    }else if (x < p->data){
        p->left = Add(p->left, x);
    }else if (x > p->data){
        p->right = Add(p->right, x);
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

void PrintPreorder(BinNode *p, int *counter){
    if (p != NULL){
        printf("%d %d\n", ++(*counter), p->data);
        if(p->left != NULL){
            PrintPreorder(p->left, counter);
        }
        if(p->right != NULL){
            PrintPreorder(p->right, counter);
        }
    }
}

void PrintInorder(BinNode *p, int *counter){
    if (p != NULL){
        if(p->left != NULL){
            PrintInorder(p->left, counter);
        }
        printf("%d %d\n",++(*counter), p->data);
        if(p->right != NULL){
        PrintInorder(p->right, counter);
        }
    }
}

void PrintPostorder(BinNode *p, int *counter){
    if (p != NULL){
        if(p->left != NULL){
            PrintPostorder(p->left, counter);
        }
        if(p->right != NULL){
            PrintPostorder(p->right, counter);
        }
        printf("%d %d\n",++(*counter), p->data);
    }
}

