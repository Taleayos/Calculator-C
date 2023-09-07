#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <QDialog>
#include <QMainWindow>
#include <QString>

extern "C" {
#include "s21_calc.h"
}

namespace Ui {
class Credit_calc;
}

class Credit_calc : public QDialog {
  Q_OBJECT

 public:
  explicit Credit_calc(QWidget *parent = nullptr);
  ~Credit_calc();

 private slots:
  void on_pushButton_clicked();

 private:
  Ui::Credit_calc *ui;
};

#endif  // CREDIT_CALC_H
