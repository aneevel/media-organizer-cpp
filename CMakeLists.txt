cmake_minimum_required(VERSION 3.16)
project(media-organizer CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(media-organizer src/main.cpp)
target_link_libraries(media-organizer ${GTKMM_LIBRARIES})
target_compile_options(media-organizer PRIVATE ${GTKMM_CFLAGS_OTHER})

