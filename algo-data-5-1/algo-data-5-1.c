#include<stdio.h>
#include<stdlib.h>
#include "BinTree.h"
#include "Queue.h"


int main(void){
    Queue que;
    BinNode *root = NULL;
    Initialize(&que,1023);
    int datanum;
    int nodedata;
    scanf("%d", &datanum);
    if(datanum > 2047){
        printf("多すぎます\n");
        scanf("%d", &datanum);
    }
    for(int i = 0; i < datanum; i++){
        scanf("%d", &nodedata);
        root = Add(root, nodedata);
    }
    Enque(&que, *root);
    BinNode tree;
    for(int i = 0; i < datanum; i++){
        Deque(&que, &tree);
        printf("%d %d\n",i+1, tree.data);
        if(tree.left != NULL){
            Enque(&que, *tree.left);
        }
        if(tree.right != NULL){
            Enque(&que, *tree.right);
        }
    }
   
    FreeTree(root);
    Terminate(&que);
    return 0;
}