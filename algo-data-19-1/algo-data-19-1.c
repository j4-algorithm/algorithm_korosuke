#include<stdio.h>

#define SIZE 100

int min(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

int VertexDetermination(int v, int Set[SIZE],int size){
    for (int i = 0; i < size; i++){
        if(Set[i] == v){
            return 1;
        }
    }
    return 0;
}

int minindex(int result[], int Set[], int size){
    int min = __INT32_MAX__;
    int minindex = -1;
    for (int i = 0; i < size; i++){
        if(result[i] < min && VertexDetermination(i, Set, size) == 0){
            min = result[i];
            minindex = i;
        }
    }
    return minindex;
}

int main(void){
    int adjMatrix[SIZE][SIZE];
    int result[SIZE];
    int Set[SIZE];
    int vertex_top = 0;
    int size;
    int start;

    scanf("%d", &size);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    scanf("%d", &start);

    for (int i = 0; i < size; i++){
        result[i] = __INT32_MAX__;
        Set[i] = __INT32_MAX__;
    }
    result[start] = 0;
    for (int i = 0; i < size; i++){
        int v = minindex(result, Set, size);
        Set[vertex_top++] = v;
        for (int j = 0; j < size; j++){
            if(adjMatrix[v][j] != 0 && VertexDetermination(j, Set, size) == 0){
                result[j] = min(result[j], result[v] + adjMatrix[v][j]);
            }
        }
    }
    for (int i = 0; i < size; i++){
        printf("%d %d\n", i, result[i]);
    }
    return 0;
}
