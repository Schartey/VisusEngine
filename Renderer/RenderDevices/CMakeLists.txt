set(CMAKE_VERBOSE_MAKEFILE ON)

ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

add_subdirectory(Glad)

FIND_PACKAGE(Boost COMPONENTS log REQUIRED)
find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)

set(SOURCE_GL   src/OpenGL/RenderDeviceOpenGL.cpp
                src/OpenGL/SkinManagerOpenGL.cpp)

set(SOURCE_D3D  src/D3D/RenderDeviceD3D.cpp
                src/D3D/SkinManagerD3D.cpp)

set(HEADER_GL   include/OpenGL/RenderDeviceOpenGL.h
                include/OpenGL/SkinManagerOpenGL.h)

set(HEADER_D3D  include/D3D/RenderDeviceD3D.h
                include/D3D/SkinManagerD3D.h)

add_library(RenderDeviceOpenGL SHARED ${SOURCE_GL} ${HEADER_GL})
add_library(RenderDeviceD3D SHARED ${SOURCE_D3D} ${HEADER_D3D})

include_directories(include)

target_include_directories(RenderDeviceOpenGL PUBLIC ${OPENGL_INCLUDE_DIR})
target_include_directories(RenderDeviceOpenGL PUBLIC ${BOOST_INCLUDE_DIRS})

target_link_libraries(RenderDeviceOpenGL ${OPENGL_gl_LIBRARY})
target_link_libraries(RenderDeviceOpenGL glfw)
target_link_libraries(RenderDeviceOpenGL Glad)
target_link_libraries(RenderDeviceOpenGL ${Boost_LIBRARIES})

install (TARGETS RenderDeviceD3D RenderDeviceOpenGL LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
