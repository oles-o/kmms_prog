target_sources(multi_module_app
	PRIVATE
		sortings.cpp
		sortings.hpp
		io.cpp
		io.hpp
)

target_include_directories(multi_module_app PRIVATE
	"${PROJECT_SOURCE_DIR}/sortings"
)