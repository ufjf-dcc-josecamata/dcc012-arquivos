cmake_minimum_required(VERSION 3.10)

project(arquivos)


file(GLOB lib_files ${PROJECT_SOURCE_DIR}/src/*.c ${PROJECT_SOURCE_DIR}/include/*.c ${PROJECT_SOURCE_DIR}/include/*.h)
include_directories(${PROJECT_SOURCE_DIR}/include)


add_library(libestud ${lib_files})
add_executable(estud main.c)
target_link_libraries(estud PUBLIC libestud)
