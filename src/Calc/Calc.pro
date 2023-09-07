QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += qwt

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    credit.cpp \
    credit_calc.cpp \
    grafic.cpp \
    main.cpp \
    qcustomplot.cpp \
    s21_calculate.c \
    s21_credit_calc.c \
    s21_deposit_calc.c \
    s21_parcer.c \
    s21_polish_notation.c \
    s21_validation.c \
    support.c \
    taleayos_calc.cpp

HEADERS += \
    credit.h \
    credit_calc.h \
    grafic.h \
    qcustomplot.h \
    s21_calc.h \
    taleayos_calc.h

FORMS += \
    credit.ui \
    credit_calc.ui \
    grafic.ui \
    taleayos_calc.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#DISTFILES += \
#    ../s21_calc.h.gch
