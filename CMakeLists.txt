cmake_minimum_required(VERSION 3.10)

project(arquivos)


file(GLOB lib_files ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/include/*.h)

include_directories(${PROJECT_SOURCE_DIR}/include)


add_library(libestud ${lib_files})
add_executable(estud main.cpp)

target_link_libraries(estud PUBLIC libestud)

enable_testing()

ADD_TEST(NAME RunTest COMMAND sh -c "$<TARGET_FILE:estud> > ${PROJECT_SOURCE_DIR}/output/output")
ADD_TEST(RunCompare ${CMAKE_COMMAND} -E compare_files ${PROJECT_SOURCE_DIR}/output/output ${PROJECT_SOURCE_DIR}/output/output.txt)
