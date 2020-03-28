cmake_minimum_required(VERSION 3.12)
project(homework1)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(OpenCV REQUIRED)
add_executable(homework_1 homework_1.cpp)
target_link_libraries(homework_1 ${OpenCV_LIBS})