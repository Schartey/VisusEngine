set(CMAKE_VERBOSE_MAKEFILE ON)

ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

add_subdirectory(Glad)

if(UNIX)
	find_package(GLFW REQUIRED)
else()
	list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
	find_package(GLFW MODULE REQUIRED)
endif()

#Logger should be loaded further up the hierachy. Surely also need it somewhere else.
FIND_PACKAGE(Boost COMPONENTS log REQUIRED)
find_package(OpenGL REQUIRED)

set(SOURCE_GL   src/OpenGL/RenderDeviceOpenGL.cpp
                src/OpenGL/AssetManagerDeviceOpenGL.cpp)

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

target_include_directories(RenderDeviceOpenGL PUBLIC ${BOOST_INCLUDE_DIRS})

target_link_libraries(RenderDeviceOpenGL Glad)
target_link_libraries(RenderDeviceOpenGL ${Boost_LIBRARIES})

install (TARGETS RenderDeviceD3D RenderDeviceOpenGL LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
