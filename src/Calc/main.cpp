#include <QApplication>

#include "taleayos_calc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Taleayos_Calc w;
    w.show();
    return a.exec();
}
