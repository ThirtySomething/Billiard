#pragma once

#include <vector>

namespace net
{
namespace derpaul
{
namespace various
{
	/**
	 * generates permutation in a lexicographical order
	 */
	class CPermutationGenerator
	{

	public:
		/**
		 * \param length number of elements to permutate
		 * \param min_idx 0 <= min_idx < fac(length), indicates the start permutation
		 * \param max_idx 0 < max_idx <= fac(length), indicates the end permutation
		 */
		CPermutationGenerator(int length, unsigned long long min_idx, unsigned long long max_idx);
		~CPermutationGenerator();

		/**
		 * true if we haven't reached max_idx
		 */
		bool Next();

		std::vector<int> GetPermutation();

		void Print();

	private:

		/**
		 * assert(0 <= min_idx < fac(length))
		 * assert(min_idx < max_idx)
		 */
		unsigned long long m_min_idx;

		/**
		 * assert(0 < max_idx <= fac(length))
		 * assert(min_idx < max_idx)
		 */
		unsigned long long m_max_idx;

		/**
		 * current state between min and max
		 * min <= idx < max
		 */
		unsigned long long m_idx;

		/**
		 * state of the algorithm
		 * m_permutation == a in [1]
		 */
		std::vector<int> m_permutation;
	};

}
}
}