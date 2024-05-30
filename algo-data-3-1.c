#include "algo-data-3-1.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef enum {
	push = 1,
	pop,
	peek,
	print,
	clear_print,
	stack_capacity,
	stack_size,
	isempty,
	isfull,
	search,
	finish
}Mode;

int InitStack(IntStack* stack, int max){
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
	if (IsFullStack(stack)){
		return -1;
	}
	stack->stk[stack->ptr] = num;
	stack->ptr++;

	return 0;
}

int Pop(IntStack* stack, int* num){
	if (IsEmptyStack(stack)){
		return -1;
	}
	stack->ptr--;
	*num = stack->stk[stack->ptr];
	return 0;
}

int Peek(const IntStack* stack, int* num){
	if (IsEmptyStack(stack)){
		return -1;
	}
	*num = stack->stk[stack->ptr - 1];
	return 0;
}

void ClearStack(IntStack* stack){
	stack->ptr = 0;
}

int GetStackCapacity(const IntStack* stack){
	return stack->max_size;
}

int GetStackSize(const IntStack* stack){
	return stack->ptr;
}

int IsEmptyStack(const IntStack* stack){
	if (stack->ptr <= 0){
		return 1;
	}
	else {
		return 0;
	}
	return 0;
}

int IsFullStack(const IntStack* stack){
	if (stack->ptr >= stack->max_size){
		return 1;
	}
	else {
		return 0;
	}
	return 0;
}

int SearchStack(const IntStack* stack, int num){
	for(int i = 0; i < stack->ptr; i++){
		if(stack->stk[i] == num){
			return i;
		}
	}	
	return -1;
}

void Print(const IntStack* stack){
	for(int i = stack->ptr -1 ; i >= 0; i--){
		printf("%d\n", stack->stk[i]);
	}
}

void TerminateStack(IntStack* stack){
	if(stack->stk != NULL){
		free(stack->stk);
	}
	stack->max_size = stack->ptr = 0;
}

int main(void){
	IntStack stack;
	InitStack(&stack, 10000);
	Mode mode = push;
	int num = 0;
	while(mode != finish){
		scanf("%d", (int*)&mode);
		if(mode == push){
			scanf("%d", &num);
			Push(&stack, num);
			printf("%d\n", num);
		}
		else if(mode == pop){
			Pop(&stack, &num);
			printf("%d\n", num);
		}
		else if(mode == peek){
			Peek(&stack, &num);
			printf("%d\n", num);
		}
		else if(mode == print){
			Print(&stack);
		}
		else if(mode == clear_print){
			//printf("clear_print\n");
			ClearStack(&stack);
			num = GetStackSize(&stack);
			printf("%d\n", num);
		}
		else if(mode == stack_capacity){
			num = GetStackCapacity(&stack);
			printf("%d\n", num);
		}
		else if(mode == stack_size){
			num = GetStackSize(&stack);
			printf("%d\n", num);
		}
		else if(mode == isempty){
			num = IsEmptyStack(&stack);
			printf("%d\n", num);
		}
		else if(mode == isfull){
			num = IsFullStack(&stack);
			printf("%d\n", num);
		}
		else if(mode == search){
			scanf("%d", &num);
			num = SearchStack(&stack, num);
			printf("%d\n", num);
		}
		else if(mode == finish){
			TerminateStack(&stack);
		}
		else{
		}
	}
	return 0;
}
