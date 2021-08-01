#include "problem_9_special_pythagorean_triplet.hpp"

#include <cmath>
#include <cstdlib>

namespace project_euler
{
	std::pair<bool, std::size_t> Special_Pythagorean_Triplet::is_pythagorean_triplet(std::size_t a, std::size_t b)
	{
		if (a == 0 || b == 0)
		{
			return { false, 0U };
		}

		double c_squared = static_cast<double>(a * a) + static_cast<double>(b * b);
		double c = std::sqrt(c_squared);

		double integer = 0.0;
		double fraction = 0.0;
		fraction = std::modf(c, &integer);

		return { fraction == 0.0, static_cast<std::size_t>(c) };
	}

	std::size_t Special_Pythagorean_Triplet::Naive(std::size_t sum)
	{
		for (std::size_t a = 0; a < sum; ++a)
		{
			for (std::size_t b = a + 1; b < sum; ++b)
			{
				auto [is_triplet, c] = is_pythagorean_triplet(a, b);
				if (is_triplet && a + b + c == sum)
				{
					return a * b * c;
				}
			}
		}

		return 0;
	}

	std::size_t Special_Pythagorean_Triplet::Optimized(const std::size_t sum)
	{
		double d_sum = static_cast<double>(sum);
		const double upper_bound = d_sum / 2.0;
		for (double a = 1; a < upper_bound; ++a)
		{
			// double fraction = a / (d_sum - a);
			// double b = d_sum / 2.0 * (1.0 - fraction);
			
			double numerator = d_sum * (d_sum - 2.0 * a);
			double denominator = 2.0 * (d_sum - a);
			double b = numerator / denominator;

			double integer = 0.0;
			double fraction = 0.0;
			fraction = std::modf(b, &integer);
			if (fraction != 0.0)
			{
				continue;
			}

			return a * b * std::sqrt(a * a + b * b);
		}
		return 0;
	}
}
