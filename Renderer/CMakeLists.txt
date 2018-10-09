set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(RenderDevices)
add_subdirectory(Window)

add_library(Renderer src/Renderer.cpp include/Renderer.h include/RenderDevice.h src/Window.cpp include/Window.h)

include_directories(include)

target_link_libraries(Renderer RenderDeviceD3D)
target_link_libraries(Renderer RenderDeviceOpenGL)
#target_link_libraries(Renderer XWindow)
#target_link_libraries(Renderer WWindow)
target_link_libraries(Renderer ${CMAKE_DL_LIBS})


install (TARGETS Renderer LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
