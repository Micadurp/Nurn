# CMake settings
cmake_minimum_required(VERSION 3.6)

# Root project settings
set(PROJECT_NAME Nurn)
project(${PROJECT_NAME})


# Set the files used in the target
file(GLOB_RECURSE HEADERS Headers/ *.hpp)
file(GLOB_RECURSE SOURCES Source/ *.cpp)
include_directories(Include)

create_source_group("Header Files" "${CMAKE_CURRENT_SOURCE_DIR}/Include" ${HEADERS})
create_source_group("Source Files" "${CMAKE_CURRENT_SOURCE_DIR}/Source" ${SOURCES})

set(DEFINITIONS _WINDLL)

add_library(${PROJECT_NAME} SHARED "${HEADERS}" "${SOURCES}")
target_include_directories(${PROJECT_NAME} PUBLIC "${INCLUDE_DIRECTORIES}")
target_link_libraries(${PROJECT_NAME} "${LIBRARIES}")
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
target_compile_definitions(${PROJECT_NAME} PRIVATE "${DEFINITIONS}")