#include "credit.h"
#include "ui_credit.h"

Credit::Credit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credit)
{
    ui->setupUi(this);
}

Credit::~Credit()
{
    delete ui;
}

void Credit::on_pushButton_clicked()
{
    type_term t = month;
//    int time_t = ui->time_2->currentData().toInt();
    int time_t = ui->time_2->currentIndex();
    if (time_t == 0) {
       t = year;
    } else if (time_t == 1) {
       t = month;
    }

    type_credit type = annuitet;

    double sum = ui->sum_1->text().toDouble();

    int year = ui->time_1->text().toInt();

    double procent = ui->proc_2->text().toDouble();

    if (ui->type_a->isChecked()) {
        type = annuitet;
    }
    if (ui->type_d->isChecked()) {
        type = differnc;
    }


    Cr_Calc res = {0, 0, 0, 0};
    res = Credit_Calc(sum, year, procent, type, t);

    ui->min->setText(QString().setNum(res.month_pay_min, 'f', 2));
    ui->tochki->setText(" ...");
    ui->max->setText(QString().setNum(res.month_pay_max, 'f', 2));
    ui->proc_nachisl->setText(QString().setNum(res.over_pay, 'f', 2));
    ui->proc_dolg->setText(QString().setNum(res.sum_pay, 'f', 2));
}



