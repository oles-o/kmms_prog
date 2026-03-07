target_sources(multi_module_app_lib
	PRIVATE
		sortings.cpp
		io.cpp
	PUBLIC
		sortings.hpp
		io.hpp
)

target_include_directories(multi_module_app_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)
