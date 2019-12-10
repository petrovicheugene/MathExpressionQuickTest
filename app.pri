#------------------------------------------------- 
DESTDIR = $${BIN_PATH}/ 
linux-g++: QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/../../lib.$${OS_SUFFIX}/ 

CONFIG(debug, debug|release) { 
    TARGET=$${TARGET}-$${VERSION}.$${VER_BUILD} 
} else { 
    TARGET=$${TARGET}-$${VERSION} 
} 
