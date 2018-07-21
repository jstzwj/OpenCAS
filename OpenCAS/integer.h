#pragma once

#include <string>

#include "number.h"

namespace opencas
{
	class Integer : public Number
	{
	public:
		Integer() {}


		virtual std::string to_string()
		{
			return std::to_string(num);
		}
	private:
		std::int32_t num;
	};
}


