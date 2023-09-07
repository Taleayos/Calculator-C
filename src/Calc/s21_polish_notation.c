#include "s21_calc.h"

Stack* Polish_Notation(Stack* line_from_parcer) {
  Stack* polish = NULL;
  Stack* oper = NULL;
  int i = 0;
  int flag_uno = 0;
  int n = Count_Stack(line_from_parcer);
  Stack* tmp = Inverse_stack(line_from_parcer);
  for (i = 0; i < n; i++) {
    if (tmp->type == 1 || tmp->type == 2) {
      polish = Push_stack(polish, tmp->value, tmp->priority, tmp->type);
      tmp = Pop_stack(tmp);
    } else {
      if (polish == NULL && tmp->priority == 1) {
        polish = Push_stack(polish, 0, 0, 1);
      }
      if (oper == NULL /*&& tmp->priority != 4*/) {
        oper = Push_stack(oper, tmp->value, tmp->priority, tmp->type);
        tmp = Pop_stack(tmp);
      } else {
        int prev_priority = Peek_stack(oper);
        if (prev_priority == -1 && tmp->priority == 1 && flag_uno == 1) {
          polish = Push_stack(polish, 0, 0, 1);
        }
        if ((tmp->priority > prev_priority && tmp->priority != 5) ||
            tmp->priority == -1) {
          if (tmp->priority == -1 && tmp->next->priority == 1) {
            flag_uno = 1;
          }
          oper = Push_stack(oper, tmp->value, tmp->priority, tmp->type);
          tmp = Pop_stack(tmp);

        } else {
          if (tmp->priority == 5) {
            while (prev_priority != -1) {
              polish =
                  Push_stack(polish, oper->value, oper->priority, oper->type);
              oper = Pop_stack(oper);
              prev_priority = Peek_stack(oper);
            }
            tmp = Pop_stack(tmp);
            oper = Pop_stack(oper);
          } else {
            while (prev_priority >= tmp->priority) {
              polish =
                  Push_stack(polish, oper->value, oper->priority, oper->type);
              oper = Pop_stack(oper);
              if (Count_Stack(oper) > 0) {
                prev_priority = Peek_stack(oper);
              } else {
                break;
              }
            }
            oper = Push_stack(oper, tmp->value, tmp->priority, tmp->type);
            tmp = Pop_stack(tmp);
          }
        }
      }
    }
  }
  while (oper != NULL) {
    polish = Push_stack(polish, oper->value, oper->priority, oper->type);
    oper = Pop_stack(oper);
  }
  polish = Inverse_stack(polish);
  return polish;
}
