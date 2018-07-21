#pragma once

#include <string>

namespace opencas
{
	class Node
	{
	public:
		Node();
		virtual ~Node();

		virtual std::string to_string() = 0;
	};
}


