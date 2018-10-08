add_library(Input src/Input.cpp include/Input.h)

install (TARGETS Input LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
