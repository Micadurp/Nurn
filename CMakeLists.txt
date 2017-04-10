# CMake settings
cmake_minimum_required(VERSION 3.6)

set(SOLUTION_NAME Nurn)
project(${SOLUTION_NAME})

option(COMPILE_RELEASE_BUILD "Unchecked is debug" OFF)

set(OUTPUT_FOLDER ${CMAKE_BINARY_DIR}/build)
set(OUTPUT_FOLDER ${OUTPUT_FOLDER}/32)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_FOLDER})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_FOLDER})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_FOLDER})

# Path for copying .dll to correct folder
if(COMPILE_RELEASE_BUILD)
	set(OUTPUT_FOLDER ${OUTPUT_FOLDER}/Release)	
else()
	set(OUTPUT_FOLDER ${OUTPUT_FOLDER}/Debug)
endif()

# Find external libraries and modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/Modules/")
include(create_source_group)


set(EXTERNAL_INCLUDE_DIRS)
set(EXTERNAL_LIBRARIES_ALL)
include_directories(${EXTERNAL_INCLUDE_DIRS})

# Set global compiler options
add_definitions(-DUNICODE -D_UNICODE)

# Add subdirectories
add_subdirectory(NurnCode)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT NurnCode)



# Set the default configuration
if (COMPILE_RELEASE_BUILD)
    set(CMAKE_BUILD_TYPE "Release")
else()
    set(CMAKE_BUILD_TYPE "Debug")
endif()
set(CMAKE_CONFIGURATION_TYPES ${CMAKE_BUILD_TYPE} CACHE STRING "" FORCE)