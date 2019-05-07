##-------------------------------------------------
##
## Project created by QtCreator 2019-04-08T17:04:57
##
##-------------------------------------------------

#QT       += core gui


##D:\contribute\install\include\opencv \
##             D:\contribute\install\include\opencv2 \
##             D:\contribute\install\include



#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = G_P
#TEMPLATE = app

## The following define makes your compiler emit warnings if you use
## any feature of Qt which has been marked as deprecated (the exact warnings
## depend on your compiler). Please consult the documentation of the
## deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

## You can also make your code fail to compile if you use deprecated APIs.
## In order to do so, uncomment the following line.
## You can also select to disable deprecated APIs only up to a certain version of Qt.
##DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


#SOURCES += \
#        main.cpp \
#        mainwindow.cpp

#HEADERS += \
#        mainwindow.h

#FORMS += \
#        mainwindow.ui

#-------------------------------------------------
#
# Project created by QtCreator 2019-04-09T20:21:53
#
#-------------------------------------------------

QT       += core gui
QT       += 3drender
QT       += 3dextras
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cvmattoqimage.cpp \
    stlloader.cpp \
    hsv.cpp \
    unit_test.cpp \
    retrieval.cpp

HEADERS += \
        mainwindow.h \
    cvmattoqimage.h \
    stlloader.h \
    hsv.h \
    retrieval.h

FORMS += \
        mainwindow.ui

#INCLUDEPATH += F:\opencv\opencv\build\include\


#此处的话添加opencv的库
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../opencv/opencv/build/x64/vc15/lib/ -lopencv_world400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../opencv/opencv/build/x64/vc15/lib/ -lopencv_world400d
else:unix: LIBS += -L$$PWD/../../../../opencv/opencv/build/x64/vc15/lib/ -lopencv_world400

INCLUDEPATH += $$PWD/../../../../opencv/opencv/build/include
DEPENDPATH += $$PWD/../../../../opencv/opencv/build/include

DISTFILES +=
