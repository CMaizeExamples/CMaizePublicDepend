cmake_minimum_required(VERSION 3.14)

project(CMaizePublicDepend VERSION 1.0.0 LANGUAGES CXX)

set(
    CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake"
    CACHE STRING "" FORCE
)

include(get_cmaize)

# Get dependencies
# This works whether building or finding an installed version of CMakePublic
cmaize_find_or_build_dependency(
    CMakePublic
    URL github.com/CMaizeExamples/CMakePublic
    BUILD_TARGET world
    FIND_TARGET CMakePublic::world
    CMAKE_ARGS BUILD_TESTING=FALSE
)

# Works fine
# find_package(CMakePublic REQUIRED COMPONENTS hello world CONFIG)

# Also works fine
# find_package(CMakePublic CONFIG)

# Build the library
cmaize_add_library(
    ${PROJECT_NAME}
    INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include/cmaize_public_depend"
    SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/src/cmaize_public_depend"
    DEPENDS CMakePublic
)

if (BUILD_TESTING)
    # Build tests
    cmaize_find_or_build_dependency(
        Catch2
        URL github.com/catchorg/Catch2
        BUILD_TARGET Catch2
        FIND_TARGET Catch2::Catch2WithMain
        VERSION v3.0.1
    )

    cmaize_add_tests(
        test_${PROJECT_NAME}
        SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/test/cmaize_public_depend"
        INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/src/cmaize_public_depend"
        DEPENDS Catch2::Catch2WithMain ${PROJECT_NAME}
    )
endif()

# Install the package
cmaize_add_package(${PROJECT_NAME})
