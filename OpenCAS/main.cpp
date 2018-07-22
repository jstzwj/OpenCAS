#include <iostream>
#include <string>

#include "multiprecision\integer.hpp"

int main()
{
	opencas::multiprecision::unsigned_integer i(0);
	std::cout << i.to_string();

	return 0;
}