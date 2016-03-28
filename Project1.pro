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
    newexecutive.cpp \
    dailysales.cpp \
    memreport.cpp \
    deletemember.cpp \
    additem.cpp

HEADERS  += mainwindow.h \
    Date.h \
    Member.h \
    Executive.h \
    MemberList.h \
    execreg.h \
    newregular.h \
    newexecutive.h \
    dailysales.h \
    memreport.h \
    deletemember.h \
    additem.h

FORMS    += mainwindow.ui \
    execreg.ui \
    newregular.ui \
    newexecutive.ui \
    dailysales.ui \
    memreport.ui \
    deletemember.ui \
    additem.ui

DISTFILES +=

RESOURCES += \
    ../../../Documents/BulkClubAlpha/warehouseshoppers.qrc
