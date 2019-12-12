QT       += core gui
QT       += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MathExpressionTestApp_01
TEMPLATE = app

# VARS
#Application version
#RC_ICONS = "ZImages/SRVLab-8.ico"

VER_MAJ=0
VER_MIN=0
VER_PAT=0
VER_BUILD=b

PRODUCT_FILE_BASE_NAME="mathExpressionTestApp_01"
PRODUCT_SHORT_NAME="Math Expression"
QMAKE_TARGET_PRODUCT="Math Expression Test"
QMAKE_TARGET_DESCRIPTION="Test of the Math Expression handler class"
QMAKE_TARGET_COMPANY="TechnoAnalyt"
QMAKE_TARGET_COPYRIGHT="Copyright © $${QMAKE_TARGET_COMPANY} Ltd. 2019.  All rights reserved."
COMPANY_URL=tehnoanalit.com

#-------------------------------------------------
# in common.pri will be defined VERSION, TARGET, DEBUG SETTINGS
#  global APP DEFINES
#-------------------------------------------------
include( ../../common.pri )
include( ../../app.pri )

TRANSLATIONS = $${PRODUCT_FILE_BASE_NAME}_ru.ts \
$${PRODUCT_FILE_BASE_NAME}_en.ts \
$${PRODUCT_FILE_BASE_NAME}_kk.ts

#END



SOURCES += \
    ZDashBoardPane.cpp \
    ZMathExpressionHandler.cpp \
    ZMathExpressionTextEdit.cpp \
    ZVariableTableModel.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h \
    ZDashBoardPane.h \
    ZMathExpressionHandler.h \
    ZMathExpressionTextEdit.h \
    ZVariableTableModel.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
