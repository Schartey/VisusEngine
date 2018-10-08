add_executable(Engine main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/Renderer) # include Renderer
target_link_libraries(Engine Renderer)

install (TARGETS Engine RUNTIME DESTINATION bin)
