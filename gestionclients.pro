QT       += core gui
QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    client.cpp \
    connection.cpp \
    customsqlmodel.cpp \
    main.cpp \
    mainwindow.cpp \
    salle.cpp \
    secdialog.cpp \
    smtp.cpp

HEADERS += \
    arduino.h \
    client.h \
    connection.h \
    customsqlmodel.h \
    mainwindow.h \
    salle.h \
    secdialog.h \
    smtp.h

FORMS += \
    mainwindow.ui \
    secdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
QT += sql
QT += printsupport
# OpenSSL library path
LIBS += -LC:/Users/rayen/Downloads/openssl-1.0.2t-i386-win32
QT += network
QT += core
DEFINES += SMTP_ENABLED
QT += charts
INCLUDEPATH += $$PWD/models
QT += serialport
