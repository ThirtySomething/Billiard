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
 * \file	BilliardBruteForce.cpp
 * \author	ThirtySomething
 * \date	2017-05-12
 * \brief	Brute force algorithm implementation
 */
#include "BilliardBruteForce.h"
#include <algorithm>
#include <iostream>
#include <cmath>

namespace org
{
	namespace derpaul
	{
		namespace various
		{
			//******************************************************************************
			//******************************************************************************
			CBilliardBruteForce::CBilliardBruteForce(void)
				: CBilliard()
			{
			}

			//******************************************************************************
			//******************************************************************************
			CBilliardBruteForce::~CBilliardBruteForce(void)
			{
			}

			//******************************************************************************
			//******************************************************************************
			void CBilliardBruteForce::DetermineSolution(void)
			{
				// Should be volatile in case of parallel tasks
				ballset Balls = InitBalls();
				int linelength = 0;
				do {
					// Check the rules
					if (true == CheckRulesFit(Balls))
					{
						// Display solution
						ShowBalls(Balls, true);
					}

					// If not miscalculated, there will be 1 307 674 368 000 permutations
					m_PermutationCount++;

					// Show a dot for each 1000000 permutations with at least
					// maximum 50 dots each line
					if (0 == (m_PermutationCount % 100000))
					{
						std::cout << ".";
						if (50 < linelength)
						{
							std::cout << std::endl;
							linelength = 0;
						}
						else
						{
							linelength++;
						}
					}
				} while (std::next_permutation(Balls.begin(), Balls.end()));
			}
		}
	}
}
