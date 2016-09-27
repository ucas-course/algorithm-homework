//
// Created by zl on 2016/9/25.
//

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "matrix-multi.h"

/**
 *
 * @param a A matrix
 * @param b A matrix
 * @param size size of a and b which should be 2^n
 * @return
 */
int *strassenMatrixMulti(int *a, int *b, int size) {

    if (size == 1) {
        int *res = malloc(sizeof(int));

        *res = *a * *b;
        return res;
    }
    int h = size / 2;

    int **ar = partitionMatrix(a, size);
    int **br = partitionMatrix(b, size);

    int *aa = ar[0],
            *ab = ar[1],
            *ac = ar[2],
            *ad = ar[3],
            *ba = br[0],
            *bb = br[1],
            *bc = br[2],
            *bd = br[3];

    int
    //p1=aa(bb-bd)
            *p1 = strassenMatrixMulti(aa, baseMatrixSub(bb, bd, h, h), h),
    //p2=(aa+ab)bd
            *p2 = strassenMatrixMulti(baseMatrixAdd(aa, ab, h, h), bd, h),
    //p3=(ac+ad)ba
            *p3 = strassenMatrixMulti(baseMatrixAdd(ac, ad, h, h), ba, h),
    //p4=ad(bc-ba)
            *p4 = strassenMatrixMulti(ad, baseMatrixSub(bc, ba, h, h), h),
    //p5=(aa+ad)(ba+bd)
            *p5 = strassenMatrixMulti(baseMatrixAdd(aa, ad, h, h), baseMatrixAdd(ba, bd, h, h), h),
    //p6=(ab-ad)(bc+bd)
            *p6 = strassenMatrixMulti(baseMatrixSub(ab, ad, h, h), baseMatrixAdd(bc, bd, h, h), h),
    //p7=(aa-ac)(ba+bb)
            *p7 = strassenMatrixMulti(baseMatrixSub(aa, ac, h, h), baseMatrixAdd(ba, bb, h, h), h);


    return combineMatrix(
            baseMatrixAdd(baseMatrixSub(baseMatrixAdd(p5, p4, h, h), p2, h, h), p6, h, h),
            baseMatrixAdd(p1, p2, h, h),
            baseMatrixAdd(p3, p4, h, h),
            baseMatrixSub(baseMatrixSub(baseMatrixAdd(p1, p5, h, h), p3, h, h), p7, h, h), h
    );
}

/**
 *
 * @param a matrix a which is squre
 * @param b matrix b which is squre
 * @param c matrix c which is squre
 * @param d matrix d which is squre
 * @param size size of a,b,c,d
 * @return
 */
int *combineMatrix(int *a, int *b, int *c, int *d, int size) {

    int h = size;
    size *= 2;
    int *res = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i < h) {

                if (j < h) {
                    // A
                    res[i * size + j] = a[i * h + j];
                } else {
                    // B
                    res[i * size + j] = b[i * h + j - h];
                }
            } else {

                if (j < h) {
                    // C
                    res[i * size + j] = c[(i - h) * h + j];
                } else {
                    // D
                    res[i * size + j] = d[(i - h) * h + j - h];
                }
            }

        }
    }
    return res;
}

/**
 *
 * @param m the matrix which is squre
 * @param size size of matrix
 * @return pointer to array of matrix
 */
int **partitionMatrix(int *m, int size) {

    int h = size / 2;

    int **res = malloc(sizeof(int *) * 4);

    for (int i = 0; i < 4; i++) {
        res[i] = malloc(h * h);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i < h) {

                if (j < h) {
                    // A
                    res[0][i * h + j] = m[i * size + j];
                } else {
                    // B
                    res[1][i * h + j - h] = m[i * size + j];
                }
            } else {

                if (j < h) {
                    // C
                    res[2][(i - h) * h + j] = m[i * size + j];
                } else {
                    // D
                    res[3][(i - h) * h + j - h] = m[i * size + j];
                }
            }
        }
    }
    return res;
}

/**
 *
 * @param a A matrix
 * @param b A matrix
 * @param m size of matrix row
 * @param n size of matrix column
 * @return
 */
int *baseMatrixAdd(int *a, int *b, int m, int n) {

    int *res = malloc(sizeof(int) * m * n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[i * m + j] = a[i * m + j] + b[i * m + j];
        }
    }
    return res;
}

/**
 *
 * @param a A matrix
 * @param b A matrix
 * @param m size of matrix row
 * @param n size of matrix column
 * @return
 */
int *baseMatrixSub(int *a, int *b, int m, int n) {

    int *res = malloc(sizeof(int) * m * n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[i * m + j] = a[i * m + j] - b[i * m + j];
        }
    }
    return res;
}

/**
 *
 * @param a A matrix
 * @param m size of matrix row
 * @param n size of matrix column
 */
void printMatrix(int *a, int m, int n) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i * m + j]);
        }
        printf("\n");
    }
}

// just implement the matrix multi by definition
int *baseMatrixMulti(int *a, int am, int an, int *b, int bm, int bn) {

    //can not multi
    if (an != bm) {
        return NULL;
    }
    int *res = malloc(am * bn * sizeof(int));

    memset(res, 0, am * bn * sizeof(int));

    for (int i = 0; i < am; i++) {
        for (int j = 0; j < bn; j++) {
            for (int k = 0; k < an; k++) {
                res[i * am + j] += a[i * am + k] * b[k * bm + j];
            }
        }
    }
    return res;
}

