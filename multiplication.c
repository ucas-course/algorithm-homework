//
// Created by zl on 2016/9/24.
//

#include "multiplication.h"

#define max(a, b) ((a)>(b)?(a):(b))


/**
 * calculate multiplication of a and b,which think in binary.
 * use karatsuba algorithm
 * NOTE: think in binary
 * @param a A matrix
 * @param b A matrix
 * @return
 */
int karatsubaMulti(int a, int b) {

    int bit = max(getBit(a), getBit(b));

    if (bit < 2) {
        return a * b;
    }

    int ah, al, bh, bl;

    //get a and b high and low part
    ah = a >> (bit >> 1);
    al = a ^ (ah << (bit >> 1));
    bh = b >> (bit >> 1);
    bl = b ^ (bh << (bit >> 1));

    //cal P
    int P = karatsubaMulti(ah + al, bh + bl);

    int ahbh = karatsubaMulti(ah, bh);
    int albl = karatsubaMulti(al, bl);

    //combine the result NOTE: replace *(common multiplication) with << and >>
    return (ahbh << (bit >> 1 << 1)) + ((P - ahbh - albl) << (bit >> 1)) + albl;
}

/**
 * get x 's bit in binary
 * @param x the number
 * @return
 */
int getBit(int x) {
    int i;
    for (i = 0; x; i++) {
        x >>= 1;
    }
    return i;
}

/**
 * calculate multiplication of a and b,which think in binary.
 * use base method
 * NOTE: think in binary
 * @param a
 * @param b
 * @return
 */
int baseMulti(int a, int b) {

    int bit = max(getBit(a), getBit(b));
    int sum = 0;

    for (int i = 0; i < bit; i++) {
        int t = 0;
        sum <<= 1;

        //this part can be optimized in the condition of binary, assert the bit if eq 1
        for (int j = 0; j < bit; j++) {
            t <<= 1;
            t |= ((b >> (bit - j - 1)) & (a >> (bit - i - 1))) & 1;
        }
        sum += t;
    }
    return sum;
}