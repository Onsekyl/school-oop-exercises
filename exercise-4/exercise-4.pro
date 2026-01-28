TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bankaccount.cpp \
        creditaccount.cpp \
        customer.cpp \
        main.cpp

HEADERS += \
    bankaccount.h \
    creditaccount.h \
    customer.h
