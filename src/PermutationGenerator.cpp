#include "PermutationGenerator.h"

#include <assert.h>
#include <numeric>
#include <utility>
#include <iostream>
#include <algorithm>

#include "MathUtility.h"

namespace net
{
namespace derpaul
{
namespace various
{

	CPermutationGenerator::CPermutationGenerator(int length, unsigned long long min_idx, unsigned long long max_idx)
		: m_min_idx(min_idx), m_max_idx(max_idx), m_idx(m_min_idx)
	{

		assert(0 <= m_min_idx && m_min_idx < CMathUtility::fac(length));
		assert(0 < m_max_idx && m_max_idx <= CMathUtility::fac(length));
		assert(m_min_idx < m_max_idx);

		// m_permutation
		m_permutation = std::vector<int>(length, 0);
		std::vector<int> to_insert_nums(length);
		std::iota(to_insert_nums.begin(), to_insert_nums.end(), 1);
		int insertion_idx = 0;
		unsigned long long idx = min_idx;
		unsigned long long block_size = CMathUtility::fac(length);
		while (insertion_idx < length)
		{
			block_size /= length - insertion_idx;
			int i = 0;
			while (idx >= block_size)
			{
				idx -= block_size;
				i++;
			}
			m_permutation[insertion_idx] = to_insert_nums[i];
			to_insert_nums.erase(to_insert_nums.begin() + i);
			insertion_idx++;
		}
	}


	CPermutationGenerator::~CPermutationGenerator()
	{
	}

	bool CPermutationGenerator::Next()
	{
		if (m_idx == m_max_idx - 1)
			return false;
		m_idx++;
		std::next_permutation(m_permutation.begin(), m_permutation.end());
	}

	std::vector<int> CPermutationGenerator::GetPermutation()
	{
		return m_permutation;
	}

	void CPermutationGenerator::Print()
	{
		for (auto it = m_permutation.begin(); it < m_permutation.end() - 1; it++)
			std::cout << *it << ",";
		std::cout << m_permutation.back();
	}
}
}
}