QT += quick widgets serialport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cpp/common/AppInfo.cpp \
    cpp/common/MySerialport.cpp \
        cpp/main.cpp \

RESOURCES += \
    qrc/image.qrc \
    qrc/js.qrc \
    qrc/qml.qrc

TRANSLATIONS += \
    ts/DicomViewer_zh_CN.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


#DISTFILES += \
#    qml/main.qml

HEADERS += \
    cpp/common/AppInfo.h \
    cpp/common/EnumParameter.h \
    cpp/common/MySerialport.h \
    cpp/common/SwitchPage.h



QMAKE_CXXFLAGS += /source-charset:utf-8 /execution-charset:utf-8


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SlBase/release/ -lSlBase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SlBase/debug/ -lSlBase

INCLUDEPATH += $$PWD/../SlBase/cpp
DEPENDPATH += $$PWD/../SlBase/cpp
