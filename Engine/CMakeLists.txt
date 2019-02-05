set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(Engine main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/General/include) # include General
include_directories(${CMAKE_SOURCE_DIR}/Renderer/include) # include Renderer
target_link_libraries(Engine Renderer)

install (TARGETS Engine RUNTIME DESTINATION bin)
