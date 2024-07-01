# cmake_minimum_required(VERSION 3.28)
# project(transpiler)

# set(CMAKE_CXX_STANDARD 17)

# add_executable(transpiler main.cpp)

cmake_minimum_required(VERSION 3.8)

project(transpiler)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Iinclude")

add_compile_definitions(__R4J_DEBUG__)

file(GLOB_RECURSE RBLX4JSOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE RBLX4JHEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

add_executable(rblx4jc "${RBLX4JSOURCES}" "${RBLX4JHEADERS}")