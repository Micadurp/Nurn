# CMake settings
cmake_minimum_required(VERSION 3.6)

# Root project settings
set(PROJECT_NAME Nurn)


# Set the files used in the target
file(GLOB_RECURSE HEADERS *.hpp)
file(GLOB_RECURSE SOURCES *.cpp)

create_source_group("Header Files" "${CMAKE_CURRENT_SOURCE_DIR}/Include" ${HEADERS})
create_source_group("Source Files" "${CMAKE_CURRENT_SOURCE_DIR}/Source" ${SOURCES})

set(INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/Include)

set(DEFINITIONS NURN_EXPORTS)

add_library(${PROJECT_NAME} SHARED "${HEADERS}" "${SOURCES}")
target_include_directories(${PROJECT_NAME} PUBLIC "${INCLUDE_DIRECTORIES}")
target_compile_definitions(${PROJECT_NAME} PRIVATE "${DEFINITIONS}")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)