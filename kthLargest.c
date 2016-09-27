//
// Created by zl on 2016/9/26.
//

#include "kthLargest.h"

/**
 *
 * @param arr array of number
 * @param begin begin index of array
 * @param end end index of array
 * @param kth kth min
 * @return kth min element value in arr
 */
int kthLargestHelper(int *arr, int begin, int end, int kth) {

    if (begin == end) {
        return arr[begin];
    }
    int p = arr[begin];
    int i = begin;
    int j = end;

    while (i != j) {
        while (i != j && arr[j] >= p) j--;
        arr[i] = arr[j];
        while (i != j && arr[i] < p) i++;
        arr[j] = arr[i];

    }
    arr[i] = p;

    if (i - begin < kth) {
        return kthLargestHelper(arr, i + 1, end, kth - (i - begin + 1));
    }
    if (i - begin > kth) {
        return kthLargestHelper(arr, begin, i - 1, kth);
    }
    return p;

}

/**
 *
 * @param arr array of number
 * @param size size of array
 * @param kth kth large element value in array
 * @return
 */
int kthLargest(int *arr, int size, int kth) {
    // kth largest eq to size-kth min (begin from 0)
    return kthLargestHelper(arr, 0, size - 1, size - kth);

}

