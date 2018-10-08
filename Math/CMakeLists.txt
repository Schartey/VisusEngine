add_library(Math src/Math.cpp include/Math.h)

install (TARGETS Math LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
