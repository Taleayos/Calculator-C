#ifndef S21_CALC_H_
#define S21_CALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  // priority = 0;
  number = 1,
  x = 2,
  // priority = 1;
  t_plus = 3,
  t_minus = 4,
  // priority = 2;
  t_mult = 5,
  t_div = 6,
  t_mod = 7,
  // priority = 3;
  t_stepen = 8,
  // priority = 4;
  t_sin = 9,
  t_cos = 10,
  t_tan = 11,
  t_acos = 12,
  t_asin = 13,
  t_atan = 14,
  t_sqrt = 15,
  t_ln = 16,
  t_log = 17,
  // priority = -1;
  sk_open = 18,
  // priority = 5;
  sk_close = 19
} Type_t;

typedef enum { annuitet, differnc } type_credit;

typedef enum { month, year } type_term;

typedef enum {
  dayly,
  weekly,
  monthly,
  quartery,
  half_yearly,
  yearly,
  at_the_end
} type_periodisity;

typedef struct stack {
  double value;
  int priority;
  struct stack *next;
  Type_t type;
} Stack;

typedef struct credit_calc {
  double month_pay_max;
  double month_pay_min;
  double over_pay;
  double sum_pay;
} Cr_Calc;

typedef struct deposit_calc {
  double procent;
  double tax;
  double sum;
} Dep_Calc;

// Calculator
int validation(char *str);
Stack *Parcer(char *str);
Stack *Polish_Notation(Stack *line_from_parcer);
double Calculate(Stack *inv_polish, double x);

// Credit_calculator
Cr_Calc Credit_Calc(double sum, int month_year, double procent,
                    type_credit type, type_term t);
// Deposit_calculator

Dep_Calc Deposit_Calc(double sum, int month, type_term type, double pr_rate,
                      double tax_rate, type_periodisity t_p,
                      int capitalisation);

// Supporting functions
int Is_Number(char a);
int Is_Operator(char a);
int Is_Function(char a);
int Is_Sin(char *str);
int Is_Cos(char *str);
int Is_Tan(char *str);
int Is_Arc(char *str);
int Is_Sqrt(char *str);
int Is_Log(char *str);
int Is_Ln(char *str);
int Is_Mod(char *str);
Stack *Push_stack(Stack *head, double value, int priority, Type_t type);
Stack *Pop_stack(Stack *top);
int Peek_stack(Stack *top);
int Count_Stack(Stack *top);
Stack *Inverse_stack(Stack *line_from_parcer);
int Priority_of_oper(int type_oper);
Stack *Push_function_to_line(Stack *line, char *str, int *i);
double Oper_Calc(double first, double value_2, int type);
double Func_Calc(int type, double value);
char print_stack(Stack *line);
void change_x(char *str, double x);

#endif  // S21_CALC_H_
