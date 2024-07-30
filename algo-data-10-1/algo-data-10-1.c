#include<stdio.h>
#include<stdlib.h>
#include"ClosedHash.h"

int main(void){
    ClosedHash h;
    int num;
    int data;
    int mode;
    int result;
    Initialize(&h, 13);
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        scanf("%d", &mode);
        if(mode == 1){
            scanf("%d", &data);
            result = Add(&h, &data);
        }else if(mode == 2){
            scanf("%d", &data);
            result = Remove(&h, &data);
            if(result == 1){
                printf("Not Found\n");
            }
        }else if(mode == 3){
            scanf("%d", &data);
            Bucket* temp;
            temp = Search(&h, &data);
            if(temp == NULL){
                printf("Not Found\n");
            }else{
                printf("Found\n");
            }
        }else if(mode == 4){
            Clear(&h);
        }else if(mode == 5){
            Dump(&h);
        }else if(mode == 0){
            Terminate(&h);
        }
    }
    
    return 0;
}