
#include <vector>
#include <cstdint>
#include <cmath>



namespace opencas
{
	namespace multiprecision
	{
#define TWO_POW_32 4294967296
		class unsigned_integer
		{
		public:
			unsigned_integer()
			{
				value.push_back(0);
			}

			unsigned_integer(std::uint64_t v)
			{
				std::uint32_t low = v % TWO_POW_32;
				std::uint32_t high = v / TWO_POW_32;
				value.push_back(low);
				value.push_back(high);
			}

			void add(const unsigned_integer & other)
			{
				std::uint32_t tmp = 0;
				std::size_t i;
				for ( i = 0; i < value.size() && i<other.value.size(); ++i)
				{
					if (TWO_POW_32 - (value[i] + tmp) <= other.value[i])
					{
						value[i] = other.value[i] - (TWO_POW_32 - (value[i] + tmp));
						tmp = 1;
					}
					else
					{
						value[i] = other.value[i] + value[i];
						tmp = 0;
					}
				}

				if (i >= value.size())
				{
					while (i < value.size())
					{
						if (TWO_POW_32 - (value[i] + tmp) <= other.value[i])
						{
							value[i] = other.value[i] - (TWO_POW_32 - (value[i] + tmp));
							tmp = 1;
						}
						else
						{
							value[i] = other.value[i] + value[i];
							tmp = 0;
						}
						++i;
					}
				}

				if (i > other.value.size())
				{
					while (i < other.value.size())
					{
						if (TWO_POW_32 - (value[i] + tmp) <= other.value[i])
						{
							value.push_back(other.value[i] - (TWO_POW_32 - (value[i] + tmp)));
							tmp = 1;
						}
						else
						{
							value.push_back(other.value[i] + value[i]);
							tmp = 0;
						}
						++i;
					}
					++i;
				}
			}
			void subtract(const unsigned_integer & other);
			void product(const unsigned_integer & other);
			void divide(const unsigned_integer & other);

			std::string to_string()
			{
				std::string str;
				for (std::size_t i = value.size() - 1; i >= 0; --i)
				{
					str += std::to_string(value[i]);
				}
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
				std::uint32_t low = v % TWO_POW_32;
				std::uint32_t high = v / TWO_POW_32;
				value.push_back(low);
				value.push_back(high);
			}

			void add(const integer & other)
			{
				if (!this->is_negetive && other.is_negetive)
					return this->subtract(other);

				if (this->is_negetive && !other.is_negetive)
					return other.subtract(*this);

				integer result;
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