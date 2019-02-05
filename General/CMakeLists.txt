add_library(General src/General.cpp include/General.h)

install (TARGETS General LIBRARY DESTINATION lib
	  		ARCHIVE DESTINATION lib)
