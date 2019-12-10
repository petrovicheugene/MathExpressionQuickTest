QT       += core gui

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

PRODUCT_SHORT_NAME="MathExpressionTestApp_01"
PRODUCT_FILE_BASE_NAME="mathExpressionTestApp_01"
QMAKE_TARGET_PRODUCT="MathExpressionTestApp_01"
QMAKE_TARGET_DESCRIPTION="Math Expression Test App_01"
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
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
