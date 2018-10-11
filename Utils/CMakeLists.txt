set(SOURCE  src/Utils.cpp)

set(HEADER  include/Utils.h)

add_library(Utils ${SOURCE} ${HEADER})

install (TARGETS Utils LIBRARY DESTINATION lib
	  		ARCHIVE DESTINATION lib)
