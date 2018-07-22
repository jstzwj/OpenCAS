#pragma once

#include <memory>
#include <cstdint>


namespace opencas
{
	template<class T>
	using unique_ptr = std::unique_ptr<T>;

	template<class T>
	using ptr = std::unique_ptr<T>;

	using integer_class = std::int32_t;
}