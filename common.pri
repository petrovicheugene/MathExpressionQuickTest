#=================================================
PROJECT_ROOT_PATH = $${PWD}/ 
 
win32: OS_SUFFIX = win32 
linux-g++: OS_SUFFIX = linux 
  
  
CONFIG += c++11 
CONFIG += c++14 
CONFIG += c++17 
 
VERSION=$${VER_MAJ}.$${VER_MIN}.$${VER_PAT} 
  
CONFIG(debug, debug|release) { 
    BUILD_FLAG = debug 
    LIB_SUFFIX = d 
} else { 
    BUILD_FLAG = release 
} 
  
# The following define makes your compiler emit warnings if you use 
# any feature of Qt which has been marked as deprecated (the exact warnings 
# depend on your compiler). Please consult the documentation of the 
# deprecated API in order to know how to port your code away from it. 
DEFINES += QT_DEPRECATED_WARNINGS 
  
# You can also make your code fail to compile if you use deprecated APIs. 
# In order to do so, uncomment the following line. 
# You can also select to disable deprecated APIs only up to a certain version of Qt. 
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0 
  
#Define the preprocessor macro to get the application version in the application.
DEFINES += APP_DISPLAY_NAME=\"\\\"$${QMAKE_TARGET_PRODUCT}\\\"\"
DEFINES += APP_PRODUCT=\"\\\"$${PRODUCT_SHORT_NAME}\\\"\"
DEFINES += APP_VERSION=\"\\\"$${VERSION}.$${VER_RELEASE}\\\"\"
DEFINES += APP_COMPANY=\"\\\"$${QMAKE_TARGET_COMPANY}\\\"\"
DEFINES += APP_COMPANY_URL=\"\\\"$${COMPANY_URL}\\\"\"
DEFINES += APP_COPYRIGHT=\"\\\"$${QMAKE_TARGET_COPYRIGHT}\\\"\"
DEFINES += APP_ICON=\"\\\"$${RC_ICONS}\\\"\"

#DEBUG SETTINGS
CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT
#by default defined: in Debug mode QT_DEBUG, in Release mode QT_NO_DEBUG

QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
  
LIBS_PATH = $${PROJECT_ROOT_PATH}/lib.$${OS_SUFFIX}/ 
EXPORT_PATH = $${PROJECT_ROOT_PATH}/export/ 
IMPORT_PATH = $${PROJECT_ROOT_PATH}/import/ 
COMMON_PATH = $${PROJECT_ROOT_PATH}/src/common/ 
BIN_PATH = $${PROJECT_ROOT_PATH}/bin/$${BUILD_FLAG}/ 
  
BUILD_PATH = $${PROJECT_ROOT_PATH}/build/$${BUILD_FLAG}/$${TARGET}/ 
RCC_DIR = $${BUILD_PATH}/rcc/ 
UI_DIR = $${BUILD_PATH}/ui/ 
MOC_DIR = $${BUILD_PATH}/moc/ 
OBJECTS_DIR = $${BUILD_PATH}/obj/ 
  
LIBS += -L$${LIBS_PATH}/ 
INCLUDEPATH += $${EXPORT_PATH}/ 
INCLUDEPATH += $${IMPORT_PATH}/ 
INCLUDEPATH += $${COMMON_PATH}/ 
  
linux-g++: QMAKE_CXXFLAGS += -std=c++11 
