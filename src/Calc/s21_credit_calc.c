#include "s21_calc.h"

Cr_Calc Credit_Calc(double sum, int month_year, double procent,
                    type_credit type, type_term t) {
  if (t == 1) {
    month_year *= 12;
  }
  Cr_Calc result = {0};
  if (type == annuitet) {
    result.month_pay_min =
        sum *
        (((procent / 100 / 12) * pow((1 + (procent / 100 / 12)), month_year)) /
         (pow(1 + ((procent / 100 / 12)), month_year) - 1));
    result.over_pay = (month_year * result.month_pay_min) - sum;
    result.sum_pay = sum + result.over_pay;
    result.month_pay_max = result.month_pay_min;
  } else if (type == differnc) {
    double sum_tmp = sum;
    for (int i = month_year; i > 0; i--) {
      result.month_pay_max = (sum / i) + (sum * (procent / 100 / 12));
      if (i == month_year) {
        result.month_pay_min = result.month_pay_max;
      }
      result.sum_pay += result.month_pay_max;
      sum -= sum_tmp / (month_year);
    }
    result.over_pay = result.sum_pay - sum_tmp;
    //        result.sum_pay = sum_tmp + result.over_pay;
  }
  return result;
}
