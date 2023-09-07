#include "s21_calc.h"

double Calculate(Stack* inv_polish, double x) {
  Stack* calc = NULL;
  double res = 0;
  double second_value = 0;
  int n = Count_Stack(inv_polish);
  for (int i = 0; i < n; i++) {
    int tmp = Peek_stack(inv_polish);
    if (tmp == 0) {
      if (inv_polish->type == 2) {
        inv_polish->value = x;
        inv_polish->type = 1;
      }
      calc = Push_stack(calc, inv_polish->value, inv_polish->priority,
                        inv_polish->type);
      inv_polish = Pop_stack(inv_polish);
    } else if (tmp < 4) {
      second_value = calc->value;
      calc = Pop_stack(calc);
      double first_value = calc->value;
      calc = Pop_stack(calc);
      calc = Push_stack(
          calc, Oper_Calc(first_value, second_value, inv_polish->type), 0, 1);
      inv_polish = Pop_stack(inv_polish);
    } else if (tmp == 4) {
      int type = inv_polish->type;
      inv_polish = Pop_stack(inv_polish);
      calc->value = Func_Calc(type, calc->value);
    }
  }
  res = calc->value;
  calc = Pop_stack(calc);
  return res;
}
