add_library(project_euler STATIC project_euler.cpp)

target_include_directories(
	project_euler
	INTERFACE "${CMAKE_CURRENT_LIST_DIR}/../"
	PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(
	project_euler
	PRIVATE project_options project_warnings)
