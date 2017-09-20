#include "MathUtility.h"

namespace net
{
namespace derpaul
{
namespace various
{

	unsigned long long CMathUtility::fac(unsigned long long n)
	{
		if (n == 0)
			return static_cast<unsigned long long>(1);
		else
			return n * fac(n - static_cast<unsigned long long>(1));
	}

	CMathUtility::CMathUtility()
	{
	}


	CMathUtility::~CMathUtility()
	{
	}
}
}
}