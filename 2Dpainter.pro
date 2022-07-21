QT       += core gui

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
    circle.cpp \
    cpoint.cpp \
    dialog_line_edit.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    dialog_point.cpp \
    dialog_line.cpp \
    dialog_rectangle.cpp \
    dialog_circular.cpp \
    polygon.cpp \
    rectangle.cpp \
    shape.cpp \
    shapearray.cpp \
    triangle.cpp \
    dialog_rectangle_edit.cpp \
    dialog_circular_edit.cpp

HEADERS += \
    circle.h \
    cpoint.h \
    dialog_line_edit.h \
    line.h \
    mainwindow.h \
    dialog_point.h \
    dialog_line.h \
    dialog_rectangle.h \
    dialog_circular.h \
    polygon.h \
    rectangle.h \
    shape.h \
    shapearray.h \
    triangle.h \
    dialog_rectangle_edit.h \
    dialog_circular_edit.h

FORMS += \
    dialog_line_edit.ui \
    mainwindow.ui \
    dialog_point.ui \
    dialog_line.ui \
    dialog_rectangle.ui \
    dialog_circular.ui \
    dialog_rectangle_edit.ui \
    dialog_circular_edit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
