#include <stdio.h>

int sum(int *num, int begin, int end, int *counter){
    (*counter)++;
    if(end - begin == 1){
        return num[begin];
    }else{
        int mid = (begin + end) / 2;
        return sum(num, begin, mid, counter) + sum(num, mid, end, counter);
    }
}

int main(void){
    int num[1000] = {0};
    int n = 0;
    int count = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    int s = sum(num, 0, n, &count);
    printf("%d\n", s);
    printf("%d\n", count);
    return 0;
}