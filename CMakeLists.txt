cmake_minimum_required(VERSION 3.10)
project(UniversalRK4 VERSION 1.0)

# On crée une bibliothèque de type INTERFACE (header-only)
add_library(rk4 INTERFACE)

# On indique à CMake où se trouvent les headers pour tout projet qui "linkera" rk4
target_include_directories(rk4 INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
