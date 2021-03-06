# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
	message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
	file(
		DOWNLOAD
		"https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
		"${CMAKE_CURRENT_BINARY_DIR}/conan.cmake"
		EXPECTED_HASH
			SHA256=396e16d0f5eabdc6a14afddbcfff62a54a7ee75c6da23f32f7a31bc85db23484
		TLS_VERIFY ON)
endif()

include(${CMAKE_CURRENT_BINARY_DIR}/conan.cmake)

# Set up some extra Conan dependencies based on our needs before loading Conan
set(CONAN_EXTRA_REQUIRES
    "")
set(CONAN_EXTRA_OPTIONS
    "")

conan_cmake_configure(
	REQUIRES ${CONAN_EXTRA_REQUIRES}
		 gtest/1.11.0
		 docopt.cpp/0.6.2
	OPTIONS ${CONAN_EXTRA_OPTIONS}
	GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)

conan_cmake_install(
	PATH_OR_REFERENCE .
	BUILD missing
	SETTINGS ${settings})

set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_BINARY_DIR}
    PARENT_SCOPE)
