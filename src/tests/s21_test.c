#include "s21_test.h"
#include <math.h>
#include <check.h>
// CONVERTOR TIPOV
START_TEST(s21_from_int_to_decimal_1) {
    s21_decimal var;
    int value = 0;
    intToDecimal(&var, 5);
    decimalToInt(var, &value);
    ck_assert_int_eq(5, value);

    printf("\nnum:%d\n", value);

    // //  --SCALE CHECKER-- 
    // s21_decimal mynum;
    // intToDecimal(&mynum, 534534543);
    // float scale = getScale(mynum);
    // printf("\nscale: %f\n", scale);
}
END_TEST

START_TEST(s21_bit_convertor) {
    //s21_decimal d;
}
END_TEST
/*
int = 2147483647
unsigned int = 4294967295
decimal = 79228162514264337593543950335
*/
START_TEST(s21_visualizer) {
    // s21_decimal d;
    // unsigned int insert_num = 4294967294; 
    // intToDecimal(&d, insert_num);
    // int result;
    // decimalToInt(d, &result);
    // printf("\n%d\n", result);
    // visualizer(&d);
    // ck_assert_int_eq(insert_num, result);
  
    unsigned int n = 110;
             //r = 18446744073709552046;
    printf("\n %d\n", n);
    int i;
    int a[96];
    int n_count;
    int count;
    while(n!=0)  
    {  
       n=n/10;  
       count++;  
    }
    printf("\ncount of numbers: %d\n", count);

    if(count == 3){
      n >>= 1;
      printf("\ndone:%d", n);
    }

    for(i = 0; n > 0; i++) {
        a[i] = n % 2;
        n = n / 2;
    }
    //printf("\nBinary of Given Number is =");    
    int counter = 0;
    for(i = i - 1; i>= 0; i--) {
        // printf("bit: %d - ", counter);
        // counter++;    
        printf("%d\n", a[i]);
    }
    printf("\n");
}
END_TEST

// START_TEST(s21_from_decimal_to_int_2) {
//     int n = rand_r(-8388608);
//     s21_decimal var;
//     int value = 0;
//     s21_from_int_to_decimal(n, &var);
//     s21_from_decimal_to_int(var, &value);
//     ck_assert_float_eq_tol(n, value, 10);
// }
// END_TEST




void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

Suite *suite_s21_from_decimal_to_int_ste(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_int_conversion");
  tc = tcase_create("case_from_decimal_to_int");

  //tcase_add_test(tc, s21_from_int_to_decimal_1);
  tcase_add_test(tc, s21_visualizer);

  // Loop cycle with random num
  // tcase_add_loop_test(tc, s21_from_decimal_to_int_2, 0, 1000);

  suite_add_tcase(s, tc);
  return s;
}

int main(void)
{
    int fail = 0;
    case_test(suite_s21_from_decimal_to_int_ste(), &fail);
    return fail;
}

// 1111111111111111111111111111111111111111111111111111111111111111
// 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000