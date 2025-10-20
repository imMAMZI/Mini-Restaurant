cmake_minimum_required(VERSION 3.15)
project(MiniRestaurant)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic)

# Gather all .cpp files in libraries/
file(GLOB LIB_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_SOURCE_DIR}/libraries/*.cpp"
)

# Create the executable
add_executable(MiniRestaurant
        main.cpp
        ${LIB_SOURCES}
)

# Include directories
target_include_directories(MiniRestaurant PRIVATE
        ${CMAKE_SOURCE_DIR}/libraries
        ${CMAKE_SOURCE_DIR}
)
