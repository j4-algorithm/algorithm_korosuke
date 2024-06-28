#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

void PrintMember(const Member *x){
    printf("%d\n", x->no);
}

int MemberNoCmp(const Member *x, const Member *y){
    return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
}

static Node* AllocNode(void){
    return calloc(1, sizeof(Node));
}

static void SetNode(Node *n, const Member *x, Node *next){
    n->data = *x;
    n->next = next;
}

void Initialize(List *list){
    list->head = NULL;
    list->crnt = NULL;
}

Node *Search(List *list, const Member *x, int compare(const Member *x, const Member *y)){
    Node *ptr = list->head;
    while (ptr != NULL){
        if(compare(&ptr->data, x) == 0){
            list->crnt = ptr;
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void InserFront(List *list, const Member *x){
    Node *ptr = list->head;
    list->head = list->crnt = AllocNode();
    SetNode(list->head, x, ptr);
}

void InserRear(List *list, const Member *x){
    if(list->head == NULL){
        InserFront(list, x);
    }else{
        Node *ptr = list->head;
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = list->crnt = AllocNode();
        SetNode(ptr->next, x, NULL);
    }
}

void RemoveFront(List *list){
    if(list->head != NULL){
        Node *ptr = list->head->next;
        free(list->head);
        list->head = list->crnt = ptr;
    }
}

void RemoveRear(List *list){
    if(list->head != NULL){
        RemoveFront(list);
    }else{
        Node *ptr = list->head;
        Node *pre;
        while(ptr->next != NULL){
            pre = ptr;
            ptr = ptr->next;
        }
        pre->next = NULL;
        free(ptr);
        list->crnt = pre;
    }
}

void RemoveCurrent(List *list){
    if(list->head != NULL){
        if(list->crnt == list->head){
            RemoveFront(list);
        }else{
            Node *ptr = list->head;
            while (ptr->next != list->crnt){
                ptr = ptr->next;
            }
            ptr->next = list->crnt->next;
            free(list->crnt);
            list->crnt = ptr;
        } 
    }
}

void Clear(List *list){
    while(list->head != NULL){
        RemoveFront(list);
    }
    list->crnt = NULL;
}

void PrintCount(const List *list){
    int count = 0;
    Node *ptr = list->head;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    printf("%d\n", count);
}

void PrintLnCurrent(const List *list){
    PrintMember(&list->crnt->data);
    putchar('\n');
}

void Printcurrent(const List *list){
    Node *ptr = list->crnt;
    while (ptr != NULL){
        PrintMember(&ptr->data);
        ptr = ptr->next;
    }
}

void Print(const List *list){
    if(list->head == NULL){
    }else{
        Node *ptr = list->head;
        while(ptr != NULL){
        PrintMember(&ptr->data);
        ptr = ptr->next;
        }
    }
}

void Terminate(List *list){
    Clear(list);
}

int main(void){
    List l;
    Initialize(&l);
    int mode = 0; 
    while(mode != 10){
        scanf("%d", &mode);
        if(mode == 1){
            Member x;
            scanf("%d", &x.no);
            InserFront(&l, &x);
            printf("%d\n", x.no);
        }
        else if(mode == 2){
            Member x;
            scanf("%d", &x.no);
            InserRear(&l, &x);
            printf("%d\n", x.no);
        }
        else if(mode == 3){
            RemoveFront(&l);
        }
        else if(mode == 4){
            RemoveRear(&l);
        }
        else if(mode == 5){
            Member x;
            scanf("%d", &x.no);
            if(Search(&l, &x, MemberNoCmp) != NULL){
                RemoveCurrent(&l);
                printf("%d\n", x.no);
            }else{
                printf("-1\n");
            }
        }
        else if(mode == 6){
            Member x;
            scanf("%d", &x.no);
            if(Search(&l, &x, MemberNoCmp) != NULL){
                Printcurrent(&l);
            }else{
                printf("-1\n");
            }
        }
        else if(mode == 7){
            PrintCount(&l);
        }
        else if(mode == 8){
            Print(&l);
        }
        else if(mode == 9){
            Clear(&l);
            PrintCount(&l);
        }
        else{
        }
    }
    return 0;
}