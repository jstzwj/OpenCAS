#pragma once

#include <complex>

#include "opencas_type.h"
#include "number.h"
#include "rational.h"

namespace opencas
{
	class Complex : public Number
	{
	public:
		Complex() {}

	private:
		unique_ptr<Rational> real;
		unique_ptr<Rational> imaginary;
	};
}


