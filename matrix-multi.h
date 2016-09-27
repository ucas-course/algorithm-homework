//
// Created by zl on 2016/9/25.
//

#ifndef WORKSPACE_MATRIX_MULTI_H
#define WORKSPACE_MATRIX_MULTI_H

int *strassenMatrixMulti(int *a, int *b, int size);

int *baseMatrixAdd(int *a, int *b, int m, int n);

int *baseMatrixSub(int *a, int *b, int m, int n);

int *baseMatrixMulti(int *a, int am, int an, int *b, int bm, int bn);

int **partitionMatrix(int *m, int size);

int *combineMatrix(int *a, int *b, int *c, int *d, int size);

void printMatrix(int *a, int m, int n);

#endif //WORKSPACE_MATRIX_MULTI_H
