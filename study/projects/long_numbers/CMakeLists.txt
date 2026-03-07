project(long_number)

set(LONG_NUMBER_LIB "long_number_lib")
add_library(${LONG_NUMBER_LIB} "")

add_subdirectory(src)
add_subdirectory(test)
