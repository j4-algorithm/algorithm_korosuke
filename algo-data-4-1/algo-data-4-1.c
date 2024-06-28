#include <stdio.h>

int main(void) {
    int tree[1023] = {0};
    int height = 0;
    scanf("%d", &height);
    int h = (1 << height) - 1;
    for(int i = 0; h > 0; h--) {
        scanf("%d", &tree[i++]);
    }
    int n = 0;
    for(int i = 0; i < height; i++){
        printf("%d ", i + 1);
        for(int j = 0; j < (1 << i); j++){
            printf(" %d ", tree[n++]);
        }
        printf("\n");
    }
    return 0;
}