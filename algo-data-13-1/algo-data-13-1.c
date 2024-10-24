#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y, int* count3)
{
    int t = *x;
    *x = *y;
    *y = t;
    (*count3)++;
}

static void downheap(int a[], int left, int right, int* count2, int* count3)
{
    (*count2)++;
    int temp = a[left];
    int child;
    int parent;

    for(parent = left; parent < (right + 1) / 2; parent = child){
        int cl = parent * 2 + 1;
        int cr = cl + 1;
        child = (cr <= right && a[cr] > a[cl]) ? cr : cl;
        if(temp >= a[child]){
            break;
        }
        a[parent] = a[child];
    }
    a[parent] = temp;
}

void heapsort(int a[], int n, int* count1, int* count2, int* count3)
{
    (*count1)++;
    int i;
    for(i = (n - 1) / 2; i >= 0; i--){
        downheap(a, i, n - 1, count2, count3);
    }
    for(i = n - 1; i > 0; i--){
        swap(&a[0], &a[i], count3);
        downheap(a, 0, i - 1, count2, count3);
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
    heapsort(x, nx, &count1, &count2, &count3);
    for(int i = 0; i < nx; i++){
        printf("%d ", x[i]);
    }
    printf("\n%d\n", count2);
    printf("%d\n", count3);
    free(x);
    return 0;
}