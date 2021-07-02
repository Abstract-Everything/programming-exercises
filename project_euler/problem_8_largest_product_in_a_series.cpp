#include "problem_8_largest_product_in_a_series.hpp"

#include <vector>
#include <sstream>
#include <numeric>

namespace project_euler
{
	std::size_t largest_product_in_a_series(const std::string& series, std::size_t digit_count)
	{
		std::size_t largest = 0;
		std::size_t running_total = 1;
		std::vector<std::size_t> numbers;
		for (auto element : series)
		{
			std::size_t number = element - '0';
			if (number == 0)
			{
				running_total = 1;
				numbers.clear();
			}
			else
			{
				running_total *= number;
				numbers.push_back(number);
			}

			if (numbers.size() > digit_count)
			{
				running_total /= numbers.front();
				numbers.erase(numbers.begin());
			}

			if (numbers.size() == digit_count)
			{
				largest = std::max(running_total, largest);
			}
		}
		return largest;
	}
}
