mkdir bin
cd bin
mkdir debug
mkdir release
cd..

#mkdir build
#cd build
#mkdir debug
#mkdir release
#cd..

mkdir import
mkdir export
mkdir lib.linux
mkdir lib.win

mkdir src
cd src
mkdir common
cd.. 

mkdir test
cd test
cd..

#app.pri
@echo #------------------------------------------------- > app.pri
@echo DESTDIR = $${BIN_PATH}/ >> app.pri
@echo linux-g++: QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/../../lib.$${OS_SUFFIX}/ >> app.pri
@echo.>> app.pri
@echo CONFIG(debug, debug^|release) { >> app.pri
@echo     TARGET=$${TARGET}-$${VERSION}.$${VER_BUILD} >> app.pri
@echo } else { >> app.pri
@echo     TARGET=$${TARGET}-$${VERSION} >> app.pri
@echo } >> app.pri

#common.pri 
@echo #------------------------------------------------- > common.pri
@echo PROJECT_ROOT_PATH = $${PWD}/ >> common.pri
@echo. >> common.pri
@echo win32: OS_SUFFIX = win32 >> common.pri
@echo linux-g++: OS_SUFFIX = linux >> common.pri
@echo. >> common.pri 
@echo. >> common.pri 
@echo CONFIG += c++11 >> common.pri
@echo CONFIG += c++14 >> common.pri
@echo CONFIG += c++17 >> common.pri
@echo. >> common.pri
@echo VERSION=$${VER_MAJ}.$${VER_MIN}.$${VER_PAT} >> common.pri
@echo. >> common.pri 
@echo CONFIG(debug, debug^|release) { >> common.pri
@echo     BUILD_FLAG = debug >> common.pri
@echo     LIB_SUFFIX = d >> common.pri
@echo } else { >> common.pri
@echo     BUILD_FLAG = release >> common.pri
@echo } >> common.pri
@echo. >> common.pri 
@echo # The following define makes your compiler emit warnings if you use >> common.pri
@echo # any feature of Qt which has been marked as deprecated (the exact warnings >> common.pri
@echo # depend on your compiler). Please consult the documentation of the >> common.pri
@echo # deprecated API in order to know how to port your code away from it. >> common.pri
@echo DEFINES += QT_DEPRECATED_WARNINGS >> common.pri
@echo. >> common.pri 
@echo # You can also make your code fail to compile if you use deprecated APIs. >> common.pri
@echo # In order to do so, uncomment the following line. >> common.pri
@echo # You can also select to disable deprecated APIs only up to a certain version of Qt. >> common.pri
@echo #DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0 >> common.pri
@echo. >> common.pri 
@echo #Define the preprocessor macro to get the application version in the application. >> common.pri
@echo DEFINES += APP_PRODUCT=\"\\\"$${QMAKE_TARGET_PRODUCT}\\\"\" >> common.pri
@echo DEFINES += APP_EXE_BASE_NAME=\"\\\"$${EXE_BASE_NAME}\\\"\" >> common.pri
@echo DEFINES += APP_VERSION=\"\\\"$${VERSION}.$${VER_RELEASE}\\\"\" >> common.pri
@echo DEFINES += APP_COMPANY=\"\\\"$${QMAKE_TARGET_COMPANY}\\\"\" >> common.pri
@echo DEFINES += APP_COMPANY_URL=\"\\\"$${COMPANY_URL}\\\"\" >> common.pri
@echo DEFINES += APP_COPYRIGHT=\"\\\"$${QMAKE_TARGET_COPYRIGHT}\\\"\" >> common.pri
@echo DEFINES += APP_ICON=\"\\\"$${RC_ICONS}\\\"\" >> common.pri
@echo. >> common.pri 
@echo #DEBUG SETTINGS >> common.pri
@echo CONFIG(release, debug^|release):DEFINES += QT_NO_DEBUG_OUTPUT >> common.pri
@echo #by default defined: in Debug mode QT_DEBUG, in Release mode QT_NO_DEBUG >> common.pri
@echo. >> common.pri 
@echo QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter >> common.pri
@echo. >> common.pri 
@echo LIBS_PATH = $${PROJECT_ROOT_PATH}/lib.$${OS_SUFFIX}/ >> common.pri
@echo EXPORT_PATH = $${PROJECT_ROOT_PATH}/export/ >> common.pri
@echo IMPORT_PATH = $${PROJECT_ROOT_PATH}/import/ >> common.pri
@echo COMMON_PATH = $${PROJECT_ROOT_PATH}/src/common/ >> common.pri
@echo BIN_PATH = $${PROJECT_ROOT_PATH}/bin/$${BUILD_FLAG}/ >> common.pri
@echo. >> common.pri 
@echo BUILD_PATH = $${PROJECT_ROOT_PATH}/build/$${BUILD_FLAG}/$${TARGET}/ >> common.pri
@echo RCC_DIR = $${BUILD_PATH}/rcc/ >> common.pri
@echo UI_DIR = $${BUILD_PATH}/ui/ >> common.pri
@echo MOC_DIR = $${BUILD_PATH}/moc/ >> common.pri
@echo OBJECTS_DIR = $${BUILD_PATH}/obj/ >> common.pri
@echo. >> common.pri 
@echo LIBS += -L$${LIBS_PATH}/ >> common.pri
@echo INCLUDEPATH += $${EXPORT_PATH}/ >> common.pri
@echo INCLUDEPATH += $${IMPORT_PATH}/ >> common.pri
@echo INCLUDEPATH += $${COMMON_PATH}/ >> common.pri
@echo. >> common.pri 
@echo linux-g++: QMAKE_CXXFLAGS += -std=c++11 >> common.pri

#lib.pri 
@echo #------------------------------------------------- > lib.pri
@echo DESTDIR = $${LIBS_PATH}/ >> lib.pri
@echo. >> lib.pri 
@echo win32: { >> lib.pri
@echo DLLDESTDIR = $${BIN_PATH}/ >> lib.pri
@echo CONFIG += skip_target_version_ext >> lib.pri
@echo } >> lib.pri
@echo. >> lib.pri 
@echo unix: { >> lib.pri
@echo CONFIG += unversioned_libname >> lib.pri
@echo } >> lib.pri
@echo. >> lib.pri 
@echo TARGET = $${TARGET}$${LIB_SUFFIX} >> lib.pri


