#pragma once

#include "number.h"

namespace opencas
{
	class Real : public Number
	{
	public:
		Real() {}
		virtual std::string to_string()
		{
			return std::to_string(num);
		}
	private:
		float num;
	};
}


