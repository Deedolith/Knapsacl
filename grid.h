#pragma once

#include <map>

#include "coordinates.h"

class grid :
	private std::map<coordinates, unsigned>
{
private:
	size_t mWidth;
	size_t mHeight;
public:
	grid(size_t, size_t);
	unsigned operator[](coordinates const&) const;
	auto insert(coordinates const&, unsigned);
	void set(coordinates const&, unsigned);
	size_t width() const;
	size_t height() const;
	using std::map<coordinates, unsigned>::size;
	using std::map<coordinates, unsigned>::empty;
	using std::map<coordinates, unsigned>::clear;
	using std::map<coordinates, unsigned>::begin;
	using std::map<coordinates, unsigned>::end;
	using std::map<coordinates, unsigned>::cbegin;
	using std::map<coordinates, unsigned>::cend;
	using std::map<coordinates, unsigned>::rbegin;
	using std::map<coordinates, unsigned>::rend;
	using std::map<coordinates, unsigned>::crbegin;
	using std::map<coordinates, unsigned>::crend;
	using std::map<coordinates, unsigned>::operator=;
};

