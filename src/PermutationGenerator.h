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
 * \file	PermutationGenerator.h
 * \author	Cubimon
 * \date	2017-09-20
 * \brief	Generates permutation in a lexicographical order
 */

#pragma once

#include <vector>

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
			/**
			 * Generates permutation in a lexicographical order
			 */
			class CPermutationGenerator
			{
			public:
				/**
				 * Constructor, used to initalize the permutation generator
				 *
				 * \param length number of elements to permutate
				 * \param min_idx 0 <= min_idx < fac(length), indicates the start permutation
				 * \param max_idx 0 < max_idx <= fac(length), indicates the end permutation
				 */
				CPermutationGenerator(int length, unsigned long long min_idx, unsigned long long max_idx);

				/**
				 * Default destructor
				 */
				virtual ~CPermutationGenerator(void);

				/**
				 * Create next permuation
				 *
				 * \return true if we haven't reached max_id
				 */
				bool Next(void);

				/**
				 * Get current permutation
				 *
				 * \return vector of ints => current permutation
				 */
				std::vector<int> GetPermutation(void);

				/**
				 * Print current permutation
				 */
				void Print(void);

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