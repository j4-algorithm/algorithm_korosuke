#include <stdio.h>
#include <stdlib.h>
#include "algo-data-3-1.h"

int Initialize(IntStack* stack, int max){
    stack->ptr = 0;
    stack->stk = calloc(max, sizeof(int));

    if(stack->stk == NULL){
        stack->max_size = 0;
        return -1;
    }
    stack->max_size = max;
    return 0;
}

int Push(IntStack* stack, int num){
    if (IsFull(stack)){
        return -1;
    }
    stack->stk[stack->ptr] = num;
    stack->ptr++;

    return 0;
}

int Pop(IntStack* stack, int* num){
    if (IsEmpty(stack)){
        return -1;
    }
    stack->ptr--;
    *num = stack->stk[stack->ptr];
    return 0;
}

int Peek(const IntStack* stack, int* num){
    if (IsEmpty(stack)){
        return -1;
    }
    *num = stack->stk[stack->ptr - 1];
    return 0;
}

void Clear(IntStack* stack){
    stack->ptr = 0;
}

int Capacity(const IntStack* stack){
    return stack->max_size;
}

int Size(const IntStack* stack){
    return stack->ptr;
}

int IsEmpty(const IntStack* stack){
    if (stack->ptr <= 0){
        return 1;
    }
    else {
        return 0;
    }
    return 0;
}

int IsFull(const IntStack* stack){
    if (stack->ptr >= stack->max_size){
        return 1;
    }
    else {
        return 0;
    }
    return 0;
}

int Search(const IntStack* stack, int num){
    for (int i = 0; i < stack->ptr; i++){
        if (stack->stk[i] == num){
            return i;
        }
    }
    return -1;
}

void Print(const IntStack* stack){
    for (int i = stack->ptr - 1; i >= 0 ; i--){
        printf("%d\n", stack->stk[i]);
    }
}

void Terminate(IntStack* stack){
    if (stack->stk != NULL){
        free(stack->stk);
    }
    stack->max_size = 0;
    stack->ptr = 0;
}

int main(void){
    IntStack s;
    Initialize(&s, 10000);
    int mode = 0;
    int num = 0;
    while(mode != 11){
        scanf("%d", &mode);
        if(mode == 1){
            scanf("%d", &num);
            Push(&s, num);
            printf("%d\n", num);
        }
        else if(mode == 2){
            Pop(&s, &num);
            printf("%d\n", num);
        }
        else if(mode == 3){
           Peek(&s, &num);
           printf("%d\n", num);
        }
        else if(mode == 4){
            Print(&s);
        }
        else if(mode == 5){
            Clear(&s);
            num = Size(&s);
            printf("%d\n", num);
        }
        else if(mode == 6){
            num = Capacity(&s);
            printf("%d\n", num);
        }
        else if(mode == 7){
            num = Size(&s);
            printf("%d\n", num);
        }
        else if(mode == 8){
            num = IsEmpty(&s);
            printf("%d\n", num);
        }
        else if(mode == 9){
            num = IsFull(&s);
            printf("%d\n", num);
        }
        else if(mode == 10){
            scanf("%d", &num);
            num = Search(&s, num);
            printf("%d\n", num);
        }
    }

    return 0;
}