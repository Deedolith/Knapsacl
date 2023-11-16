#pragma once

#include <functional>

struct coordinates
{
	unsigned long long x;
	unsigned long long y;
	coordinates(unsigned long long, unsigned long long);
};

template<>
struct std::less<coordinates>
{
	bool operator()(coordinates const& lhs, coordinates const& rhs) const
	{
		if (lhs.x < rhs.x)
			return true;
		if (lhs.x > rhs.x)
			return false;
		if (lhs.y < rhs.y)
			return true;
		return false;
	}
};
