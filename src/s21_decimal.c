#include "s21_decimal.h"

int getBit(s21_decimal d, int index) {
    int bitNum = index % 32;
    int elemNum = index / 32;
    int mask = 1u << bitNum;
    return (d.bits[elemNum] & mask) >> bitNum;
}

void setBit(s21_decimal *d, int index, int bit) {
    int bitNum = index % 32;
    int elemNum = index / 32;
    if (bit == 1) {
        d->bits[elemNum] |= (1u << bitNum);
    } else {
        d->bits[elemNum] &= (~(1u << bitNum));
    }
}

void setScale(s21_decimal *d, int scale) {
    for (int i = 112; i < 119; i++) {
        setBit(d, i, scale & 1);
        scale >>= 1;
    }
}

int getScale(s21_decimal d) {
    int scale = 0;
    for (int i = 119; i >= 112; i--) {
        scale <<= 1;
        scale |= getBit(d, i);
    }
    return scale;
}

int getSign(s21_decimal d) {
    return (getBit(d, 127));
}

void setSign(s21_decimal *d, int sign) {
    setBit(d, 127, sign);
}

