#pragma once

#include <string>

#include "number.h"

namespace opencas
{
	class Rational : public Number
	{
	public:
		Rational() {}


		virtual std::string to_string()
		{
			return std::to_string(n) + "/" + std::to_string(d);
		}
	private:
		std::int32_t n;
		std::int32_t d;
	};
}


