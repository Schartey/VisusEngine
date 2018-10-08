add_library(Game src/Game.cpp include/Game.h)

install (TARGETS Game LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
