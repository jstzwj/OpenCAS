#pragma once

#include "opencas_type.h"
#include "number.h"
#include "rational.h"

namespace opencas
{
	class Infinity : public Number
	{
	public:
		Infinity() {}

	private:
		unique_ptr<Number> direction;
	};
}


