//
// Created by zl on 2016/9/26.
//

#include "kthLargest.h"

/**
 * Implementation of finding kth min in unsort array, using quick-sort idea
 * @param arr array of number
 * @param begin begin index of array
 * @param end end index of array
 * @param kth kth min
 * @return kth min element value in arr
 */
int kthMinHelper(int *arr, int begin, int end, int kth) {

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
        return kthMinHelper(arr, i + 1, end, kth - (i - begin + 1));
    }
    if (i - begin > kth) {
        return kthMinHelper(arr, begin, i - 1, kth);
    }
    return p;

}

/**
 * entry of find kth largest
 * @param arr array of number
 * @param size size of array
 * @param kth kth large element value in array
 * @return
 */
int kthLargest(int *arr, int size, int kth) {
    // kth largest eq to size-kth min (begin from 0)
    return kthMinHelper(arr, 0, size - 1, size - kth);

}

