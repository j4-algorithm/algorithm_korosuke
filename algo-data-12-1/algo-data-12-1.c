#include<stdio.h>
#include<stdlib.h>

void insertion(int a[], int n, int* count)
{
    for(int i = 1; i < n; i++){
        int tmp = a[i];
        int j = 0;
        (*count)++;
        for(j = i; j > 0 && a[j - 1] > tmp; j--){
            a[j] = a[j - 1];
            (*count)++;
        }
        a[j] = tmp;
    }
}

int main(void){
    int num;
    scanf("%d", &num);
    int* a = calloc(num, sizeof(int));
    for(int i = 0; i < num; i++){
        scanf("%d", &a[i]);
    }
    int count = 0;
    insertion(a, num, &count);
    for(int i = num-1; i >= 0; i--){
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("%d\n", count);
    free(a);
    return 0;
}