cmake_minimum_required(VERSION 3.14)

project(CMaizePublicDepend VERSION 1.0.0 LANGUAGES CXX)

set(
    CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake"
    CACHE STRING "" FORCE
)

include(get_cmaize)

cpp_find_or_build_dependency(
    CMakePublic
    URL github.com/CMaizeExamples/CMakePublic
    BUILD_TARGET CMakePublic
    FIND_TARGET CMakePublic::CMakePublic
)

cmaize_add_library(
    ${PROJECT_NAME}
    INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include/cmaize_public_depend"
    SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/src/cmaize_public_depend"
    DEPENDS CMakePublic::CMakePublic
)

cpp_find_or_build_dependency(
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

cmaize_add_package(${PROJECT_NAME})
