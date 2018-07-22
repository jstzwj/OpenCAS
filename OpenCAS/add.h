#pragma once


#include <vector>

#include "opencas_type.h"
#include "number.h"
#include "rational.h"

namespace opencas
{
	class Add : public Node
	{
	public:
		Add() {}

	private:
		std::vector<std::pair<ptr<Node>, ptr<Number>>> dictionary;
		ptr<Number> coef;
	};
}


