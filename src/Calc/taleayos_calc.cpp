#include "taleayos_calc.h"
#include "ui_taleayos_calc.h"

Taleayos_Calc::Taleayos_Calc(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Taleayos_Calc) {
    ui->setupUi(this);
    sWindow = new Grafic();

    connect(ui->pushButton_0, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_dot, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_acos, SIGNAL(clicked()),this,SLOT(digit_numbers_func()));
    connect(ui->pushButton_asin, SIGNAL(clicked()),this,SLOT(digit_numbers_func()));
    connect(ui->pushButton_atan, SIGNAL(clicked()),this,SLOT(digit_numbers_func()));
    connect(ui->pushButton_close_sk, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_cos, SIGNAL(clicked()),this,SLOT(digit_numbers_func()));
    connect(ui->pushButton_div, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_ln, SIGNAL(clicked()),this,SLOT(digit_numbers_func()));
    connect(ui->pushButton_log, SIGNAL(clicked()),this,SLOT(digit_numbers_func()));
    connect(ui->pushButton_minus, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_mod, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_mult, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_open_sk, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_plus, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_sin, SIGNAL(clicked()),this,SLOT(digit_numbers_func()));
    connect(ui->pushButton_tan, SIGNAL(clicked()),this,SLOT(digit_numbers_func()));
    connect(ui->pushButton_x, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()),this,SLOT(digit_sqrt()));
    connect(ui->pushButton_step, SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(this, SIGNAL(take_text(const QString &)), sWindow, SLOT(TakeStr(const QString &)));
}

Taleayos_Calc::~Taleayos_Calc()
{
    delete ui;
}

void Taleayos_Calc::digit_numbers()
{
   QPushButton *button = (QPushButton *)sender();

   QString str = button->text();

   ui->lineEdit->setText(ui->lineEdit->text() += str);
}

void Taleayos_Calc::digit_numbers_func()
{
   QPushButton *button = (QPushButton *)sender();

   QString str = button->text();

   ui->lineEdit->setText(ui->lineEdit->text() += str);
   ui->lineEdit->setText(ui->lineEdit->text() += '(');
}

void Taleayos_Calc::digit_sqrt()
{

   QString str =  "sqrt(";

   ui->lineEdit->setText(ui->lineEdit->text() += str);
}

void Taleayos_Calc::on_pushButton_AC_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() = ' ');
}


void Taleayos_Calc::on_pushButton_res_clicked()
{
    QByteArray ba = ui->lineEdit->text().toLocal8Bit();
        char *str = ba.data();
        int valid = validation(str);
        if (valid == 1) {
            ui->lineEdit->setText("INCORRECT INPUT");
        } else {
            Stack* parce = Parcer(str);
            Stack* polish = Polish_Notation(parce);
            double res = Calculate(polish, 0);
            QString result;
            result = QString::number(res, 'g', 15);
            ui->lineEdit->setText(result);
       }
}


void Taleayos_Calc::on_pushButton_grafic_clicked()
{
    emit take_text(ui->lineEdit->text());
    sWindow->show();
//    this->close();

}


void Taleayos_Calc::on_pushButton_credit_clicked()
{
    Credit window;
    window.setModal(true);
    window.exec();
}


void Taleayos_Calc::on_pushButton_deposit_clicked()
{
    Credit_calc window;
    window.setModal(true);
    window.exec();

}

