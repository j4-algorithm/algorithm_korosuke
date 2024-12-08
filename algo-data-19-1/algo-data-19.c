#include "stdio.h"
#include "stdbool.h"

#define INFINITY 1000000

#define SIZE 100

typedef struct {
    int visitedNode[SIZE];
    int visitableNode[SIZE];
}VNode;

void visitNode(int nodeNum, int edgeCostArray[SIZE][SIZE], int costArr[SIZE], int s, int g, VNode* v);


int main(void) {
    int nodeNum;
    int edgeCostArray[SIZE][SIZE];
    int costArray[SIZE];
    int s;
    int goal;
    int minWeight = INFINITY;
    int minWeightIdx = 0;
    int result;
    VNode v;

    scanf("%d", &nodeNum);

    for (int i = 0; i < nodeNum; i++) {
        for (int j = 0; j < nodeNum; j++) {
            scanf("%d", &edgeCostArray[i][j]);
        }
    }
    goal = nodeNum - 1;
    scanf("%d", &s);


    for (int i = 0; i < nodeNum; i++) {
        if (i != s) {
            for (int j = 0; j < nodeNum; j++) {
                if (j == 0) {
                    costArray[j] = 0;
                    v.visitedNode[j] = true;
                } else {
                    costArray[j] = INFINITY;
                    v.visitedNode[j] = false;
                }
                v.visitableNode[j] = false;
            }
            visitNode(nodeNum, edgeCostArray, costArray, s, i, &v);
        }else{
            printf("%d %d\n", s, 0);
        }
    }

    return 0;
}

void visitNode(int nodeNum, int edgeCostArray[SIZE][SIZE], int costArr[SIZE], int s, int g, VNode* v) {
    int minWeight = INFINITY;
    int minWeightIdx = 0;
    for (int currentNodeIndex = 0; currentNodeIndex < nodeNum; currentNodeIndex++) {
        if (edgeCostArray[s][currentNodeIndex] != 0 && v->visitedNode[currentNodeIndex] == false) {
            v->visitableNode[currentNodeIndex] = true;
        }
    }

    for (int a = 0; a < nodeNum; a++) {
        if (v->visitableNode[a] == true) {
            if (costArr[a] > edgeCostArray[s][a] + costArr[s]) {
                minWeight = edgeCostArray[s][a] + costArr[s];
                minWeightIdx = a;
                for (int b = 0; b < nodeNum; b++) {
                    if (costArr[b] < minWeight && costArr[b] != 0 && v->visitedNode[b] != 1) {
                        minWeight = costArr[b];
                        minWeightIdx = b;
                    }
                }
                costArr[minWeightIdx] = minWeight;
                v->visitedNode[minWeightIdx] = true;
                if (minWeightIdx == g) {
                    printf("%d %d\n", g, minWeight);
                    return;
                }
            }
        }
    }
    visitNode(nodeNum, edgeCostArray, costArr, minWeightIdx, g, v);

    return;
}