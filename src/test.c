#include "test.h"

START_TEST(valid_error_1) {
  char str[256] = "cos(sin(tan(asin(acos(atan)";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_2) {
  char str[256] = "32+12-(18.6-)";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_3) {
  char str[256] = "32/(12*(18.6-)";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_4) {
  char str[256] = "mod3ln";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_5) {
  char str[256] = "127-a+cis(son(lg(laq(acus(2)))))";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_6) {
  char str[256] = "x.123z*aspo(2)/sqrt(/)";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_7) {
  char str[256] = "ln(-3) * 3 mod 2 )";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_8) {
  char str[256] = "25+$3-c0s(@-4)/";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_9) {
  char str[256] = "13$(^mod5*!/(&+5)18";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_10) {
  char str[256] = "37/";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_11) {
  char str[256] = "37+";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_12) {
  char str[256] = "(2+3)x";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_13) {
  char str[256] = "80*+13";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_14) {
  char str[256] = "sin(3) + * 4";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_15) {
  char str[256] = "3sin(3)";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_16) {
  char str[256] = "18(4-89)";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_17) {
  char str[256] = "sin(3)+3mod";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_18) {
  char str[256] = "123.123.123 + 1";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_19) {
  char str[256] = "123.123.123 * 1";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(valid_error_20) {
  char str[256] = "(x+2.123.2)";
  int res = validation(str);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(polish_1) {
  char str[256] = "10+sin(cos(log(5+1)))";
  char str_res[256] = "ddd+lcs+";
  int n = strlen(str_res);
  Stack* parc = Parcer(str);
  Stack* res = Polish_Notation(parc);
  for (int i = 0; i < n; i++) {
    char c = print_stack(res);
    ck_assert_int_eq(c, str_res[i]);
    res = Pop_stack(res);
  }
}
END_TEST

START_TEST(polish_2) {
  char str[256] = "((3^2 - 2^3)^2)";
  char str_res[256] = "dd^dd^-d^";
  int n = strlen(str_res);
  Stack* parc = Parcer(str);
  Stack* res = Polish_Notation(parc);
  for (int i = 0; i < n; i++) {
    char c = print_stack(res);
    ck_assert_int_eq(c, str_res[i]);
    res = Pop_stack(res);
  }
}
END_TEST

START_TEST(polish_3) {
  char str[256] = "((2^3 - 3^2)^77) / 7^(-1)";
  char str_res[256] = "dd^dd^-d^ddd-^/";
  int n = strlen(str_res);
  Stack* parc = Parcer(str);
  Stack* res = Polish_Notation(parc);
  for (int i = 0; i < n; i++) {
    char c = print_stack(res);
    ck_assert_int_eq(c, str_res[i]);
    res = Pop_stack(res);
  }
}
END_TEST

START_TEST(polish_4) {
  char str[256] = "0.8^0*(3^3+5^5)^0+(1/5)^(-1)";
  char str_res[256] = "dd^dd^dd^+d^*dd/dd-^+";
  int n = strlen(str_res);
  Stack* parc = Parcer(str);
  Stack* res = Polish_Notation(parc);
  for (int i = 0; i < n; i++) {
    char c = print_stack(res);
    ck_assert_int_eq(c, str_res[i]);
    res = Pop_stack(res);
  }
}
END_TEST

START_TEST(polish_5) {
  char str[256] = "(1/4)*(4^3-2^5)+(1/2)^(-2)*(-2)";
  char str_res[256] = "dd/dd^dd^-*dd/dd-^dd-*+";
  int n = strlen(str_res);
  Stack* parc = Parcer(str);
  Stack* res = Polish_Notation(parc);
  for (int i = 0; i < n; i++) {
    char c = print_stack(res);
    ck_assert_int_eq(c, str_res[i]);
    res = Pop_stack(res);
  }
}
END_TEST

START_TEST(polish_6) {
  char str[256] = "-5+8";
  char str_res[256] = "dd-d+";
  int n = strlen(str_res);
  Stack* parc = Parcer(str);
  Stack* res = Polish_Notation(parc);
  for (int i = 0; i < n; i++) {
    char c = print_stack(res);
    ck_assert_int_eq(c, str_res[i]);
    res = Pop_stack(res);
  }
}
END_TEST

START_TEST(polish_7) {
  char str[256] = "(1/4)*(4^3-2^5)+(1/2)^(-2)*(-2)";
  char str_res[256] = "dd/dd^dd^-*dd/dd-^dd-*+";
  int n = strlen(str_res);
  Stack* parc = Parcer(str);
  Stack* res = Polish_Notation(parc);
  for (int i = 0; i < n; i++) {
    char c = print_stack(res);
    ck_assert_int_eq(c, str_res[i]);
    res = Pop_stack(res);
  }
}
END_TEST

START_TEST(polish_8) {
  char str[256] = "sin(cos(log(3^2 - 2^3)))";
  char str_res[256] = "dd^dd^-lcs";
  int n = strlen(str_res);
  Stack* parc = Parcer(str);
  Stack* res = Polish_Notation(parc);
  for (int i = 0; i < n; i++) {
    char c = print_stack(res);
    ck_assert_int_eq(c, str_res[i]);
    res = Pop_stack(res);
  }
}
END_TEST

START_TEST(polish_9) {
  char str[256] = "10 mod 2 - (-x) * asin(acos(2)) +atan(ln(2^2))";
  char str_res[256] = "ddmdx-daa*-dd^la+";
  int n = strlen(str_res);
  Stack* parc = Parcer(str);
  Stack* res = Polish_Notation(parc);
  for (int i = 0; i < n; i++) {
    char c = print_stack(res);
    ck_assert_int_eq(c, str_res[i]);
    res = Pop_stack(res);
  }
}
END_TEST

START_TEST(polish_10) {
  char str[256] = "-tan(sqrt(9))";
  char str_res[256] = "ddst-";
  int n = strlen(str_res);
  Stack* parc = Parcer(str);
  Stack* res = Polish_Notation(parc);
  for (int i = 0; i < n; i++) {
    char c = print_stack(res);
    ck_assert_int_eq(c, str_res[i]);
    res = Pop_stack(res);
  }
}
END_TEST

START_TEST(calc_1) {
  char str[256] = "10+sin(cos(log(5+1)))";
  double res = 0;
  double count = 10.65351005;
  Stack* parc = Parcer(str);
  Stack* polish = Polish_Notation(parc);
  res = Calculate(polish, 0);
  ck_assert_double_eq_tol(res, count, 8);
}
END_TEST

START_TEST(calc_2) {
  char str[256] = "((3^2 - 2^3)^2)";
  double res = 0;
  double count = 1;
  Stack* parc = Parcer(str);
  Stack* polish = Polish_Notation(parc);
  res = Calculate(polish, 0);
  ck_assert_double_eq_tol(res, count, 8);
}
END_TEST

START_TEST(calc_3) {
  char str[256] = "((2^3 - 3^2)^77) / 7^(-1)";
  double res = 0;
  double count = -7;
  Stack* parc = Parcer(str);
  Stack* polish = Polish_Notation(parc);
  res = Calculate(polish, 0);
  ck_assert_double_eq_tol(res, count, 8);
}
END_TEST

START_TEST(calc_4) {
  char str[256] = "0.8^0*(3^3+5^5)^0+(1/5)^(-1)";
  double res = 0;
  double count = 6;
  Stack* parc = Parcer(str);
  Stack* polish = Polish_Notation(parc);
  res = Calculate(polish, 0);
  ck_assert_double_eq_tol(res, count, 8);
}
END_TEST

START_TEST(calc_5) {
  char str[256] = "(1/4)*(4^3-2^5)+(1/2)^(-2)*(-2)";
  double res = 0;
  double count = 0;
  Stack* parc = Parcer(str);
  Stack* polish = Polish_Notation(parc);
  res = Calculate(polish, 0);
  ck_assert_double_eq_tol(res, count, 8);
}
END_TEST

START_TEST(calc_6) {
  char str[256] = "-5.8734/12+(0.000076*sqrt(0.99)-9mod3)";
  double res = 0;
  double count = -0.4893743809547799;
  Stack* parc = Parcer(str);
  Stack* polish = Polish_Notation(parc);
  res = Calculate(polish, 0);
  ck_assert_double_eq_tol(res, count, 8);
}
END_TEST

START_TEST(calc_7) {
  char str[256] = "sin(cos(log(3^2 - 2^3)))";
  double res = 0;
  double count = 0.841470984808;
  Stack* parc = Parcer(str);
  Stack* polish = Polish_Notation(parc);
  res = Calculate(polish, 0);
  ck_assert_double_eq_tol(res, count, 8);
}
END_TEST

START_TEST(calc_8) {
  char str[256] = "atan(0.678456)";
  double res = 0;
  double count = 0.59612010125075;
  Stack* parc = Parcer(str);
  Stack* polish = Polish_Notation(parc);
  res = Calculate(polish, 0);
  ck_assert_double_eq_tol(res, count, 8);
}
END_TEST

START_TEST(calc_9) {
  char str[256] = "asin(0.678456)";
  double res = 0;
  double count = 0.745658882754721;
  Stack* parc = Parcer(str);
  Stack* polish = Polish_Notation(parc);
  res = Calculate(polish, 0);
  ck_assert_double_eq_tol(res, count, 8);
}
END_TEST

START_TEST(calc_10) {
  char str[256] = "acos(0.0331)";
  double res = 0;
  double count = 1.53769027969789;
  Stack* parc = Parcer(str);
  Stack* polish = Polish_Notation(parc);
  res = Calculate(polish, 0);
  ck_assert_double_eq_tol(res, count, 8);
}
END_TEST

START_TEST(calc_11) {
  char str[256] = "-tan(sqrt(9))";
  double res = 0;
  double count = -0.052407779283;
  Stack* parc = Parcer(str);
  Stack* polish = Polish_Notation(parc);
  res = Calculate(polish, 0);
  ck_assert_double_eq_tol(res, count, 8);
}
END_TEST

START_TEST(calc_12) {
  char str[256] = "5mod2*ln(sqrt(2.9-0.13))+(-1.987)";
  double res = 0;
  double count = -1.4775763399003764;
  Stack* parc = Parcer(str);
  Stack* polish = Polish_Notation(parc);
  res = Calculate(polish, 0);
  ck_assert_double_eq_tol(res, count, 8);
}
END_TEST

START_TEST(calc_13) {
  char str[256] = "-sqrt(9)/((1/4)*(4^3-2^5)+(1/2)^(-2)*(-2))";
  double res = 0;
  Stack* parc = Parcer(str);
  Stack* polish = Polish_Notation(parc);
  res = Calculate(polish, 0);
  ck_assert_double_nan(res);
}
END_TEST

START_TEST(calc_14) {
  char str[256] = "sin(x)";
  double count = -0.8414709848;
  Stack* parc = Parcer(str);
  Stack* polish = Polish_Notation(parc);
  double res = Calculate(polish, -1);
  ck_assert_double_eq_tol(res, count, 8);
}
END_TEST

START_TEST(credit_1) {
  double sum = 1000000;
  int year = 2;
  double procent = 13;
  Cr_Calc res = Credit_Calc(sum, year, procent, 0, 1);
  double m_pay = 47541.82;
  double o_pay = 141003.68;
  double s_pay = 1141003.68;
  ck_assert_double_eq_tol(res.month_pay_max, m_pay, 2);
  ck_assert_double_eq_tol(res.over_pay, o_pay, 2);
  ck_assert_double_eq_tol(res.sum_pay, s_pay, 2);
}
END_TEST

START_TEST(credit_2) {
  double sum = 150000;
  int year = 9;
  double procent = 13;
  Cr_Calc res = Credit_Calc(sum, year, procent, 1, 0);
  double m_pay = 16847.22;
  double o_pay = 8125.00;
  double s_pay = 158125.00;
  ck_assert_double_eq_tol(res.month_pay_max, m_pay, 2);
  ck_assert_double_eq_tol(res.over_pay, o_pay, 2);
  ck_assert_double_eq_tol(res.sum_pay, s_pay, 2);
}
END_TEST

START_TEST(deposit_1) {
  double sum = 1000000;
  int month = 2;
  int type = 1;
  double pr_rate = 10;
  double tax_rate = 13;
  int t_p = 0;
  int capitalisation = 0;
  double r_procent = 200000;
  double r_tax = 6500;
  double r_sum = 1000000;
  Dep_Calc res =
      Deposit_Calc(sum, month, type, pr_rate, tax_rate, t_p, capitalisation);
  ck_assert_double_eq_tol(res.procent, r_procent, 2);
  ck_assert_double_eq_tol(res.tax, r_tax, 2);
  ck_assert_double_eq_tol(res.sum, r_sum, 2);
}

START_TEST(deposit_2) {
  double sum = 1000000;
  int month = 2;
  int type = 1;
  double pr_rate = 10;
  double tax_rate = 13;
  int t_p = 0;
  int capitalisation = 1;
  double r_procent = 221369.301640;
  double r_tax = 9278.009213;
  double r_sum = 1221369.301640;
  Dep_Calc res =
      Deposit_Calc(sum, month, type, pr_rate, tax_rate, t_p, capitalisation);
  ck_assert_double_eq_tol(res.procent, r_procent, 2);
  ck_assert_double_eq_tol(res.tax, r_tax, 2);
  ck_assert_double_eq_tol(res.sum, r_sum, 2);
}

START_TEST(deposit_3) {
  double sum = 1000000;
  int month = 2;
  int type = 1;
  double pr_rate = 10;
  double tax_rate = 13;
  int t_p = 1;
  int capitalisation = 1;
  double r_procent = 223516.596619;
  double r_tax = 9557.157560;
  double r_sum = 1223516.596619;
  Dep_Calc res =
      Deposit_Calc(sum, month, type, pr_rate, tax_rate, t_p, capitalisation);
  ck_assert_double_eq_tol(res.procent, r_procent, 2);
  ck_assert_double_eq_tol(res.tax, r_tax, 2);
  ck_assert_double_eq_tol(res.sum, r_sum, 2);
}

START_TEST(deposit_4) {
  double sum = 1000000;
  int month = 2;
  int type = 1;
  double pr_rate = 10;
  double tax_rate = 13;
  int t_p = 2;
  int capitalisation = 1;
  double r_procent = 220390.961376;
  double r_tax = 9150.824979;
  double r_sum = 1220390.961376;
  Dep_Calc res =
      Deposit_Calc(sum, month, type, pr_rate, tax_rate, t_p, capitalisation);
  ck_assert_double_eq_tol(res.procent, r_procent, 2);
  ck_assert_double_eq_tol(res.tax, r_tax, 2);
  ck_assert_double_eq_tol(res.sum, r_sum, 2);
}

START_TEST(deposit_5) {
  double sum = 1000000;
  int month = 2;
  int type = 1;
  double pr_rate = 10;
  double tax_rate = 13;
  int t_p = 3;
  int capitalisation = 1;
  double r_procent = 218402.897510;
  double r_tax = 8892.376676;
  double r_sum = 1218402.897510;
  Dep_Calc res =
      Deposit_Calc(sum, month, type, pr_rate, tax_rate, t_p, capitalisation);
  ck_assert_double_eq_tol(res.procent, r_procent, 2);
  ck_assert_double_eq_tol(res.tax, r_tax, 2);
  ck_assert_double_eq_tol(res.sum, r_sum, 2);
}

START_TEST(deposit_6) {
  double sum = 1000000;
  int month = 2;
  int type = 1;
  double pr_rate = 10;
  double tax_rate = 13;
  int t_p = 4;
  int capitalisation = 1;
  double r_procent = 215506.250000;
  double r_tax = 8515.812500;
  double r_sum = 1215506.250000;
  Dep_Calc res =
      Deposit_Calc(sum, month, type, pr_rate, tax_rate, t_p, capitalisation);
  ck_assert_double_eq_tol(res.procent, r_procent, 2);
  ck_assert_double_eq_tol(res.tax, r_tax, 2);
  ck_assert_double_eq_tol(res.sum, r_sum, 2);
}

START_TEST(deposit_7) {
  double sum = 1000000;
  int month = 2;
  int type = 1;
  double pr_rate = 10;
  double tax_rate = 13;
  int t_p = 5;
  int capitalisation = 1;
  double r_procent = 210000;
  double r_tax = 7800;
  double r_sum = 1210000;
  Dep_Calc res =
      Deposit_Calc(sum, month, type, pr_rate, tax_rate, t_p, capitalisation);
  ck_assert_double_eq_tol(res.procent, r_procent, 2);
  ck_assert_double_eq_tol(res.tax, r_tax, 2);
  ck_assert_double_eq_tol(res.sum, r_sum, 2);
}

START_TEST(deposit_8) {
  double sum = 1000000;
  int month = 2;
  int type = 1;
  double pr_rate = 10;
  double tax_rate = 13;
  int t_p = 6;
  int capitalisation = 1;
  double r_procent = 200000;
  double r_tax = 6500;
  double r_sum = 1200000;
  Dep_Calc res =
      Deposit_Calc(sum, month, type, pr_rate, tax_rate, t_p, capitalisation);
  ck_assert_double_eq_tol(res.procent, r_procent, 2);
  ck_assert_double_eq_tol(res.tax, r_tax, 2);
  ck_assert_double_eq_tol(res.sum, r_sum, 2);
}

START_TEST(deposit_9) {
  double sum = 150000;
  int month = 4;
  int type = 0;
  double pr_rate = 10;
  double tax_rate = 13;
  int t_p = 1;
  int capitalisation = 1;
  double r_procent = 5278.058770;
  double r_tax = 0;
  double r_sum = 155278.058770;
  Dep_Calc res =
      Deposit_Calc(sum, month, type, pr_rate, tax_rate, t_p, capitalisation);
  ck_assert_double_eq_tol(res.procent, r_procent, 2);
  ck_assert_double_eq_tol(res.tax, r_tax, 2);
  ck_assert_double_eq_tol(res.sum, r_sum, 2);
}

Suite* test(void) {
  Suite* s = suite_create("test");
  TCase* tc = tcase_create("case_test");

  tcase_add_test(tc, valid_error_1);
  tcase_add_test(tc, valid_error_2);
  tcase_add_test(tc, valid_error_3);
  tcase_add_test(tc, valid_error_4);
  tcase_add_test(tc, valid_error_5);
  tcase_add_test(tc, valid_error_6);
  tcase_add_test(tc, valid_error_7);
  tcase_add_test(tc, valid_error_8);
  tcase_add_test(tc, valid_error_9);
  tcase_add_test(tc, valid_error_10);
  tcase_add_test(tc, valid_error_11);
  tcase_add_test(tc, valid_error_12);
  tcase_add_test(tc, valid_error_13);
  tcase_add_test(tc, valid_error_14);
  tcase_add_test(tc, valid_error_15);
  tcase_add_test(tc, valid_error_16);
  tcase_add_test(tc, valid_error_17);
  tcase_add_test(tc, valid_error_18);
  tcase_add_test(tc, valid_error_19);
  tcase_add_test(tc, valid_error_20);
  tcase_add_test(tc, polish_1);
  tcase_add_test(tc, polish_2);
  tcase_add_test(tc, polish_3);
  tcase_add_test(tc, polish_4);
  tcase_add_test(tc, polish_5);
  tcase_add_test(tc, polish_6);
  tcase_add_test(tc, polish_7);
  tcase_add_test(tc, polish_8);
  tcase_add_test(tc, polish_9);
  tcase_add_test(tc, polish_10);
  tcase_add_test(tc, calc_1);
  tcase_add_test(tc, calc_2);
  tcase_add_test(tc, calc_3);
  tcase_add_test(tc, calc_4);
  tcase_add_test(tc, calc_5);
  tcase_add_test(tc, calc_6);
  tcase_add_test(tc, calc_7);
  tcase_add_test(tc, calc_8);
  tcase_add_test(tc, calc_9);
  tcase_add_test(tc, calc_10);
  tcase_add_test(tc, calc_11);
  tcase_add_test(tc, calc_12);
  tcase_add_test(tc, calc_13);
  tcase_add_test(tc, calc_14);
  tcase_add_test(tc, credit_1);
  tcase_add_test(tc, credit_2);
  tcase_add_test(tc, deposit_1);
  tcase_add_test(tc, deposit_2);
  tcase_add_test(tc, deposit_3);
  tcase_add_test(tc, deposit_4);
  tcase_add_test(tc, deposit_5);
  tcase_add_test(tc, deposit_6);
  tcase_add_test(tc, deposit_7);
  tcase_add_test(tc, deposit_8);
  tcase_add_test(tc, deposit_9);

  suite_add_tcase(s, tc);
  return s;
}
