set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(Glad)

if(UNIX)
	find_package(GLFW REQUIRED)
else()
	list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
	find_package(GLFW MODULE REQUIRED)
endif()

find_package(OpenGL REQUIRED)

add_library(RenderDeviceD3D SHARED src/RenderDeviceD3D.cpp include/RenderDeviceD3D.h)
add_library(RenderDeviceOpenGL SHARED src/RenderDeviceOpenGL.cpp include/RenderDeviceOpenGL.h)

if(NOT UNIX AND GLFW_FOUND)
	include_directories(${GLFW_INCLUDE_DIR})
endif()

include_directories(include)

target_include_directories(RenderDeviceOpenGL PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(RenderDeviceOpenGL ${OPENGL_gl_LIBRARY})

if(UNIX)
	target_link_libraries(RenderDeviceOpenGL glfw)
else(GLFW_FOUND)
	target_link_libraries(RenderDeviceOpenGL GLFW_LIBRARY)
endif()

target_link_libraries(RenderDeviceOpenGL Glad)

install (TARGETS RenderDeviceD3D RenderDeviceOpenGL LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
