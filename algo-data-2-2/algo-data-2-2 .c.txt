#include<stdio.h>

int num(double x ){
    int a = (int)x;
    if(x == a){
        return a;
    }else{
        return a + 1;
    }
}

int main(void)
{
    int first = 0;
    int harf = 0;
    int end = 0;
    int num_balls = 0;
    int balls[10000] = {0};
    scanf("%d",&end);
    for (int i = 0; i < end; i++)
    {
        scanf("%d",&balls[i]);
    }
    for(int i = 0; i < end; i++)
        {
            num_balls = num_balls + balls[i];
        }
    printf("%d\n", num_balls);

    while (end - first > 1)
    {
        harf = num((first+end) / 2.0);
        num_balls = 0;
        for(int i = first; i < harf; i++)
        {
            num_balls = num_balls + balls[i];
        }
        if (num_balls % 100 != 0)
        {
            printf("%d\n", num_balls);
            end = harf;
        }
        else
        {
            num_balls = 0;
            for(int i = harf; i < end; i++)
            {
                num_balls = num_balls + balls[i];
            }
            printf("%d\n", num_balls);
            first = harf;
        }
        
    }
    return 0;
}