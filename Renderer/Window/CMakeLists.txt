# These libraries are for future use -> I want to replace GLFW3 Window initializiation with my own code at some point
add_library(XWindow SHARED src/XWindow.c include/XWindow.h src/GLXContext.c include/GLXContext.h)
add_library(WWindow SHARED src/WWindow.cpp include/WWindow.h)

include_directories(include)

install (TARGETS XWindow WWindow LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
