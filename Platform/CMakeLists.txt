set(SOURCE  src/DLHelper.cpp)

set(HEADER  include/Platform.h include/DLHelper.h)

add_library(Platform ${SOURCE} ${HEADER})

include_directories(include)

install (TARGETS Platform LIBRARY DESTINATION lib
	  		ARCHIVE DESTINATION lib)
