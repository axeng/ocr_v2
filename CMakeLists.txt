cmake_minimum_required(VERSION 3.14)
project(ocr_v2)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "-pedantic -Werror -Wall -Wextra -std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast")

set(CMAKE_CXX_STANDARD 17)
set(TARGET ocr)

include_directories(src)

# EXEC SOURCES
set(EXEC_SOURCES
        src/main.cc)
# ----------

# MAIN SOURCES
set(MAIN_SOURCES
        ${EXEC_SOURCES})


add_executable(${TARGET}
        ${MAIN_SOURCES})