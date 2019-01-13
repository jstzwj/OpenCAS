#pragma once

#include <memory>
#include <cstdint>
#include <opencas/multiprecision/integer.hpp>


namespace opencas
{
	template<class T>
	using unique_ptr = std::unique_ptr<T>;

	template<class T>
	using ptr = std::unique_ptr<T>;

	using IntegerType = multiprecision::Integer;
}