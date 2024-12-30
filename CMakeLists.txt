cmake_minimum_required(VERSION 3.16)
project(test_project VERSION 1.0.0)

set(CMAKE_COMPILE_WARNING_AS_ERROR OFF)

# Include DuckDB configuration - now in root folder
include(${CMAKE_CURRENT_SOURCE_DIR}/duckdb.cmake)

# Create executable
add_executable(${CMAKE_PROJECT_NAME} main.cpp)

# Link DuckDB
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE DuckDB::duckdb)

# Windows-specific configuration
if(WIN32)
  target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE DUCKDB_STATIC_BUILD)
endif()