cmake_minimum_required(VERSION 3.12)
project(homework_3)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(OpenCV REQUIRED)
add_executable(homework_3 homework_3.cpp)
target_link_libraries(homework_3 ${OpenCV_LIBS})
