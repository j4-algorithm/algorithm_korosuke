#include<stdio.h>
#include<stdlib.h>
#include "BinTree.h"


int main(void){
    int p = 0;
    int n = 0;
    int x = 0;
    int counter = 0;
    BinNode *tree = NULL;
    scanf("%d", &p);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        tree = Add(tree, x);
    }
    if(p == 0){
        printf("Error\n");
    }else if(p == 1){
        PrintPreorder(tree, &counter);
        printf("\n");
    }else if(p == 2){
        PrintInorder(tree, &counter);
        printf("\n");
    }else if(p == 3){
        PrintPostorder(tree, &counter);
        printf("\n");
    }
    FreeTree(tree);
}