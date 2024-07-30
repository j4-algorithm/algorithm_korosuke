#include<stdio.h>
#include<stdlib.h>
#include"ClosedHash.h"

int main(void){
    ClosedHash h;
    int data;
    int mode;
    int result;
    Initialize(&h, 10000);
    scanf("%d", &mode);
    if(mode == 1){
        scanf("%d", &data);
        result = Add(&h, data);
    return 0;
}