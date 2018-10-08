add_subdirectory(Glad)

add_library(RenderDeviceD3D SHARED src/RenderDeviceD3D.cpp include/RenderDeviceD3D.h)
add_library(RenderDeviceOpenGL SHARED src/RenderDeviceOpenGL.cpp include/RenderDeviceOpenGL.h)

include_directories(include)

target_link_libraries(RenderDeviceOpenGL Glad)

install (TARGETS RenderDeviceD3D RenderDeviceOpenGL LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
