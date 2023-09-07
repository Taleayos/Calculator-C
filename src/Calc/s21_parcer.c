#include "s21_calc.h"

Stack *Parcer(char *str) {
  Stack *line = NULL;
  double stack_number = 0;
  int i = 0;
  char *buf = NULL;
  int Malloc = 0;
  int countBuf = 0;
  while (str[i] != '\0') {
    while (Is_Number(str[i]) || str[i] == '.') {
      if (buf == NULL || countBuf >= Malloc - 1) {
        Malloc += 10;
        char *temp = (char *)realloc(
            buf, sizeof(char) * Malloc);  // Надо ли освобождать temp?
        if (temp != NULL) {
          buf = temp;
        }
      }
      buf[countBuf++] = str[i++];
    }
    if (countBuf != 0) {
      buf[countBuf++] = '\0';
      stack_number = atof(buf);
      line = Push_stack(line, stack_number, 0, 1);
      stack_number = 0;
      countBuf = 0;
    }
    if (Is_Operator(str[i]) > 0) {
      int type_oper = Is_Operator(str[i]);
      int pr = Priority_of_oper(type_oper);
      line = Push_stack(line, 0, pr, type_oper);
    } else if (Is_Function(str[i])) {
      if (Is_Mod(&str[i])) {
        line = Push_stack(line, 0, 2, 7);
        i += 2;
      } else {
        line = Push_function_to_line(line, &str[i], &i);
      }
    } else if (str[i] == '(') {
      line = Push_stack(line, 0, -1, 18);
    } else if (str[i] == ')') {
      line = Push_stack(line, 0, 5, 19);
    } else if (str[i] == 'x') {
      line = Push_stack(line, 0, 0, 2);
    }
    i++;
  }
  if (buf != NULL) {
    free(buf);
    buf = NULL;
  }
  return line;
}
