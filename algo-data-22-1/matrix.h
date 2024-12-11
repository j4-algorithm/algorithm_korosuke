#pragma once
#include <stdio.h>

#define MAX_NUM_ROW 100
#define MAX_NUM_COL 100

#define MAX_NUM_MATRIX 10

typedef int Row;
typedef int Col;

typedef struct {
    Row numRow;
    Col numCol;
} Matrix;


int SolveChainMatrixMultiplicationProblem(Matrix matrix[MAX_NUM_MATRIX], size_t nmemb); 
