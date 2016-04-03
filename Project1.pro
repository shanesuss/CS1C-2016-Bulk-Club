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
    MemberList.cpp \
    execreg.cpp \
    newregular.cpp \
    newexecutive.cpp \
    memreport.cpp \
    deletemember.cpp \
    additem.cpp \
    salesinventory.cpp \
    deleteitem.cpp \
    SalesList.cpp \
    executive.cpp

HEADERS  += mainwindow.h \
    Date.h \
    Member.h \
    Executive.h \
    MemberList.h \
    execreg.h \
    newregular.h \
    newexecutive.h \
    memreport.h \
    deletemember.h \
    additem.h \
    salesinventory.h \
    deleteitem.h \
    SalesList.h

FORMS    += mainwindow.ui \
    execreg.ui \
    memreport.ui \
    deletemember.ui \
    additem.ui \
    deleteitem.ui

DISTFILES +=

RESOURCES += \
    bulkclub.qrc
