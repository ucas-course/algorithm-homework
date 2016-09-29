//
// Created by zl on 2016/9/29.
//

#include "nth-smallest.h"

#define min(a, b) ((a)<(b)?(a):(b))
#define max(a, b) ((a)>(b)?(a):(b))

/**
 *
 * @param a A sorted array
 * @param ab The begin element index of a
 * @param ae The end element index of a
 * @param b A sorted array
 * @param bb The begin element index of b
 * @param be The end element index of b
 * @return The median element
 */
int findMedianHelper(int *a, int ab, int ae, int *b, int bb, int be) {
    if (ab == ae && bb == be) {
        return min(a[ab], b[bb]);
    }

    int am = (ab + ae) / 2;
    int bm = (bb + be) / 2;

    if (a[am] > b[bm]) {
        return findMedianHelper(a, ab, am, b, bm + 1, be);
    } else {
        return findMedianHelper(a, am + 1, ae, b, bb, bm);
    }
}

/**
 *
 * @param a A sorted array
 * @param b A sorted array
 * @param size Size of a and b
 * @return The median element
 */
int findMedian(int *a, int *b, int size) {
    return findMedianHelper(a, 0, size - 1, b, 0, size - 1);
}
