cmake_minimum_required(VERSION 3.2...3.27.5)

project(study)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(travel_menu)
add_subdirectory(multi_module_app)
add_subdirectory(unit_test_example)
add_subdirectory(long_numbers)

set(CMAKE_SUPPRESS_REGENERATION true)