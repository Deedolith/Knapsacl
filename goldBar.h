#pragma once

#include <string>

class goldBar
{
private:
	std::string mIDMAT;
	std::string mCode;
	unsigned mLBMAFOZ;
	std::string mNOMCOND1;
public:
	goldBar() = delete;
	goldBar(std::string const&, std::string const&, float, std::string const&);
	goldBar(goldBar const&) = delete;
	goldBar(goldBar&&) = default;
	goldBar& operator=(goldBar const&) = delete;
	goldBar& operator=(goldBar&&) = default;
	std::string IDMAT() const;
	std::string Code() const;
	float LBMAFOZ() const;
	unsigned weight() const;
	std::string NOMCOND1() const;
};
