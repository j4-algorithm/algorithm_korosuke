#include<stdio.h>
#include "Stack.h"

int main(void){
    int n, start;
    scanf("%d",&n);
    int E[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&E[i][j]);
        }
    }
    scanf("%d",&start);
    struct STACK s;
    init(&s);
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    push(start - 1,&s);
    visited[start - 1] = 1;
    int visitnums[n];
    int k = 0;
    while (!isEmpty(&s))
    {
        int v = pop(&s);
        visited[v] = 1;
        visitnums[k] = v + 1;
        k += 1;
        for (int i = 0; i < n; i++)
        {
            if (E[v][i] == 1 && visited[i] == 0)
            {
                push(i, &s);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",visitnums[i]);
    }
    return 0;
}


