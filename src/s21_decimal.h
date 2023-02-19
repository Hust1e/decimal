#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <stdio.h>

#define START_LOW 0
#define START_MID 32
#define START_HIGHT 64
#define START_INFO 96

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
void intToDecimal(s21_decimal *d, unsigned int num);
int decimalToInt(s21_decimal d, int *num);
void initDecimal(s21_decimal *d);
void visualizer(s21_decimal *d);

void s21_from_int_to_decimal(int src, s21_decimal *dst);


#endif  // SRC_S21_DECIMAL_H_