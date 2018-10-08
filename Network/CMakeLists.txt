add_library(Network src/Network.cpp include/Network.h)

install (TARGETS Network LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
