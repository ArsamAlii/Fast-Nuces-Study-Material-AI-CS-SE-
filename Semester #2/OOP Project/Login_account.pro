QT  += core gui sql # added sql for database

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


SOURCES += \
    databaseutils.cpp \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp \
    useraccount.cpp

HEADERS += \
    loginpage.h \
    mainwindow.h \
    useraccount.h

FORMS += \
    loginpage.ui \
    mainwindow.ui \
    useraccount.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
