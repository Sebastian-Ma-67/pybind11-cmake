cmake_minimum_required(VERSION 3.4...3.18)
project(cmake_example)

find_package(PCL 1.3 REQUIRED)
add_subdirectory(pybind11)


include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

file (GLOB MY_SRC src/*.cpp)

pybind11_add_module(cmake_example "${MY_SRC}")

target_link_libraries(cmake_example PRIVATE ${PCL_LIBRARIES})


# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(cmake_example
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
