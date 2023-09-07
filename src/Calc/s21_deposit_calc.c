#include "s21_calc.h"

Dep_Calc Deposit_Calc(double sum, int month, type_term type, double pr_rate,
                      double tax_rate, type_periodisity t_p,
                      int capitalisation) {
  Dep_Calc res = {0};
  double so = 1000000 * (7.50 / 100);
  double procent_tmp = 0;
  int d = 0;
  if (type == 1) {
    month *= 12;
  }
  double days = month * 30.41666666;
  if (capitalisation == 0) {
    res.procent = sum * ((pr_rate / 12 / 100) * month);
    res.sum = sum;
  }
  if (capitalisation == 1) {
    if (t_p == 0) {
      d = 365;
    } else if (t_p == 1) {
      days /= 7;
      d = 52;
    } else if (t_p == 2) {
      days = month;
      d = 12;
    } else if (t_p == 3) {
      days = month / 3;
      d = 4;
    } else if (t_p == 4) {
      days = month / 6;
      d = 2;
    } else if (t_p == 5 && month > 11) {
      days = month / 12;
      d = 1;
    } else if (t_p == 6 || month < 12) {
      res = Deposit_Calc(sum, month, 0, pr_rate, tax_rate, t_p, 0);
      res.sum = res.procent + sum;
      return res;
    }
    for (int i = 0; i < days; i++) {
      procent_tmp = sum * (pr_rate / 100 / d);
      res.procent += procent_tmp;
      sum += procent_tmp;
    }
    res.sum = sum;
  }
  double tmp = res.procent;
  double s = (double)month / 12;
  double ex_tax = so * s;
  if (tmp > ex_tax) {
    res.tax = (res.procent - ex_tax) * (tax_rate / 100);
  } else {
    res.tax = 0;
  }
  return res;
}
