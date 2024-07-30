#include<stdio.h>

void move(int no, int x, int y, int *count);

int main(void){
    int n = 0;
    int count = 0;
    printf("n?:");
    scanf("%d", &n);
    move(n, 1, 3, &count);
    printf("%d\n", count);
    return 0;
}

void move(int no, int x, int y, int *count)
{
    (*count)++;
    if(no > 1){
        move(no - 1, x, 6 - x - y, count);
    }
    printf("%d %d %d\n", no, x, y);
    if(no > 1){
        move(no - 1, 6 - x - y, y, count);
    }
}