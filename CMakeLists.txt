cmake_minimum_required(VERSION 3.15)
project(VPS LANGUAGES CXX)

find_package(Eigen3 REQUIRED)
find_package(assimp REQUIRED)
find_package(Ceres REQUIRED)
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} Eigen3::Eigen)
target_link_libraries(${PROJECT_NAME} assimp::assimp)
target_link_libraries(${PROJECT_NAME} Ceres::ceres)

include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} )

