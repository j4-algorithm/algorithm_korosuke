#include <stdio.h>
#include <stdbool.h>
#include "BinTree.h"
#include "Member.h"

int main(void){
    BinNode *root = NULL;
    bool isEnd = false;
    while(!isEnd){
        int mode = 0;
        scanf("%d", &mode);
        if(mode == 1){
            Member x;
            scanf("%d", &x.no);
            BinNode* result = Search(root, &x);
            if(result != NULL){
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
        else if(mode == 2){
            Member x;
            scanf("%d", &x.no);
            root = Add(root, &x);
        }
        else if(mode == 3){
            Member x;
            scanf("%d", &x.no);
            Remove(&root, &x);
        }
        else if(mode == 4){
            PrintTree(root);
            printf("\n");
        }
        else if(mode == 5){
            FreeTree(root);
            root = NULL;
        }
        else {
            isEnd = true;
        }
    }
}