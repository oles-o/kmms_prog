set(SOURCES
	test_app.cpp
)

add_executable(test_app ${SOURCES})
target_link_libraries(test_app
	gtest_main
	multi_module_app_lib
)

add_test(test_app test_app)