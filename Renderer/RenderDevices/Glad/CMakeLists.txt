add_library(Glad SHARED src/glad.c include/glad/glad.h include/KHR/khrplatform.h)

include_directories(include)

install (TARGETS Glad LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
