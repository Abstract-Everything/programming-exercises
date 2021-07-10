add_executable(
	project_euler_answers
	${CMAKE_CURRENT_LIST_DIR}/answers.cpp)

target_link_libraries(
	project_euler_answers
	PRIVATE project_options
		project_warnings
		project_euler_lib)
