#pragma once

#include <string>
#include <vector>

#include "number.h"

namespace opencas
{
	class Integer : public Number
	{
	public:
		Integer() {}


		virtual std::string to_string()
		{
			
		}
	private:
		std::vector<std::int32_t> num;
	};
}


