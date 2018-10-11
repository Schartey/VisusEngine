set(CMAKE_VERBOSE_MAKEFILE ON)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(RenderDevices)
#add_subdirectory(Window)

FIND_PACKAGE(DevIL REQUIRED)

set(SOURCE  src/Asset/AssetManager.cpp
            src/Asset/ImageLoader.cpp
            src/SkinManager.cpp
            src/Renderer.cpp)

set(HEADER  include/Asset/Asset.h
            include/Asset/AssetManager.h
            include/Asset/AssetManagerDevice.h
            include/Asset/ImageLoader.h
            include/SkinManager.h
            include/Renderer.h
            include/RenderDevice.h
            include/Common.h)

add_library(Renderer ${SOURCE} ${HEADER})

include_directories(include)

target_include_directories(Renderer PUBLIC ${DevIL_INCLUDE_DIRS})

target_link_libraries(Renderer RenderDeviceD3D)
target_link_libraries(Renderer RenderDeviceOpenGL)
target_link_libraries(Renderer Utils)
#target_link_libraries(Renderer XWindow)
#target_link_libraries(Renderer WWindow)
target_link_libraries(Renderer IL)

#----maybe not needed-------------
target_link_libraries(Renderer ILU)
target_link_libraries(Renderer ILUT)
#---------------------------------
target_link_libraries(Renderer ${CMAKE_DL_LIBS})

message(STATUS Test: ${DevIL_LIBS})

install (TARGETS Renderer LIBRARY DESTINATION lib
			  ARCHIVE DESTINATION lib)
