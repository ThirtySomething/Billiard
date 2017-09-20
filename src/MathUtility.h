#pragma once
namespace net
{
namespace derpaul
{
namespace various
{
	class CMathUtility
	{
	public:
		/**
		 * simple recursive factorial function, because boost is unavailable and math does not provide it =(
		 */
		static unsigned long long fac(unsigned long long n);

	private:
		CMathUtility();
		~CMathUtility();
	};
}
}
}