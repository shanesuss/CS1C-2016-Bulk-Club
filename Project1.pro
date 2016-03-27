#-------------------------------------------------
#
# Project created by QtCreator 2016-03-07T15:51:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Date.cpp \
    Member.cpp \
    Executive.cpp \
    MemberList.cpp \
    salesinventory.cpp

HEADERS  += mainwindow.h \
    Date.h \
    Member.h \
    Executive.h \
    MemberList.h \
    salesinventory.h

FORMS    += mainwindow.ui

DISTFILES += \
    day1.txt \
    day2.txt \
    day3.txt \
    day4.txt \
    day5.txt \
    SalesReport.txt
