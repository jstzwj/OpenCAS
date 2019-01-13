
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cmath>



namespace opencas
{
	namespace multiprecision
	{
#define TWO_POW_32 4294967296
		
		inline std::uint32_t fullAdder32(std::uint32_t a, std::uint32_t b, std::uint32_t in_carry, std::uint32_t * out_carry)
		{
			std::uint64_t c = static_cast<std::uint64_t>(a) +
				static_cast<std::uint64_t>(b) +
				static_cast<std::uint64_t>(in_carry);
			*out_carry = static_cast<std::uint32_t>(c >> 32);
			return static_cast<std::uint32_t>(c & 0xFFFFFFFF);
		}

		inline std::uint32_t fullProducter32(std::uint32_t a, std::uint32_t b, std::uint32_t in_carry, std::uint32_t * out_carry)
		{
			std::uint64_t c = static_cast<std::uint64_t>(a) *
				static_cast<std::uint64_t>(b) +
				static_cast<std::uint64_t>(in_carry);
			*out_carry = static_cast<std::uint32_t>(c >> 32);
			return static_cast<std::uint32_t>(c & 0xFFFFFFFF);
		}

		class unsigned_integer
		{
		public:
			unsigned_integer()
			{
				value.push_back(0);
			}

			unsigned_integer(std::uint64_t v)
			{
				std::uint32_t low = static_cast<std::uint32_t>(v & 0xFFFFFFFF);
				std::uint32_t high = static_cast<std::uint32_t>((v & 0xFFFFFFFF00000000) >> 32);
				value.push_back(low);
				value.push_back(high);
			}

			void shift_logical_left(std::size_t n)
			{
				std::size_t shift_bits = n % 32;
				std::size_t shift_bytes = n / 32;
				
				for (int i = value.size() - shift_bytes; i >= 0; --i)
					value[i + shift_bytes] = value[i] << shift_bits;
			}

			void shift_logical_right(std::size_t n)
			{
				std::size_t shift_bits = n % 32;
				std::size_t shift_bytes = n / 32;

				for (int i = shift_bytes; i < value.size(); ++i)
					value[i - shift_bytes] = value[i] >> shift_bits;
			}

			void add(const unsigned_integer & other)
			{
				std::uint32_t in_carry = 0;
				std::size_t i;
				for (i = 0; i < value.size() && i<other.value.size(); ++i)
					value[i] = fullAdder32(value[i], other.value[i], in_carry, &in_carry);

				if (i >= value.size())
				{
					while (i < value.size())
					{
						value[i] = fullAdder32(value[i], other.value[i], in_carry, &in_carry);
						++i;
					}
				}

				if (i >= other.value.size())
				{
					while (i < other.value.size())
					{
						value[i] = fullAdder32(value[i], other.value[i], in_carry, &in_carry);
						++i;
					}
				}
				while (in_carry != 0)
					value[i] = fullAdder32(value[i], other.value[i], in_carry, &in_carry);
			}
			void subtract(const unsigned_integer & other);
			void product(const unsigned_integer & other)
			{
				std::uint32_t in_carry = 0;
				unsigned_integer result;

				

				
			}
			void divide(const unsigned_integer & other);

			std::string to_string()
			{
				std::string str;
				std::uint64_t num = 0;
				if (!value.empty())
					num = value[0];
				for (std::size_t i = 0; i < value.size(); ++i)
				{
					if (i != 0)
						num = num + value[i] * TWO_POW_32;
					while (num > 10)
					{
						str += std::to_string(num % 10);
						num /= 10;
					}
				}
				if (num > 0) str += std::to_string(num);

				std::reverse(str.begin(), str.end());
				return str;
			}
		private:
			std::vector<std::uint32_t> value;
		};

		class integer
		{
		public:
			integer()
				:is_negetive(false)
			{
				value.push_back(0);
			}

			integer(std::int64_t v)
			{
				is_negetive = v < 0;
				v = std::abs(v);
				std::uint32_t low = static_cast<std::uint32_t>(v & 0xFFFFFFFF);
				std::uint32_t high = static_cast<std::uint32_t>((v & 0xFFFFFFFF00000000) >> 32);
				value.push_back(low);
				value.push_back(high);
			}

			void add(const integer & other)
			{
			}
			void subtract(const integer & other);
			void product(const integer & other);
			void divide(const integer & other);
		private:
			std::vector<std::uint32_t> value;
			bool is_negetive;
		};
#undef TWO_POW_32
	}
}