# CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(test_project VERSION 1.0.0)

set(CMAKE_COMPILE_WARNING_AS_ERROR OFF)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/deps/duckdb.cmake)
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/common/bootstrap.cmake" NO_POLICY_SCOPE)

include(compilerconfig)
include(defaults)
# include(helpers)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE DuckDB::duckdb)

if(WIN32)
  target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE DUCKDB_STATIC_BUILD)
endif()