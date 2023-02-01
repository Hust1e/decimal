#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <stdio.h>

typedef struct s21_decimal {
  unsigned int bits[4];
} s21_decimal;

enum {
    LOW, MID, HIGH, SCALE
};

int getBit(s21_decimal d, int index);
void setBit(s21_decimal *d, int index, int bit);
void setSign(s21_decimal *d, int sign);
int getSign(s21_decimal d);
int getScale(s21_decimal d);
void setScale(s21_decimal *d, int scale);

void s21_from_int_to_decimal(int src, s21_decimal *dst);

#endif  // SRC_S21_DECIMAL_H_