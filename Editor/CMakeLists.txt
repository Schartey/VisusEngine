add_library(Editor src/Editor.cpp include/Editor.h)

install (TARGETS Editor LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
