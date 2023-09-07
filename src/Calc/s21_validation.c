#include "s21_calc.h"

int validation(char *str) {
  int res = 0;
  int n = strlen(str);
  int flag_bracket = 0;
  char ptr_ch = ' ';
  int flag_point = 0;
  for (int i = 0; i < n && res != 1; i++) {
    if (Is_Number(str[i]) || str[i] == 'x') {
      if (ptr_ch == ' ' || Is_Number(ptr_ch) || Is_Operator(ptr_ch) > 0 ||
          ptr_ch == '(' || ptr_ch == '.') {
        ptr_ch = str[i];
      } else {
        res = 1;
      }
    } else if (str[i] == '-' || str[i] == '+') {
      if (ptr_ch == ' ' || Is_Number(ptr_ch) || ptr_ch == '(' ||
          ptr_ch == 'x' || ptr_ch == ')') {
        char *tmp = &str[i + 1];
        if (strcmp(tmp, "\0") == 0) {
          res = 1;
        } else {
          ptr_ch = str[i];
          if (flag_point != 0) {
            flag_point--;
          }
        }
      } else {
        res = 1;
      }
    } else if (Is_Operator(str[i]) > 0) {
      if ((ptr_ch == ' ' || Is_Number(ptr_ch) || ptr_ch == 'x' ||
           ptr_ch == ')') &&
          i > 0) {
        char *tmp = &str[i + 1];
        if (strcmp(tmp, "\0") == 0) {
          res = 1;
        } else {
          ptr_ch = str[i];
          if (flag_point != 0) {
            flag_point--;
          }
        }
      } else {
        res = 1;
      }
    } else if (str[i] == '.') {
      if (Is_Number(ptr_ch) && Is_Number(str[i + 1])) {
        ptr_ch = str[i];
        flag_point++;
      } else {
        res = 1;
      }
    } else if (Is_Function(str[i]) && !(Is_Mod(&str[i]))) {
      if (ptr_ch == ' ' || Is_Operator(ptr_ch) > 0 || ptr_ch == '(') {
        if (Is_Cos(&str[i]) || Is_Sin(&str[i]) || Is_Tan(&str[i]) ||
            Is_Log(&str[i])) {
          ptr_ch = '(';
          i += 3;
          flag_bracket++;
        } else if (Is_Sqrt(&str[i]) || Is_Arc(&str[i])) {
          ptr_ch = '(';
          i += 4;
          flag_bracket++;
        } else if (Is_Ln(&str[i])) {
          ptr_ch = '(';
          i += 2;
          flag_bracket++;
        } else {
          res = 1;
        }
      } else {
        res = 1;
      }
    } else if (Is_Function(str[i]) && (Is_Mod(&str[i]))) {
      if (Is_Number(ptr_ch) || ptr_ch == 'x') {
        if ((Is_Number(str[i + 3]) ||
             (str[i + 3] == ' ' && Is_Number(str[i + 4]))) ||
            ((str[i + 3] == 'x') || (str[i + 3] == ' ' && str[i + 4] == 'x'))) {
          ptr_ch = ' ';
          i += 2;
        } else
          res = 1;
      } else {
        res = 1;
      }
    } else if (str[i] == '(') {
      if (ptr_ch == ' ' || (Is_Operator(ptr_ch) > 0) || ptr_ch == '(') {
        ptr_ch = str[i];
        flag_bracket++;
      } else {
        res = 1;
      }
    } else if (str[i] == ')') {
      if (ptr_ch == ' ' || Is_Number(ptr_ch) || ptr_ch == 'x' ||
          ptr_ch == ')') {
        ptr_ch = str[i];
        flag_bracket--;
        if (flag_point != 0) {
          flag_point--;
        }
      } else {
        res = 1;
      }
    } else if (str[i] == ' ') {
    } else {
      res = 1;
    }
  }
  if (flag_bracket != 0) {
    res = 1;
  }
  if (flag_point != 0) {
    res = 1;
  }
  return res;
}
