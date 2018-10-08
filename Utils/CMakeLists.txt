add_library(Utils src/Utils.cpp include/Utils.h)

install (TARGETS Utils LIBRARY DESTINATION lib
	  		ARCHIVE DESTINATION lib)
