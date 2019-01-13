#pragma once


#include <vector>

#include <opencas/opencas_type.h>
#include <opencas/number.h>
#include <opencas/rational.h>

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


