cmake_minimum_required(VERSION 2.6)
project(MiniPlatformer)

LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2IMAGE_INCLUDE_DIR})

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

