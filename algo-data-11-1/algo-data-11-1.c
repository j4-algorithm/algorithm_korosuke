#include<stdio.h>
#include"ChainHash.h"
#include"Node.h"

int main(void){
    ChainHash hash;
    Initialize(&hash, 13);
    int result;
    int num;
    int mode;
    Node x;
    Node *temp;
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        scanf("%d", &mode);
        if(mode == 1){
            x = ScanNode();
            result = Add(&hash, &x.v);
            if(result){
                printf("Failed\n");
            }
        }else if(mode == 2){
            x = ScanNode();
            result = Remove(&hash, &x.v);
            if(result == 1){
                printf("Not Found\n");
            }
        }else if(mode == 3){
            x = ScanNode();
            temp = Search(&hash, &x.v);
            if(temp == NULL){
                printf("Not Found\n");
            }else{
                printf("Found\n");
            }
        }else if(mode == 4){
            Clear(&hash);
        }else if(mode == 5){
            Dump(&hash);
        }else if(mode == 0){
            Terminate(&hash);
        }
    }
    return 0;
}