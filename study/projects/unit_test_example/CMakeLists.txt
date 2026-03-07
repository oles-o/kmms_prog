project(unit_test_example)

set(NAME_ADD_LIB multi_module_app_lib)

add_library(${NAME_ADD_LIB} "")

add_subdirectory(src)
add_subdirectory(test)