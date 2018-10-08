add_library(Audio src/Audio.cpp include/Audio.h)

install (TARGETS Audio LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
