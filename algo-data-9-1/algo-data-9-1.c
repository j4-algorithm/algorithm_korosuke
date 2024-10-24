#include<stdio.h>

int main(void){
    int n = 0;
    int k = 0;
    int data[10000] = {0};
    printf("n?:");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &data[i]);
    }
    printf("k?:");
    scanf("%d", &k);
    int left = 0;
    int right = n - 1;
    int mid =(left + right) / 2;
    for(int  i = 0;right - left >= 0; i++){
        if(data[mid] == k){
            printf("Found: %d %d\n", mid, data[mid]);
            break;
        }else if(data[mid] < k){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
        mid = (left + right) / 2; 
    }
    if(data[mid] != k){
        printf("Not Found:\n");
    }
    return 0;
}