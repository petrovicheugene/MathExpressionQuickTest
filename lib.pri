#------------------------------------------------- 
DESTDIR = $${LIBS_PATH}/ 
  
win32: { 
DLLDESTDIR = $${BIN_PATH}/ 
CONFIG += skip_target_version_ext 
} 
  
unix: { 
CONFIG += unversioned_libname 
} 
  
TARGET = $${TARGET}$${LIB_SUFFIX} 
