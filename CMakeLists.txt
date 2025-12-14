cmake_minimum_required(VERSION 3.10)
project(allocator C)

add_library(stack ${CMAKE_SOURCE_DIR}/source/stack.c)
add_library(header INTERFACE)

add_executable(allocator ${CMAKE_SOURCE_DIR}/source/main.c)

target_include_directories(stack PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(header INTERFACE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(stack PRIVATE header)
target_link_libraries(allocator PRIVATE stack)
