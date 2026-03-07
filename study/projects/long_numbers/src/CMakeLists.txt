target_sources(${LONG_NUMBER_LIB} 
	PRIVATE
		long_number.cpp
)

target_include_directories(${LONG_NUMBER_LIB} PUBLIC
	"${CURRENT_SOURCE_DIR}"
)
