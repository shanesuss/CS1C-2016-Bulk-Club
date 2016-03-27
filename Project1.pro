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
    execreg.cpp \
    newregular.cpp \
    newexecutive.cpp

HEADERS  += mainwindow.h \
    Date.h \
    Member.h \
    Executive.h \
    MemberList.h \
    execreg.h \
    newregular.h \
    newexecutive.h

FORMS    += mainwindow.ui \
    execreg.ui \
    newregular.ui \
    newexecutive.ui

DISTFILES += \
    BulkClubMembers.txt \
    day1.txt \
    day2.txt \
    day3.txt \
    day4.txt \
    day5.txt
