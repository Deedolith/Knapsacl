#pragma once

// #include <memory_resource>
#include <map>

#include "coordinates.h"

class grid :
	private std::map<coordinates, unsigned>
{
private:
	using container = std::map<coordinates, unsigned>;
	size_t mWidth;
	size_t mHeight;
public:
	grid(size_t, size_t);
	unsigned operator[](coordinates const&) const;
	auto insert(coordinates const&, unsigned);
	void set(coordinates const&, unsigned);
	size_t width() const;
	size_t height() const;
	using container::size;
	using container::empty;
	using container::clear;
	using container::begin;
	using container::end;
	using container::cbegin;
	using container::cend;
	using container::rbegin;
	using container::rend;
	using container::crbegin;
	using container::crend;
	using container::operator=;
};

