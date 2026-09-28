cmake_minimum_required(VERSION 3.14)
project(rk4_integrator VERSION 1.0.0 LANGUAGES CXX)

# Création de la bibliothèque header-only
add_library(rk4_integrator INTERFACE)

# Ajout d'un alias pour permettre l'inclusion via FetchContent ou add_subdirectory dans d'autres projets
add_library(rk4_integrator::rk4_integrator ALIAS rk4_integrator)

# Définition des dossiers d'inclusion
target_include_directories(rk4_integrator INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# --- Optionnel : Compiler les exemples ---
option(RK4_BUILD_EXAMPLES "Build the examples" ON)

if(RK4_BUILD_EXAMPLES)
    add_executable(basic_example examples/basic_example.cpp)
    target_link_libraries(basic_example PRIVATE rk4_integrator)
endif()
