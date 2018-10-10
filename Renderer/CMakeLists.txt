set(CMAKE_VERBOSE_MAKEFILE ON)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(RenderDevices)
#add_subdirectory(Window)

set(SOURCE  src/SkinManager.cpp
            src/Renderer.cpp)

set(HEADER  include/SkinManager.h
            include/Renderer.h
            include/RenderDevice.h
            include/Common.h)

add_library(Renderer ${SOURCE} ${HEADER})

include_directories(include)

target_link_libraries(Renderer RenderDeviceD3D)
target_link_libraries(Renderer RenderDeviceOpenGL)
#target_link_libraries(Renderer XWindow)
#target_link_libraries(Renderer WWindow)
target_link_libraries(Renderer ${CMAKE_DL_LIBS})


install (TARGETS Renderer LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
