#include<stdio.h>
#define SIZE 100
void Eulergraph(int adjMatrix[][SIZE], int size){
    int order[size];
    int ordernums = 0;
    for(int i = 0; i < size; i++){
        order[i] = 0;
    }
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if(adjMatrix[i][j] == 1){
                order[i]++;
            }
        }
    }
    for (int i = 0; i < size; i++){
        if(order[i] % 2 == 0){
            ordernums++;
        }
    }
    if(ordernums == size){
        printf("オイラーグラフ:YES\n");
    }else{
        printf("オイラーグラフ:NO\n");
    }
}


void matrixmultiplication(int result[][SIZE], int adjMatrix[][SIZE], int size, int returnnums[][SIZE]){
    for (int j = 0; j < size; j++){
        for (int k = 0; k < size; k++){
            for (int l = 0; l < size; l++){
                returnnums[j][k] += result[j][l] * adjMatrix[l][k];
            }
        }
    }
}

void matrixaddition(int adjMatrix[][SIZE], int size, int num, int returnnums[][SIZE]){
    int result[size][size];
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            result[i][j] = adjMatrix[i][j];
        }
    }

    for (int i = 0; i < num; i++){
        matrixmultiplication(result, adjMatrix, size, returnnums);
        for (int j = 0; j < size; j++){
            for (int k = 0; k < size; k++){
                result[j][k] = returnnums[j][k];
            }
        }
    }
    
}

void HamiltonianPath(int adjMatrix[][SIZE], int size, int start, int goal){
    int identitymatrix[size][size];
    int result[size][size];
    int returnnums[size][size];
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            identitymatrix[i][j] = 0;
        }
    }
    for (int i = 0;i < size; i++){
        identitymatrix[i][i] = 1;
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            result[i][j] = identitymatrix[i][j];
        }
    }
    for(int i = 0; i < size -1; i++){
        if(result[start][goal] == 1){
            for (int j = 0; j < size; j++){
                for(int k = 0; k < size; k++){
                    printf("%d ", result[j][k]);
                }
                printf("\n");
            }
            printf("可達:YES\n");
            break;
        }else{
            matrixaddition(adjMatrix, size, i, returnnums);
            for (int j = 0; j < size; j++){
                for (int k = 0; k < size; k++){
                    result[j][k] += returnnums[j][k];
                }
            }
        }
    }
    printf("可達:NO\n");
}

void HamiltonianCycle(int adjMatrix[][SIZE], int size){
    int order1;
    int order2;
    int order[size];
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if(adjMatrix[i][j] == 0){
                order1 = i;
                order2 = j;
                break;
            }
        }
    }
    for(int i = 0; i < size; i++){
        order[i] = 0;
    }
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if(adjMatrix[i][j] == 1){
                order[i]++;
            }
        }
    }

    if(order[order1] + order[order2] == size ){
        printf("ハミルトン閉路:YES\n");
    }else{
        printf("ハミルトン閉路:NO\n");
    }

}


int main(){
    int size;
    printf("頂点の数を入力してください: ");
    scanf("%d", &size);

    int adjMatrix[size][size];
    printf("隣接行列を入力してください:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    int start, goal, num;
    printf("可達かどうかを判定しますか\nYESなら1、NOなら0を入力してください: ");
    scanf("%d", &num);
    if(num == 1){
        printf("任意の2頂点を入力してください: ");
        scanf("%d %d", &start, &goal);
        HamiltonianPath(adjMatrix, size, start, goal);
    }else{
        printf("オイラーグラフかどうかを判定しますか\nYESなら1、NOなら0を入力してください: ");
        scanf("%d", &num);
        if(num == 1){
            Eulergraph(adjMatrix, size);
        }else{
            printf("ハミルトン閉路かどうかを判定しますか\nYESなら1、NOなら0を入力してください: ");
            scanf("%d", &num);
            if(num == 1){
                HamiltonianCycle(adjMatrix, size);
            }
        }
    }
    return 0;
}