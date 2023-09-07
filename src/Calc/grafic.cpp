#include "grafic.h"
#include "ui_grafic.h"

Grafic::Grafic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Grafic)
{
    ui->setupUi(this);

}

Grafic::~Grafic()
{
    delete ui;
}

void Grafic::TakeStr(const QString &text)
{
    QString str_take = text;
    ui->Text_from_calc->setText(str_take);
}

void Grafic::on_Print_graf_clicked()
{
    x.clear();
    y.clear();

    h = 0.1;
    xBegin = ui->xBegin->text().toDouble();
    xEnd = ui->xEnd->text().toDouble();
    yBegin = ui->yBegin->text().toDouble();
    yEnd = ui->yEnd->text().toDouble();

    N = (xEnd - xBegin)/h + 2;

    QByteArray by = ui->Text_from_calc->text().toLocal8Bit();
    char *str = by.data();

    if (strchr(str, 'x') == NULL || validation(str) == 1)
    {
    ui->Text_from_calc->setText("INCORRECT INPUT");
    } else
    {
    for (X = xBegin; X <= xEnd; X += h) {
          x.push_back(X);

            Stack* parce = Parcer(str);
            Stack* polish = Polish_Notation(parce);
            double res = Calculate(polish, X);

          y.push_back(res);
    }
}

    ui->Qwt_Widget->addGraph();
    ui->Qwt_Widget->graph(0)->setData(x,y);

    ui->Qwt_Widget->xAxis->setLabel("x");
    ui->Qwt_Widget->yAxis->setLabel("y");

    ui->Qwt_Widget->xAxis->setRange(xBegin, xEnd);
//    ui->Qwt_Widget->yAxis->setRange(yBegin, yEnd);
    double minY = y[0], maxY = y[0];
    for (int i = 1; i < N; i++) {
        if (y[i] < minY) minY = y[i];
        if (y[i] > maxY) maxY = y[i];
    }
    ui->Qwt_Widget->yAxis->setRange(minY, maxY);

    ui->Qwt_Widget->replot();

    ui->Qwt_Widget->setInteraction(QCP::iRangeZoom, true);
    ui->Qwt_Widget->setInteraction(QCP::iRangeDrag, true);

}


