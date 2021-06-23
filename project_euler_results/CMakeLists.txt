add_executable(
	project_euler_results
	${CMAKE_CURRENT_LIST_DIR}/answers.cpp)

target_link_libraries(
	project_euler_results
	PRIVATE project_options
		project_warnings
		project_euler)
