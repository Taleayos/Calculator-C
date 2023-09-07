#ifndef CREDIT_H
#define CREDIT_H

#include <QDialog>
#include <QMainWindow>
#include <QString>

extern "C" {
#include "s21_calc.h"
}

namespace Ui {
class Credit;
}

class Credit : public QDialog {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private slots:

  void on_pushButton_clicked();

 private:
  Ui::Credit *ui;
};

#endif  // CREDIT_H
