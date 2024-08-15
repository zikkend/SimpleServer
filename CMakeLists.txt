cmake_minimum_required(VERSION 3.10)
project(Server)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost 1.75 REQUIRED COMPONENTS system)

add_executable(server server.cpp)

target_link_libraries(server Boost::system)

# Check if we are using MinGW
if (CMAKE_SYSTEM_NAME STREQUAL "Windows" AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Detected MinGW on Windows")
    # You can add MinGW-specific settings here
    set(USING_MINGW TRUE)
else()
    set(USING_MINGW FALSE)
endif()

# You can conditionally add libraries or flags based on this check
if (USING_MINGW)
    target_link_libraries(server ws2_32)
endif()
