#include<stdio.h>

int main(void)
{
    char numstring[10000] = {'\0'};
    printf("整数を入力してください\n");
    scanf("%s",numstring);
    int sum = 0;
    int k = 0;
    for (int i = 0; numstring[i] != '\0'; i++)
    {
        k = numstring[i] - '0';
        sum = sum + k;
    }
    printf("%d\n", sum);
    if (sum % 3 == 0){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}