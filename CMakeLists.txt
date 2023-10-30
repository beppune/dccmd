
cmake_minimum_required(VERSION 3.20.0)

project(dccmd)

set(CXX_STANDARD 17)

## Setup Xlnt
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND WIN32)
    message(FATAL_ERROR "vcpkg.cmake integration not found: run cmake with -DCMAKE_TOOLCHAIN_FILE:PATH=<path to vcpkg.cmake>")
    # C:/Users/manzo/Software/vcpkg/scripts/buildsystems/vcpkg.cmake
endif()

if(WIN32)
    add_compile_definitions(_WIN32_WINNT=0x0601)
endif()

find_package(Xlnt CONFIG REQUIRED)

set(Boost_USE_STATIC_LIBS ON)

find_package(Boost REQUIRED COMPONENTS program_options)

## Setup Target
add_executable(dccmd main.cpp)
target_link_libraries(dccmd PRIVATE xlnt::xlnt Boost::program_options)