//******************************************************************************
// Copyright 2017 ThirtySomething
//******************************************************************************
// This file is part of Billiard.
//
// Billiard is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// Billiard is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
// more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Billiard. If not, see <http://www.gnu.org/licenses/>.
//******************************************************************************

/**
 * \file	PermutationGenerator.cpp
 * \author	Cubimon
 * \date	2017-09-20
 * \brief	Generates permutation in a lexicographical order
 */

#include "PermutationGenerator.h"

#include <assert.h>
#include <numeric>
#include <utility>
#include <iostream>
#include <algorithm>

#include "MathUtility.h"

 /**
 * Namespace of Billiard
 */
namespace net
{
	/**
	* Namespace of Billiard
	*/
	namespace derpaul
	{
		/**
		* Namespace of tools
		*/
		namespace various
		{
			//******************************************************************************
			//******************************************************************************
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

			//******************************************************************************
			//******************************************************************************
			CPermutationGenerator::~CPermutationGenerator(void)
			{
			}

			//******************************************************************************
			//******************************************************************************
			bool CPermutationGenerator::Next(void)
			{
				if (m_idx == m_max_idx - 1)
				{
					return false;
				}
				m_idx++;
				std::next_permutation(m_permutation.begin(), m_permutation.end());
				return true;
			}

			//******************************************************************************
			//******************************************************************************
			std::vector<int> CPermutationGenerator::GetPermutation(void)
			{
				return m_permutation;
			}

			//******************************************************************************
			//******************************************************************************
			void CPermutationGenerator::Print(void)
			{
				for (auto it = m_permutation.begin(); it < m_permutation.end() - 1; it++)
				{
					std::cout << *it << ",";
				}
				std::cout << m_permutation.back();
			}
		}
	}
}