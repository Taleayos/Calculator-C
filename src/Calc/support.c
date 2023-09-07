#include "s21_calc.h"

// Stack* head = NULL;

int Is_Number(char a) {
  int res = 0;
  if (a >= 48 && a <= 57) res = 1;
  return res;
}

int Is_Operator(char a) {
  int res = 0;
  switch (a) {
    case '+':
      res = 3;
      break;
    case '-':
      res = 4;
      break;
    case '*':
      res = 5;
      break;
    case '/':
      res = 6;
      break;
    case '^':
      res = 8;
      break;
  }
  return res;
}

int Is_Function(char a) {
  int res = 0;
  if (a == 's' || a == 'c' || a == 'm' || a == 't' || a == 'a' || a == 'l') {
    res = 1;
  }
  return res;
}

int Is_Sin(char *str) {
  int res = 0;
  char s[4] = "sin(";
  if (strlen(str) >= 4) {
    if (strncmp(str, s, 4) == 0) {
      res = 1;
    }
  }
  return res;
}

int Is_Cos(char *str) {
  int res = 0;
  char c[4] = "cos(";
  if (strlen(str) >= 4) {
    if (strncmp(str, c, 4) == 0) {
      res = 1;
    }
  }
  return res;
}

int Is_Tan(char *str) {
  int res = 0;
  char t[4] = "tan(";
  if (strlen(str) >= 4) {
    if (strncmp(str, t, 4) == 0) {
      res = 1;
    }
  }
  return res;
}

int Is_Arc(char *str) {
  int res = 0;
  if (str[0] == 'a') {
    str++;
    if (Is_Sin(str) == 1) {
      res = 13;
    } else if (Is_Cos(str) == 1) {
      res = 12;
    } else if (Is_Tan(str) == 1) {
      res = 14;
    }
  }
  return res;
}

int Is_Sqrt(char *str) {
  int res = 0;
  char s[5] = "sqrt(";
  if (strlen(str) >= 5) {
    if (strncmp(str, s, 5) == 0) {
      res = 1;
    }
  }
  return res;
}

int Is_Log(char *str) {
  int res = 0;
  char log[4] = "log(";
  if (strlen(str) >= 4) {
    if (strncmp(str, log, 4) == 0) {
      res = 1;
    }
  }
  return res;
}

int Is_Ln(char *str) {
  int res = 0;
  char log[3] = "ln(";
  if (strlen(str) >= 3) {
    if (strncmp(str, log, 3) == 0) {
      res = 1;
    }
  }
  return res;
}

int Is_Mod(char *str) {
  int res = 0;
  char m[3] = "mod";
  if (strlen(str) >= 3) {
    if (strncmp(str, m, 3) == 0) {
      res = 1;
    }
  }
  return res;
}

Stack *Push_stack(Stack *head, double value, int priority, Type_t type) {
  Stack *element = (Stack *)malloc(sizeof(Stack));
  if (head == NULL) {
    element->value = value;
    element->priority = priority;
    element->next = NULL;
    element->type = type;
    head = element;
  } else {
    element->value = value;
    element->priority = priority;
    element->next = head;
    element->type = type;
    head = element;
  }
  return element;
}

Stack *Pop_stack(Stack *top) {
  Stack *temp;
  if (top == NULL)
    top = NULL;
  else {
    temp = top;
    top = top->next;
    free(temp);
  }
  return top;
}

int Peek_stack(Stack *top) {
  int priopity = top->priority;
  return priopity;
}

int Priority_of_oper(int type_oper) {
  int pr = 0;
  if (type_oper == 4 || type_oper == 3) {
    pr = 1;
  } else if (type_oper == 5 || type_oper == 6) {
    pr = 2;
  } else if (type_oper == 8) {
    pr = 3;
  }
  return pr;
}

Stack *Push_function_to_line(Stack *line, char *str, int *i) {
  //    Stack *line = NULL;
  if (Is_Sin(str)) {
    line = Push_stack(line, 0, 4, 9);
    *i += 2;
  } else if (Is_Cos(str)) {
    line = Push_stack(line, 0, 4, 10);
    *i += 2;
  } else if (Is_Tan(str)) {
    line = Push_stack(line, 0, 4, 11);
    *i += 2;
  } else if (Is_Arc(str) > 0) {
    int t = Is_Arc(str);
    line = Push_stack(line, 0, 4, t);
    *i += 3;
  } else if (Is_Sqrt(str)) {
    line = Push_stack(line, 0, 4, 15);
    *i += 3;
  } else if (Is_Ln(str)) {
    line = Push_stack(line, 0, 4, 16);
    *i += 1;
  } else if (Is_Log(str)) {
    line = Push_stack(line, 0, 4, 17);
    *i += 2;
  }
  return line;
}

int Count_Stack(Stack *top) {
  int count = 0;
  Stack *temp = NULL;
  if (top != NULL) {
    for (temp = top; temp != NULL; temp = temp->next) {
      count++;
    }
    free(temp);
  }
  return count;
}

Stack *Inverse_stack(Stack *line_from_parcer) {
  Stack *result = NULL;
  int n = Count_Stack(line_from_parcer);
  for (int i = 0; i < n; i++) {
    result = Push_stack(result, line_from_parcer->value,
                        line_from_parcer->priority, line_from_parcer->type);
    line_from_parcer = Pop_stack(line_from_parcer);
  }
  return result;
}

double Func_Calc(int type, double value) {
  double res = 0;
  if (type == 9) {
    res = sin(value);
  } else if (type == 10) {
    res = cos(value);
  } else if (type == 11) {
    res = tan(value);
  } else if (type == 12) {
    res = acos(value);
  } else if (type == 13) {
    res = asin(value);
  } else if (type == 14) {
    res = atan(value);
  } else if (type == 15) {
    res = sqrt(value);
  } else if (type == 16) {
    res = log(value);
  } else if (type == 17) {
    res = log10(value);
  }
  return res;
}

double Oper_Calc(double first, double value_2, int type) {
  double res = 0;
  if (type == 3) {
    res = first + value_2;
  } else if (type == 4) {
    res = first - value_2;
  } else if (type == 5) {
    res = first * value_2;
  } else if (type == 6 && value_2 != 0) {
    res = first / value_2;
  } else if (type == 6 && value_2 == 0) {
    res = NAN;
  } else if (type == 7) {
    res = fmod(first, value_2);
  } else if (type == 8) {
    res = pow(first, value_2);
  }
  return res;
}

char print_stack(Stack *line) {
  char c = '\0';
  switch (line->type) {
    case 1:
      c = 'd';
      break;
    case 2:
      c = 'x';
      break;
    case 3:
      c = '+';
      break;
    case 4:
      c = '-';
      break;
    case 5:
      c = '*';
      break;
    case 6:
      c = '/';
      break;
    case 7:
      c = 'm';
      break;
    case 8:
      c = '^';
      break;
    case 9:
      c = 's';
      break;
    case 10:
      c = 'c';
      break;
    case 11:
      c = 't';
      break;
    case 12:
      c = 'a';
      break;
    case 13:
      c = 'a';
      break;
    case 14:
      c = 'a';
      break;
    case 15:
      c = 's';
      break;
    case 16:
      c = 'l';
      break;
    case 17:
      c = 'l';
      break;
  }
  return c;
}
