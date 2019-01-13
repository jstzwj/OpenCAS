#pragma once

#include <string>
#include <vector>

#include "number.h"
#include <opencas/opencas_type.h>

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
		IntegerType num;
	};
}


