//
// Created by zl on 2016/9/25.
//

#include <stdlib.h>
#include "inversion-number.h"

/**
 * Number of inversions merge-sort idea implementation
 * @param arr
 * @param begin
 * @param end
 * @return
 */
long mergeSort(int *arr, int begin, int end) {
    if (begin == end) {
        return 0;
    }
    int p = (begin + end) / 2;
    long il = mergeSort(arr, begin, p);
    long ir = mergeSort(arr, p + 1, end);

    int ls = p - begin + 1;
    int rs = end - p;
    int s = ls + rs;
    int *tmp = malloc(sizeof(int) * (s));

    int i = 0;
    int j = 0;
    int k = 0;
    long inv = 0;
    while (i < ls && j < rs) {
        if (arr[i + begin] > arr[j + p + 1]) {
            tmp[k++] = arr[j + p + 1];
            j++;
            // important! count the number of inversion
            inv += ls - i;
        } else {
            tmp[k++] = arr[i + begin];
            i++;
        }
    }
    while (i < ls) { tmp[k++] = arr[begin + i++]; }
    while (j < rs) { tmp[k++] = arr[p + 1 + j++]; }
    for (int t = begin; t <= end; t++) {
        arr[t] = tmp[t - begin];
    }
    free(tmp);
    return il + ir + inv;
}

/**
 * entry of count the number of inversions, using merge-sort idea
 * @param arr input, array of unsort number
 * @param size size of input array
 * @return inversion number
 */
long mergeSortInversion(int *arr, int size) {
    return mergeSort(arr, 0, size - 1);
}

int *tmp = NULL;

long quickSort(int *arr, int begin, int end) {
    if (begin >= end) {
        return 0;
    }
    long v = 0, lv, rv, vi = 0;
    int pi = begin;

    int p = arr[begin];
    for (int i = begin; i <= end; i++) {
        if (arr[i] < p) pi++;
    }

    tmp[pi] = p;

    int ir = pi + 1, il = begin;

    for (int i = begin + 1; i <= end; i++) {
        if (arr[i] > p) {
            tmp[ir++] = arr[i];
            vi++;
            if (i < begin) v++;
        } else if (arr[i] < p) {
            tmp[il++] = arr[i];
            if (i > begin) v++;
            v += vi;
        }
    }

    for (int i = begin; i <= end; i++) {
        arr[i] = tmp[i];
    }
    lv = quickSort(arr, pi + 1, end);
    rv = quickSort(arr, begin, pi - 1);
    return lv + rv + v;

}

long quickSortInversion(int *arr, int size) {
    tmp = malloc(sizeof(int) * size);
    long result = quickSort(arr, 0, size - 1);
    free(tmp);
    return result;
}

/**
 * base algorithm count the number of inversions, validate result only
 * @param arr input, array of unsort number
 * @param size size of input array
 * @return inversion number
 */
long baseInversion(int *arr, int size) {
    long re = 0;
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                re++;
            }
        }
    }
    return re;
}
