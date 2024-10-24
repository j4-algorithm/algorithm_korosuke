#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y, int* count3)
{
    int t = *x;
    *x = *y;
    *y = t;
    (*count3)++;
}

int sort3elem(int x[], int a, int b, int c, int* count2, int* count3)
{
    (*count2)++;
    if(x[b] < x[a]){
        swap(&x[b], &x[a], count3);
    }
    if(x[c] < x[b]){ 
        swap(&x[c], &x[b], count3);
    }
    if(x[b] < x[a]){ 
        swap(&x[b], &x[a], count3);
    }
    return b;    
}


void quicksort(int a[], int left, int right, int* count1, int* count2, int* count3)
{
    (*count1)++;
    if(left < right){
        int pl = left;
        int pr = right;
        int m = sort3elem(a, pl, (pl + pr) / 2, pr, count2, count3);
        int x = a[m];
        swap(&a[m], &a[right - 1], count3);
        pl++;
        pr -= 2;
        do{
            while(a[pl] < x) pl++;
            while(a[pr] > x) pr--;
            if(pl <= pr){
                swap(&a[pl], &a[pr], count3);
                pl++;
                pr--;
            }
        }while(pl <= pr);
        if(left < pr) quicksort(a, left, pr, count1, count2, count3);
        if(pl < right) quicksort(a, pl, right, count1, count2, count3);
    }
}
int main(void){
    int nx;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));
    for(int i = 0; i < nx; i++){
        scanf("%d", &x[i]);
    }
    quicksort(x, 0, nx - 1, &count1, &count2, &count3);
    for(int i = 0; i < nx; i++){
        printf("%d ", x[i]);
    }
    printf("\n%d\n%d\n%d\n", count1, count2, count3);
    free(x);
    return 0;
}