#include <stdio.h>
#include <stdlib.h>
#include "Member.h"

typedef struct __node {
	Member         data;	
	struct __node *next;
} Node;


typedef struct {
	Node *head;		
	Node *crnt;	
} List;

void PrintCurrent(const List *list){
    if (list->crnt != NULL){
    }else{
        PrintMember(&list->crnt->data);
    }
}

void PrintLnCurrent(const List *list){
    PrintCurrent(list);
    putchar('\n');
}

void PrintMember(const Member *x){
    printf("%d\n", x->no);
}

int MemberNoCmp(const Member *x, const Member *y){
    return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
}

void PrintLnMember(const Member *x){
    printf("%d ", x->no);
}