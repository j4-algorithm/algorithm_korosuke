#include<stdio.h>

void Eulergraph(int adjMatrix[size][size], int size){
    int oredr[size];
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

void HamiltonianPath(int adjMatrix[size][size], int size, int start, int goal){
    int identity matrix[size][size];
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            identity matrix[i][j] = 0;
        }
    }
    for (int i = 0;i < size; i++){
        identity matrix[i][i] = 1;
    }
    
}

void HamiltonianCycle(int adjMatrix[size][size], int size){
    int order1;
    int order2;
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

    int adjMatrix[n][n];
    printf("隣接行列を入力してください:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    int start, goal;
    printf("任意の2頂点を入力してください: ");
    scanf("%d %d", &start, &goal);

   

    return 0;
}