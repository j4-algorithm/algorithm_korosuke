#include<stdio.h>
#include<stdbool.h>

int main(void)
{
    bool flag = true;
    int num1 = 0,num2 = 0, num3 = 0, num4 = 0, num5 = 0;
    int balls[10000] = {0};
    int balls2[10000] = {0};
    scanf("%d",&num1);
    for (int i = 0; i < num1; i++)
    {
        scanf("%d",&balls[i]);
    }

    for(int i = 0; i < num1; i++)
    {
        num5 = num5 + balls[i];
    }

    printf("%d\n", num5);

    while (flag)
    {
        num2 = num1 / 2;
        for (int i = num2; i > 0; i--)
        {
            balls2[num2 - i] = balls[num1 - i];
            balls[num1 - i] = 0;
        }
        num1 = num1 - num2;
        for(int i = 0; i < num1; i++)
        {
            num3 = num3 + balls[i];
            num4 = num4 + balls2[i];
        }
        if(num3 % 100 != 0)
        {
            printf("%d\n", num3);
            if(num3 - 100 < 10){
                flag = false;
            }else{
                num3 = 0;
                num4 = 0;
            }
        }   
        if(num4 % 100 != 0)
        {
            printf("%d\n", num4);
            if(num4 - 100 < 10){
                flag = false;
            }else{
                num3 = 0;
                num4 = 0;
            }
        }   
    }
       
    return 0;
}