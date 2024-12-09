#include <stdio.h>

int kmp_match(const char txt[], const char patern[]){
    int pt = 1;
    int pp = 0;
    int skip[1024];

    skip[pt] = 0;
    while (patern[pt] != '\0') {
        if (patern[pt] == patern[pp]){
            skip[++pt] = ++pp;
        } else if (pp == 0){
            skip[++pt] = pp;
        } else {
            pp = skip[pp];
        }
    }
    pt = pp = 0;
    while (txt[pt] != '\0' && patern[pp] != '\0') {
        if (txt[pt] == patern[pp]) {
            pt++;
            pp++;
        } else if (pp == 0) {
            pt++;
        } else {
            pp = skip[pp];
        }
    }

    if (patern[pp] == '\0'){
        return pt - pp;
    }

    return -1;
}

int main(void){
    char txt[1024];
    char patern[1024];

    printf("テキスト：");
    scanf("%s", txt);
    printf("パターン：");
    scanf("%s", patern);

    int result = kmp_match(txt, patern);
    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("一致なし\n");
    }
    return 0;
}
    