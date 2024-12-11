#include "stdio.h"
#include "string.h"
#include "limits.h"

#define SIZE 1024

int boyerMoore(char* text, char* pattern) {
    int pt;
    int pp;
    int text_LEN = strlen(text);
    int pattern_LEN = strlen(pattern);
    int skip[UCHAR_MAX + 1];

    for (pt = 0; pt <= UCHAR_MAX; pt++) {
        skip[pt] = pattern_LEN;
    }
    for (pt = 0; pt < pattern_LEN - 1; pt++) {
        skip[pattern[pt]] = pattern_LEN - pt - 1;
    }

    while (pt < text_LEN) {
        pp = pattern_LEN - 1;
        while (text[pt] == pattern[pp]) {
            if (pp == 0) {
                return pt;
            }
            pp--;
            pt--;
        }
        pt += (skip[text[pt]] > pattern_LEN - pp) ? skip[text[pt]] : pattern_LEN - pp;
    }

    return -1;
}       

int main(void) {
    char text[SIZE];
    char pattern[SIZE];
    printf("テキスト：");
    scanf("%s", text);
    printf("パターン：");
    scanf("%s", pattern);

    int result = boyerMoore(text, pattern);

    printf("開始位置：%d\n", result+1);

    return 0;
}            