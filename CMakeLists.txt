cmake_minimum_required(VERSION 3.14)
project(xor)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "-pedantic -Werror -Wall -Wextra -std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -DRELEASE")

set(CMAKE_CXX_STANDARD 17)
set(TARGET xor)

include_directories(lib)
include_directories(lib/misc)
include_directories(lib/misc/matrix)

include_directories(src)

# EXEC SOURCES
set(EXEC_SOURCES
        src/main.cc)
# ----------

# MAIN SOURCES
set(MAIN_SOURCES
        ${EXEC_SOURCES})
# ----------

# MISC SOURCES
set(MISC_SOURCES
        lib/misc/matrix/matrix.cc
        lib/misc/matrix/matrix.hh)
# ----------

# LIB SOURCES
set(LIB_SOURCES
        ${MISC_SOURCES})
# ----------

add_executable(${TARGET}
        ${MAIN_SOURCES}
        ${LIB_SOURCES})