cmake_minimum_required(VERSION 3.15)
project(VPS LANGUAGES CXX)

find_package(7bitDI REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} 7bitDI::7bitDI)
