#-------------------------------------------------
#
# Project created by QtCreator 2019-02-21T16:42:20
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WeatherQuery
TEMPLATE = app


SOURCES += main.cpp\
        weatherquery.cpp \
    rolltest.cpp \
    keybutton.cpp \
    softkey.cpp

HEADERS  += weatherquery.h \
    rolltest.h \
    keybutton.h \
    softkey.h

FORMS    += weatherquery.ui \
    rolltest.ui \
    softkey.ui

RESOURCES += \
    image.qrc
