#include<stdio.h>
#include<stdlib.h>
#include "BinTree.h"
#include "Queue.h"
#define TREE_HIGHT_MAX 10

int search(BinNode *root, Queue *que, int searchdata){
    BinNode* node ;
    int data = 0;
    Deque(que, node);
    data = node->data;
    if(node->left != NULL){
        Enque(que, node->left);
    }
    if(node->right != NULL){
        Enque(que, node->right);
    }
    return data;
}

int main(void){
    int numnodes = 10000000;
    Queue que;
    BinNode *root = NULL;
    Initialize(&que,sizeof(BinNode*), numnodes);
    int datanum;
    int nodedata;
    scanf("%d", &datanum);
    if(datanum > 2047){
        printf("多すぎます\n");
        scanf("%d", &datanum);
    }
    for(int i = 0; i < datanum; i++){
        scanf("%d", &nodedata);
        root = Add(root, &nodedata);
    }
    printf("探索するデータを入力してください\n");
    int searchdata;
    scanf("%d", &searchdata);
    Enque(&que, root);
    int quedata;
    while (searchdata  != quedata)
    {
        quedata = search(root, &que, searchdata);
        printf("%d\n", quedata);
    }
    FreeTree(root);
    Terminate(&que);
    return 0;
}