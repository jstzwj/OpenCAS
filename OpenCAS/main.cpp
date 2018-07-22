#include <iostream>
#include <string>

#include "multiprecision\integer.hpp"

int main()
{
	opencas::multiprecision::unsigned_integer i(11000000000);
	opencas::multiprecision::unsigned_integer j(1100234324000);
	i.add(j);
	std::cout << i.to_string();
	system("pause");
	return 0;
}