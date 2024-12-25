#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_NUM_MATRIX 65534

double comp(int length, char *input){
    char *output = (char *)malloc(length * 2);
    int index = 0;
    int count = 1;
    for (int i = 1; i < length; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            index += sprintf(output + index, "%d%c", count, input[i - 1]);
            count = 1;
        }
    }
    index += sprintf(output + index, "%d%c", count, input[length - 1]);
    
    printf("%s\n", output);
    int output_length = strlen(output);
    free(output);
    double result = output_length / (double)length;
    return result;
}

int decomp(int length, char *input){
    char *output = (char *)malloc(length * 10);
    int index = 0;

    for (int i = 0; i < length; i++) {
        int count = 0;
        while (isdigit(input[i])) {
            count = count * 10 + (input[i] - '0');
            i++;
        }


        if (i < length && count > 0) {
            char character = input[i];
            for (int j = 0; j < count; j++) {
                output[index++] = character;
            }
        } else {
            printf("エラー\n");
            free(output); 
            return 0;
        }
    }

    output[index] = '\0';
    printf("%s\n", output);
    free(output);
    return 0;
}

int main(void){
    int n;
    int length;
    char input[MAX_NUM_MATRIX];
    scanf("%d", &n);
    scanf("%d", &length);
    scanf("%s", input);
    if(n == 1){
        printf("%f\n", comp(length, input));
    }else if (n == 2){
        decomp(length, input);
    }
    return 0;
        
}