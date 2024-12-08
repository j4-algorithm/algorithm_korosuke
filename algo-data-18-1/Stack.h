#include <stdio.h>
#define SIZE 100 // スタックのサイズ

struct STACK {
    int elm[SIZE]; // 各要素
    int top; // データがどの場所まであるかを記憶
} ;
 
// 初期化関数　STACKがポインタなのは参照渡しにするため
void init(struct STACK *s) {
    s->top = -1; // スタックが空 -> -1
}
 
// 出力関数　STACKがポインタなのは参照渡しにするため
void print(struct STACK *s){
    printf("スタックの中身:");
    for(int i = 0; i <= s->top; i += 1) {
        printf("%d ",s->elm[i]);
    }
    printf("\n");
}
 
// push関数　STACKが（以下省略）
void push(int x, struct STACK *s){
    s->top += 1; // データの場所が1つ増やす
    s->elm[s->top] = x; // 要素格納
}
 
// pop関数　
int pop(struct STACK *s){
    int out_data = s->elm[s->top]; // 出力する要素
    s->top -= 1; // データの場所が1つ減る
    return out_data;
}
 
// スタックが空か判定
int isEmpty(struct STACK *s){
    if(s->top != -1) {
        return 0;
    }
    else {
        return 1;
    }
}
