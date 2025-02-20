QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    criminals_widgets.cpp \
    fan_widgets.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Criminal_class.h \
    Ultras_class.h \
    criminals_widgets.h \
    fan_widgets.h \
    mainwindow.h

FORMS += \
    criminals_widgets.ui \
    fan_widgets.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/criminals.txt \
    build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/ultras — копия.txt \
    build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/ultras — копия.txt \
    build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/ultras.txt
