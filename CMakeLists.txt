cmake_minimum_required(VERSION 3.15)
project(VPS)

find_package(Eigen3 REQUIRED)
find_package(assimp REQUIRED)
find_package(Ceres REQUIRED)
find_package(OpenCV REQUIRED)
find_package(TinyGLTF REQUIRED)
find_package(draco REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( ${TinyGLTF_INCLUDE_DIRS})

file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Eigen3::Eigen)
target_link_libraries(${PROJECT_NAME} assimp::assimp)
target_link_libraries(${PROJECT_NAME} Ceres::ceres)
target_link_libraries(${PROJECT_NAME} draco::draco)
target_link_libraries(${PROJECT_NAME} TinyGLTF::TinyGLTF)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} )
