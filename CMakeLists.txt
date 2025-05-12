# Always declare the minimum CMake version FIRST
cmake_minimum_required(VERSION 3.16)
project(main LANGUAGES CXX)
# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Optional: Ensures strictly standard C++17, no GNU extensions

# Tell pkg-config where to find ftxui.pc
set(ENV{PKG_CONFIG_PATH} "/usercode/local/lib/pkgconfig:$ENV{PKG_CONFIG_PATH}")

# Use pkg-config to find ftxui
find_package(PkgConfig REQUIRED)
pkg_check_modules(FTXUI REQUIRED ftxui)

include_directories(${FTXUI_INCLUDE_DIRS})
link_directories(${FTXUI_LIBRARY_DIRS})

add_executable(main main.cpp)
target_link_libraries(main ${FTXUI_LIBRARIES} pthread)

