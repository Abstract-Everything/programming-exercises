#!/bin/bash

hpp_file_contents="/**
 * @file
 *
 * @section DESCRIPTION
 * Solution to Problem REPLACE_PROBLEM_NUMBER
 *
 */

#ifndef PROJECT_EULER_PROBLEM_REPLACE_PROBLEM_NUMBER_REPLACE_PROBLEM_NAME_SNAKECASE_HPP
#define PROJECT_EULER_PROBLEM_REPLACE_PROBLEM_NUMBER_REPLACE_PROBLEM_NAME_SNAKECASE_HPP

namespace project_euler
{
	class REPLACE_PROBLEM_NAME_CAPITALIZED_SNAKECASE
	{
	public:

		static constexpr const char* name = \"REPLACE_PROBLEM_NAME_DESCRIPTION\";

		/**
		 * @brief
		 */
		static void Naive();
	};
}

#endif
"

cpp_file_contents="#include \"REPLACE_PROBLEM_FILE_NAME.hpp\"

namespace project_euler
{
	void REPLACE_PROBLEM_NAME_CAPITALIZED_SNAKECASE::Naive()
	{
	}
}
"

test_file_contents="#include <project_euler/REPLACE_PROBLEM_FILE_NAME.hpp>

#include <gtest/gtest.h>
#define TEST_NL(test_suite_name, test_name) TEST(test_suite_name, test_name) // NOLINT

using namespace project_euler;

TEST_NL(REPLACE_PROBLEM_FILE_NAME, test_name)
{
}
"

function get_root_path
{
	git rev-parse --show-toplevel
}

function get_lib_folder
{
	echo "$(get_root_path)/project_euler/lib"
}

function get_test_folder
{
	echo "$(get_root_path)/project_euler/test"
}

function get_next_problem_number
{
	current_largest=$(ls $(get_lib_folder) | grep "problem" | grep -v "${problem_name}" | cut -d '_' -f 2 | sort -nr | head -n 1)
	echo "$((current_largest + 1))"
}

function get_problem_file_name
{
	echo "problem_$(get_next_problem_number)_${problem_name}"
}

function get_test_file_name
{
	echo "${problem_name}"
}

function replace_code_contents
{
	file_name=$(get_problem_file_name)
	problem_name_snakecase=$(sed -E 's/([a-z])/\U\1/g' <<< $problem_name)
	problem_name_capitalized_snakecase=$(sed -E 's/((^|_)[a-z])/\U\1/g' <<< $problem_name)
	problem_name_description=$(sed -E 's/_/ /g' <<< $problem_name)

	contents="${1}"
	contents="${contents//REPLACE_PROBLEM_NUMBER/$(get_next_problem_number)}"
	contents="${contents//REPLACE_PROBLEM_NAME_SNAKECASE/$problem_name_snakecase}"
	contents="${contents//REPLACE_PROBLEM_NAME_CAPITALIZED_SNAKECASE/$problem_name_capitalized_snakecase}"
	contents="${contents//REPLACE_PROBLEM_FILE_NAME/$file_name}"
	contents="${contents//REPLACE_PROBLEM_NAME_DESCRIPTION/$problem_name_description}"
	echo "${contents}"
}

function replace_cmake_contents
{
	cmake_path=$1
	filename=$2
	perl -0777 -i -ne "s/(add_(library|executable)\([^)]+)/\$1\n\t${filename}.cpp/; print" $cmake_path
}

function create_lib_files
{
	file_name=$(get_problem_file_name)

	hpp_path="$(get_lib_folder)/include/project_euler/${file_name}.hpp"
	hpp_content=$(replace_code_contents "${hpp_file_contents}")
	echo "${hpp_content}" > $hpp_path

	cpp_path="$(get_lib_folder)/${file_name}.cpp"
	cpp_content=$(replace_code_contents "${cpp_file_contents}")
	echo "${cpp_content}" > $cpp_path

	replace_cmake_contents "$(get_lib_folder)/CMakeLists.txt" $(get_problem_file_name)
}

function create_test_file
{
	file_name="$(get_test_file_name)"
	test_path="$(get_test_folder)/${file_name}.cpp"
	test_content=$(replace_code_contents "${test_file_contents}")
	echo "${test_content}" > $test_path

	replace_cmake_contents "$(get_test_folder)/CMakeLists.txt" $(get_test_file_name)
}

problem_name=${1}
if [[ ! "${problem_name}" =~ ^[_a-z]+ ]]; then
	echo "Expected a lower_snake_case problem name"
	exit 1
fi

create_lib_files
create_test_file
