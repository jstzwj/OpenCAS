#pragma once


#include <vector>

#include "opencas_type.h"
#include "number.h"
#include "rational.h"

namespace opencas
{
	class Mul : public Node
	{
	public:
		Mul() {}

	private:
		std::vector<std::pair<ptr<Node>, ptr<Node>>> dictionary;
		ptr<Number> coef;
	};
}


