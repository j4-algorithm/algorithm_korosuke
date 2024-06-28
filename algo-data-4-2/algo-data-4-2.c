#include <stdio.h>

int sum(int *num, int begin, int end){
    if(end - begin == 1){
        return num[begin];
    }else{
        int mid = (begin + end) / 2;
        return sum(num, begin, mid) + sum(num, mid, end);
    }
}

int main(void){
    int num[1000] = {0};
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    int s = sum(num, 0, n);
    printf("%d\n", s);
    return 0;
}