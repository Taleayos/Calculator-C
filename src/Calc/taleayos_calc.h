#ifndef TALEAYOS_CALC_H
#define TALEAYOS_CALC_H

#include <credit.h>
#include <credit_calc.h>
#include <grafic.h>

#include <QDialog>
#include <QMainWindow>
#include <QString>

extern "C" {
#include "s21_calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class Taleayos_Calc;
}
QT_END_NAMESPACE

class Taleayos_Calc : public QMainWindow {
  Q_OBJECT

 public:
  Taleayos_Calc(QWidget *parent = nullptr);
  ~Taleayos_Calc();

 private:
  Ui::Taleayos_Calc *ui;
  Grafic *sWindow;

 private slots:
  void digit_numbers();

 private slots:
  void digit_numbers_func();

 private slots:
  void digit_sqrt();
  void on_pushButton_AC_clicked();
  void on_pushButton_res_clicked();
  void on_pushButton_credit_clicked();
  void on_pushButton_grafic_clicked();

  void on_pushButton_deposit_clicked();

 signals:
  void take_text(const QString &text);
  void sig_set_text(QString);
};
#endif  // TALEAYOS_CALC_H
