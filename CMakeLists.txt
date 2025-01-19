# Минимальная версия CMake
cmake_minimum_required(VERSION 3.30)

project(UPR C)
set(CMAKE_C_STANDARD 99)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

set(SRC
    ${SRC_DIR}/cli.c
    ${SRC_DIR}/dependency_manager.c
    ${SRC_DIR}/file_manager.c
    ${SRC_DIR}/repository.c
    ${SRC_DIR}/package_manager.c
)

set(INCLUDE
    ${INCLUDE_DIR}/cli.h
    ${INCLUDE_DIR}/dependency_manager.h
    ${INCLUDE_DIR}/file_manager.h
    ${INCLUDE_DIR}/repository.h
    ${INCLUDE_DIR}/package_manager.h
)

add_library(core STATIC
    ${SRC}
    ${INCLUDE}
)

add_executable(UPR ${SRC_DIR}/main.c)

target_link_libraries(UPR PRIVATE core)

set_target_properties(UPR PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

target_include_directories(core PUBLIC ${INCLUDE_DIR})
target_include_directories(UPR PRIVATE ${INCLUDE_DIR})