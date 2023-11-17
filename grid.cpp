#include <utility>

#include "grid.h"

grid::grid(size_t width, size_t height):
	mWidth{ width },
	mHeight{ height }
{
}

unsigned grid::operator[](coordinates const& key) const
{
	auto found = std::map<coordinates, unsigned>::find(key);
	if (found != std::map<coordinates, unsigned>::end())
		return found->second;
	return 0u;
}

auto grid::insert(coordinates const& key, unsigned value)
{
	return std::map<coordinates, unsigned>::insert(std::make_pair(key, value));
}

void grid::set(coordinates const& key, unsigned value)
{
	if (value)
	{
		auto inserted = insert(key, value);
		if (!inserted.second)
			inserted.first->second = value;
	}
}

size_t grid::width() const
{
	return mWidth;
}

size_t grid::height() const
{
	return mHeight;
}
