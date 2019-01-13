#include <iostream>
#include <string>

#include <opencas/multiprecision/integer.hpp>

int main()
{
	opencas::multiprecision::Integer i(11);
	opencas::multiprecision::Integer j(2400000000000);

	std::cout << i+j << std::endl;
	return 0;
}