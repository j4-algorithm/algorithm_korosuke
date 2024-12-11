#include <stdio.h>

int kmp_match(const char txt[], const char searchPattern[]){
    int pt = 1;
    int pp = 0;
    int skip[1024];

    skip[pt] = 0;
    while (searchPattern[pt] != '\0') {
        if (searchPattern[pt] == searchPattern[pp]){
            skip[++pt] = ++pp;
        } else if (pp == 0){
            skip[++pt] = pp;
        } else {
            pp = skip[pp];
        }
    }
    pt = pp = 0;
    while (txt[pt] != '\0' && searchPattern[pp] != '\0') {
        if (txt[pt] == searchPattern[pp]) {
            pt++;
            pp++;
        } else if (pp == 0) {
            pt++;
        } else {
            pp = skip[pp];
        }
    }

    if (searchPattern[pp] == '\0'){
        return pt - pp;
    }

    return -1;
}

int main(void){
    char txt[1024];
    char textPattern[1024];

    printf("テキスト：");
    scanf("%s", txt);
    printf("パターン：");
    scanf("%s", textPattern);

    int result = kmp_match(txt, textPattern);
    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("一致なし\n");
    }
    return 0;
}
    