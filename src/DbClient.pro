QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

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
    addEnrolleeWidget.cpp \
    addSpecWidget.cpp \
    dbmaneger.cpp \
    enrolleetable.cpp \
    loginwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    persanalInfoWidget.cpp \
    specTableWidget.cpp \
    statisticWidget.cpp

HEADERS += \
    addEnrolleeWidget.h \
    addSpecWidget.h \
    dbmaneger.h \
    enrolleetable.h \
    loginwidget.h \
    mainwindow.h \
    personalInfoWidget.h \
    specTableWidget.h \
    statisticWidget.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



macx: LIBS += -L$$PWD/../../../../../../../../../../usr/local/mysql-connector-c++-8.0.18/lib64/ -lmysqlcppconn.7.8.0.18

INCLUDEPATH += $$PWD/../../../../../../../../../../usr/local/mysql-connector-c++-8.0.18/include
DEPENDPATH += $$PWD/../../../../../../../../../../usr/local/mysql-connector-c++-8.0.18/include

#macx: LIBS += -L$$PWD/../../../../../../../../../../usr/local/mysql-8.0.17-macos10.14-x86_64/lib64/ -lmysqlcppconn8.2.8.0.18

#INCLUDEPATH += $$PWD/../../../../../../../../../../usr/local/mysql-8.0.17-macos10.14-x86_64/include
#DEPENDPATH += $$PWD/../../../../../../../../../../usr/local/mysql-8.0.17-macos10.14-x86_64/include

macx: LIBS += -L$$PWD/../../../../../../../../../../usr/local/mysql-8.0.18-macos10.14-x86_64/lib/ -lmysqlclient.21

INCLUDEPATH += $$PWD/../../../../../../../../../../usr/local/mysql-8.0.18-macos10.14-x86_64/include
DEPENDPATH += $$PWD/../../../../../../../../../../usr/local/mysql-8.0.18-macos10.14-x86_64/include
