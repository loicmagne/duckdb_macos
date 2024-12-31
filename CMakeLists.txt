cmake_minimum_required(VERSION 3.16)
project(duckdb_test)

# Build DuckDB first
add_subdirectory(deps/duckdb EXCLUDE_FROM_ALL)

# Create our test executable
add_executable(test_program main.cpp)
target_link_libraries(test_program PRIVATE duckdb_static)
target_include_directories(test_program PRIVATE deps/duckdb/src/include)
