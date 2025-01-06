cmake_minimum_required(VERSION 3.10)

project(URP)

set(CMAKE_C_STANDARD 99)

set(SRC
    src/cli.c
    src/dependency_manager.c
    src/file_manager.c
    src/repository.c
    src/package_manager.c
)

set(INCLUDE
    include/cli.h
    include/dependency_manager.h
    include/file_manager.h
    include/repository.h
    include/package_manager.h
)

add_library(core
    ${SRC}
    ${CORE_SRC}
)

add_executable(URP
    src/main.c
)

target_link_libraries(URP PRIVATE core)

set_target_properties(URP PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)
