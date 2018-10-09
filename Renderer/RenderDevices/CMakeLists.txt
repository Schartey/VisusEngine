set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(Glad)

find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)

add_library(RenderDeviceD3D SHARED src/RenderDeviceD3D.cpp include/RenderDeviceD3D.h)
add_library(RenderDeviceOpenGL SHARED src/RenderDeviceOpenGL.cpp include/RenderDeviceOpenGL.h)

include_directories(include)

target_include_directories(RenderDeviceOpenGL PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(RenderDeviceOpenGL glfw ${OPENGL_gl_LIBRARY})
target_link_libraries(RenderDeviceOpenGL Glad)

install (TARGETS RenderDeviceD3D RenderDeviceOpenGL LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
