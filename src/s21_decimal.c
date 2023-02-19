#include "s21_decimal.h"
// <<   this is left shift, dobovlyaet v konec 4isla nuli (2 systema is4isleniya).
int getBit(s21_decimal d, int index) {
    int bitNum = index % 32;
    int elemNum = index / 32;
    int mask = 1u << bitNum;
    // mask = 1u << 0;
    // mask = 1;
    return (d.bits[elemNum] & mask) >> bitNum;
    // elemNum eto 4islo int i k nemy maska 
    // (0 & 1) >> 0;
    // 0 & 1 = 0;
    // 0 >> 0 = 0;
}

void setBit(s21_decimal *d, int index, int bit) {
    int bitNum = index % 32;
    int elemNum = index / 32;
    if (bit == 1) {
        d->bits[elemNum] |= (1u << bitNum);
        // 0 =| (1 << 0)
        // 0 = 0 | (1 << 0)
        // 0 = 0 | (1)
        // result = 1
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

void intToDecimal(s21_decimal *d, unsigned int num) {
    
    initDecimal(d);
    int sign = 0;
    // int count = 0;

    if (num != 0) {
        if (num < 0) {
            sign = 1;
            num = -num;
        }
        d->bits[0] = num;
        setScale(d, 0);
        setSign(d, sign);
    }
}
 
void initDecimal(s21_decimal *d) {
    for (int i = 0; i < 128; ++i) {
    setBit(d, i, 0);
    }
}
int decimalToInt(s21_decimal src, int *num) {

    int flag = 0;
    int data = 0;
    int scale = getScale(src);

    if (scale + 31 < 95) {
        for (int i = scale + 31; i <= 95; ++i) {
            if (getBit(src, i)) {
                flag = 1; 
            }
        }
    }

    if (!flag) {
        printf("\nflagTYT\n");
        for (int i = scale + 30; i >= scale; --i) {
            // i = 0 + 30; 30 >= 0; --30; 
            data <<= 1;
            data |= getBit(src, i);
            // data sna4alo delaet sdvig vpravo a potom poly4aet bit
            // na4inaet so starshego bita
        }
        if (getSign(src)) {
            data = -data;
        }
        *num = data;
    }
    return flag;

// //  --SCALE CHECKER-- 
//     s21_decimal mynum;
//     intToDecimal(&mynum, 534534543);
//     int scale = getScale(mynum);
//     printf("\nscale: %d\n", scale);
}

void visualizer(s21_decimal *d) {

    for(int index = 0; index < 32; index++){
        int bitNum = index % 32;
        int elemNum = index / 32;
        printf("\nelem:%d, bit:%d, value:%d", elemNum, bitNum, getBit(*d, index));
        // int mask = 1u << bitNum;
        // printf("\nindex:%d bitNum:%d elemNum:%d mask: %d\n", index, bitNum, elemNum, mask);
        // // return (d.bits[elemNum] & mask) >> bitNum;
    }
    printf("\n");
    printf("\nZnak: %d\n", getBit(*d, 127));

    // printf("start 0 bit\n");
    // for (int i = 0; i < 4; ++i) {
    //     for(int j = 0; j < 33; j++) {
    //         printf("visualizer bit by num:%d - equal: %d\n", j, getBit(*d, j));
    //     }
    //     printf("end %d bit\n", i);
    //     // printf("\nvisualizer: %d\n", d[i]);
    // }
}