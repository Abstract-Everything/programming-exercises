cmake_minimum_required(VERSION 3.15)

project(
	cpp_programming_exercises
	VERSION 0.0.0.1
	DESCRIPTION "A set of code samples that server as exercises to improve my skills"
	LANGUAGES CXX)

include(cmake/Constants.cmake)
include(cmake/PreventInSourceBuilds.cmake)
include(cmake/StandardProjectSettings.cmake)
include(cmake/LinkTimeOptimization.cmake)
include(cmake/TimeTrace.cmake)
include(cmake/CompilerWarnings.cmake)
include(cmake/Cache.cmake)
include(cmake/Sanitizers.cmake)
include(cmake/StaticAnalyzers.cmake)
include(cmake/Doxygen.cmake)
include(cmake/PrecompileHeaders.cmake)
include(cmake/Tests.cmake)
include(cmake/UnityBuild.cmake)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(
	project_options
	INTERFACE cxx_std_17)
enable_time_trace(project_options)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)
set_project_warnings(project_warnings)

ENABLE_IPO()
enable_pch(project_options)
option(CPP_TMPL_BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)

enable_doxygen()
enable_ccache()
enable_sanitizers(project_options)
enable_static_analyzers()

enable_tests()

add_subdirectory(dependencies)
add_subdirectory(project_euler)
