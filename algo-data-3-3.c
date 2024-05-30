#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

Node* AllocNode(void){
    return calloc(1, sizeof(Node));
}

void SetNode(Node* n, const Member* x, const Node* next){
    n->data = *x;
    n->next = next;
}

void Initialize(List* list){
    list->head = NULL;
    list->crnt = NULL;
}

void InsertFront(List* list, const Member* x){
    Node* ptr = list->head; 
    list->head = list->crnt = AllocNode();
    SetNode(list->head, x, ptr);
}

void RemoveFront(List* list){
    if(list->head != NULL){
        Node* ptr = list->head->next;
        free(list->head);
        list->head = list->crnt = ptr;
    }
}

void InsertRear(List* list, const Member* x){
    if(list->head == NULL){
        InsertFront(list, x);
    }
    else{
        Node* ptr = list->head;
        while(ptr != NULL){
            ptr = ptr->next;
        }
        ptr->next = list->crnt = AllocNode();
        SetNode(ptr->next, x, NULL);
    }
}

void RemoveRear(List* list){
    if(list->head != NULL){
        if(list->head->next == NULL){
            RemoveFront(list);
        }
        else{
            Node* ptr = list->head;
            Node* pre;
            while(ptr->next != NULL){
                pre = ptr;
                ptr = ptr->next;
            }
            pre->next = NULL;
            free(ptr);
            list->crnt = pre;
        }
    }
}

Node *Search(List *list, const Member *x, int compare(const Member *x, const Member *y)){
    Node* ptr = list->head;
    while(ptr != NULL){
        if(compare(&ptr->data, x) == 0) {
            list->crnt = ptr;
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void RemoveCurrent(List* list){
    if(list->head != NULL){
        if(list->crnt == list->head){
            RemoveFront(list);
        }
        else{
            Node* ptr = list->head;
            while(ptr->next != list->crnt) { 
                ptr = ptr->next;
            }
            ptr->next = list->crnt->next;
            free(list->crnt);
            list->crnt = ptr;
        }
    }
}

void Clear(List* list){
    while(list->head != NULL) {
        RemoveFront(list);
    }
    list->crnt = NULL;
}

void PrintCurrent(const List* list){
    if(list->crnt == NULL){
        printf("着目ノードはありません。");
    }
    else{
        PrintMember(&list->crnt->data);
    }
}

void PrintLnCurrent(const List* list){
    PrintCurrent(list);
    putchar('\n');
}

void Print(const List* list){
    if(list->head == NULL){
        puts("ノードがありません。");
    }
    else{
        Node* ptr = list->head;
        puts("【一覧表】");
        while(ptr != NULL){
            PrintMember(&ptr->data);
            ptr = ptr->next;
        }
    }
}

void Terminate(List* list){
    Clear(list);
}


int main(void){
    List list;
    Initialize(&list);
    int mode = 0;
    while (mode != 10){
        scanf("%d", &mode);
        if (mode == 1){
            Member x;

            InsertFront(&list, &x);

        }
        else if (mode == 2){
                printf("mode2\n");
        }
        else if (mode == 3){
                printf("mode3\n");
        }
        else if (mode == 4){
                printf("mode4\n");
        }
        else if (mode == 5){
                printf("mode5\n");
        }
        else if (mode == 6){
                printf("mode6\n");
        }
        else if (mode == 7){
                printf("mode7\n");
        }
        else if (mode == 8){
                printf("mode8\n");
        }
        else if (mode == 9){
                printf("mode9\n");
        }
        else if (mode == 10){
                printf("mode10\n");
        }

    }
}






