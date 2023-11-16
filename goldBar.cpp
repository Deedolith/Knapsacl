#include "goldBar.h"

goldBar::goldBar(std::string const& IDMAT, std::string const& Code, float LBMAFOZ, std::string const& NOMCOND1):
	mIDMAT{ IDMAT },
	mCode{ Code },
	mLBMAFOZ{ static_cast<unsigned>(LBMAFOZ * 1000) },
	mNOMCOND1{ NOMCOND1 }
{
}

std::string goldBar::IDMAT() const
{
	return mIDMAT;
}

std::string goldBar::Code() const
{
	return mCode;
}

float goldBar::LBMAFOZ() const
{
	return static_cast<float>(mLBMAFOZ) / 1000.0f;
}

unsigned goldBar::weight() const
{
	return mLBMAFOZ;
}

std::string goldBar::NOMCOND1() const
{
	return mNOMCOND1;
}
