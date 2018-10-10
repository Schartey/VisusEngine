add_library(Logger src/Logger.cpp include/Logger.h)

install (TARGETS Logger LIBRARY DESTINATION lib
	  		ARCHIVE DESTINATION lib)
