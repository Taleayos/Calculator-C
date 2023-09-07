#include "credit_calc.h"
#include "ui_credit_calc.h"

Credit_calc::Credit_calc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credit_calc)
{
    ui->setupUi(this);
}

Credit_calc::~Credit_calc()
{
    delete ui;
}

void Credit_calc::on_pushButton_clicked()
{
    Dep_Calc res = {0, 0, 0};
    type_term t = month;
    int time_t = ui->time_2->currentIndex();

    if (time_t == 0) {
       t = year;
    } else if (time_t == 1) {
       t = month;
    }

    double sum = ui->sum_1->text().toDouble();

    int year = ui->time_1->text().toInt();

    double pr_rate = ui->proc_2->text().toDouble();

    double tax_rate = ui->proc_nalog_2->text().toDouble();

    type_periodisity t_p = at_the_end;
    int period = ui->comboBox->currentIndex();
    switch (period) {
    case 0 : t_p = dayly; break;
    case 1 : t_p = weekly; break;
    case 2 : t_p = monthly; break;
    case 3 : t_p = quartery; break;
    case 4 : t_p = half_yearly; break;
    case 5 : t_p = yearly; break;
    default : t_p = at_the_end;
    }

    int capitalisation = 0;
    if (ui->capital->isChecked()) {
        capitalisation = 1;
    }

    res = Deposit_Calc(sum, year, t, pr_rate, tax_rate, t_p,capitalisation);

    ui->res_proc_1->setText(QString().setNum(res.procent, 'f', 2));
    ui->sum_nalog_1->setText(QString().setNum(res.tax, 'f', 2));
    ui->sum_itog->setText(QString().setNum(res.sum, 'f', 2));
}

