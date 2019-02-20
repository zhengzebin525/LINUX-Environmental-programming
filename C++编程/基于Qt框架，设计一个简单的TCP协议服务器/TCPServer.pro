#-------------------------------------------------
#
# Project created by QtCreator 2019-02-20T10:03:36
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TCPServer
TEMPLATE = app


SOURCES += main.cpp\
        tcpserver.cpp

HEADERS  += tcpserver.h

FORMS    += tcpserver.ui
