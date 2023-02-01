#include "s21_test.h"
#include <check.h>
// CONVERTOR TIPOV
START_TEST(s21_from_int_to_decimal_1) {
    
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

  tcase_add_test(tc, s21_from_int_to_decimal_1);

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