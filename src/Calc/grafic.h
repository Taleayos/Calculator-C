#ifndef GRAFIC_H
#define GRAFIC_H

#include <QDialog>
#include <QMainWindow>
#include <QString>
#include <QVector>

extern "C" {
#include "s21_calc.h"
}

namespace Ui {
class Grafic;
}

class Grafic : public QMainWindow {
  Q_OBJECT

 public:
  explicit Grafic(QWidget *parent = nullptr);
  ~Grafic();

 private slots:
  void on_Print_graf_clicked();
  void TakeStr(const QString &text);

 private:
  Ui::Grafic *ui;
  double xBegin, xEnd, yBegin, yEnd, h, X;
  int N;

  QVector<double> x, y;
};

// public slots:
//     void mySlot(const QString &text);

#endif  // GRAFIC_H
