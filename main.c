//
// Created by zl on 2016/9/24.
//

#include "stdio.h"
#include "stdlib.h"
#include "multiplication.h"
#include "matrix-multi.h"
#include "inversion-number.h"
#include "kthLargest.h"
#include "tree-local-min.h"

#define BUFFER_SIZE (1000*1000)
int arr[BUFFER_SIZE];

int main() {

    //int k;
    //k = baseMulti(13,4);
    //k = karatsubaMulti(5e5, 5e5, 10);

//    int a[4] = {1, 2, 3, 4};
//    int *b = baseMatrixMulti(a, 2, 2, a, 2, 2);

//    int a[4] = {1, 2, 3, 4};
//
//    int *m=strassenMatrixMulti(a,a,2);
//
//    printMatrix(m,2,2);



//    FILE *file = fopen("D:\\\\Q8.txt", "r");
//    int size = 0;
//    while (EOF != fscanf(file, "%d", arr + size)) {
//        size++;
//    };
//
//    long invNum = mergeSortInversion(arr, size);
//
//    printf("%ld", invNum);


//    int arr[] = {3, 2, 5, 8, 6, 1};
//    //sorted   : 1, 2, 3, 5 ,6, 8
//    printf("%d", kthLargest(arr, 6, 6));


    // Tree =
    //             5
    //           /   \
    //          2     7
    //         / \   / \
    //        3   4 6   1
    //
    Node n1 = {
            .left=NULL,
            .right=NULL,
            .val=1
    }, n6 = {
            .left=NULL,
            .right=NULL,
            .val=6
    }, n4 = {
            .left=NULL,
            .right=NULL,
            .val=4
    }, n3 = {
            .left=NULL,
            .right=NULL,
            .val=3
    };

    Node n2 = {
            .left=&n3,
            .right=&n4,
            .val=2
    }, n7 = {
            .left=&n6,
            .right=&n1,
            .val=7
    };

    Node n5 = {
            .left=&n2,
            .right=&n7,
            .val=5
    };

    Tree *tree = &n5;

    printf("%d", findTreeLocalMin(tree));

    return 0;
}