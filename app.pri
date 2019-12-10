#------------------------------------------------- 
DESTDIR = $${BIN_PATH}/ 
linux-g++: QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/../../lib.$${OS_SUFFIX}/ 

CONFIG(debug, debug|release) {
    TARGET=$${PRODUCT_FILE_BASE_NAME}-$${VERSION}.$${BUILD_FLAG}
} else {
    TARGET=$${PRODUCT_FILE_BASE_NAME}
}
