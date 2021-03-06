cmake_minimum_required(VERSION 3.14)
project(ocr_v2)

# 'Debug' or 'Release'
set(CMAKE_BUILD_TYPE Debug)

############### COMPILATION FLAGS ###############
# General compilation flags
set(CMAKE_CXX_FLAGS "-pedantic -Werror -Wall -Wextra -std=c++17")

# Debug compilation flags
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")

# Release compilation flags
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -DRELEASE -DNDEBUG -march=native")
##################################################

set(CMAKE_CXX_STANDARD 17)

set(MAIN_TARGET ocr)
set(UNIT_TESTS_TARGET unit_tests)

################## DIRECTORIES ##################
# Lib directories
include_directories(lib)
include_directories(lib/misc)
include_directories(lib/misc/matrix)
include_directories(lib/misc/random)
include_directories(lib/misc/singleton)
include_directories(lib/neural_network)
include_directories(lib/neural_network/activation_function)
include_directories(lib/neural_network/layer)

# Main directories
include_directories(src)
##################################################

#################### SOURCES ####################
# LIB SOURCES
# Matrix
set(MISC_MATRIX_SOURCES
        lib/misc/matrix/matrix.cc
        lib/misc/matrix/matrix.hh

        lib/misc/matrix/lib-matrix.cc
        lib/misc/matrix/lib-matrix.hh)

# Random
set(MISC_RANDOM_SOURCES
        lib/misc/random/uniform-random.hxx
        lib/misc/random/uniform-random.hh)

# Singleton
set(MISC_SINGLETON_SOURCES
        lib/misc/singleton/singleton.hxx
        lib/misc/singleton/singleton.hh)

# Misc
set(MISC_SOURCES
        ${MISC_RANDOM_SOURCES}
        ${MISC_MATRIX_SOURCES}
        ${MISC_SINGLETON_SOURCES})

# Neural Network
set(NEURAL_NETWORK_SOURCES
        lib/neural_network/neural-network.cc
        lib/neural_network/neural-network.hh

        lib/neural_network/activation_function/activation-function.hxx
        lib/neural_network/activation_function/activation-function.hh
        lib/neural_network/activation_function/simple-activation-function.hxx
        lib/neural_network/activation_function/simple-activation-function.hh
        lib/neural_network/activation_function/sigmoid-function.hxx
        lib/neural_network/activation_function/sigmoid-function.hh
        lib/neural_network/activation_function/softmax-function.hxx
        lib/neural_network/activation_function/softmax-function.hh

        lib/neural_network/layer/layer.hxx
        lib/neural_network/layer/layer.hh
        lib/neural_network/layer/fully-connected-layer.cc
        lib/neural_network/layer/fully-connected-layer.hh)

set(LIB_SOURCES
        ${MISC_SOURCES}
        ${NEURAL_NETWORK_SOURCES})

# MAIN SOURCES
# Exec
set(EXEC_SOURCES
        src/main.cc)

set(MAIN_SOURCES
        ${EXEC_SOURCES})

# TESTS SOURCES
# Unit Tests
set(UNIT_TESTS_SOURCES
        tests/unit_tests/main.cc
        tests/unit_tests/lib-matrix.cc
        tests/unit_tests/lib-random.cc
        tests/unit_tests/lib-singleton.cc

        ${LIB_SOURCES})
##################################################

# Main Executable
add_executable(${MAIN_TARGET}
        ${LIB_SOURCES}
        ${MAIN_SOURCES})

# Unit Tests Custom Target
add_custom_target(unit
        COMMAND ./${UNIT_TESTS_TARGET}
        DEPENDS ${UNIT_TESTS_TARGET})


###############################################################################
#                                 GOOGLE TEST                                 #
###############################################################################

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif ()

# Unit Tests Executable
add_executable(${UNIT_TESTS_TARGET} ${UNIT_TESTS_SOURCES})
target_link_libraries(${UNIT_TESTS_TARGET} gtest_main)