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
		 * Namespace of Billiard
		 */
		namespace various
		{
			//******************************************************************************
			//******************************************************************************
			const int CBilliardBruteForce::DotsPerLine = 50;
			const unsigned long long CBilliardBruteForce::PermutationsPerDot = 200000;

			//******************************************************************************
			//******************************************************************************
			CBilliardBruteForce::CBilliardBruteForce(void)
				: CBilliard(__FUNCTION__)
			{
			}

			//******************************************************************************
			//******************************************************************************
			CBilliardBruteForce::~CBilliardBruteForce(void)
			{
			}

			//******************************************************************************
			//******************************************************************************
			bool CBilliardBruteForce::CheckPermutation(const ballset &Balls)
			{
				// The ruleset for all 10 groups
				bool Level1 = CheckGroup(Balls[0], Balls[1], Balls[2]);
				bool Level2 = Level1
					&& CheckGroup(Balls[1], Balls[3], Balls[4])
					&& CheckGroup(Balls[2], Balls[4], Balls[5]);
				bool Level3 = Level2
					&& CheckGroup(Balls[3], Balls[6], Balls[7])
					&& CheckGroup(Balls[4], Balls[7], Balls[8])
					&& CheckGroup(Balls[5], Balls[8], Balls[9]);
				bool Level4 = Level3
					&& CheckGroup(Balls[6], Balls[10], Balls[11])
					&& CheckGroup(Balls[7], Balls[11], Balls[12])
					&& CheckGroup(Balls[8], Balls[12], Balls[13])
					&& CheckGroup(Balls[9], Balls[13], Balls[14]);

				// Returns true if its a solution, otherwise false
				return (Level1 && Level2 && Level3 && Level4);
			}

			//******************************************************************************
			//******************************************************************************
			void CBilliardBruteForce::DetermineSolution(void)
			{
				// Should be volatile in case of parallel tasks
				ballset Balls = InitBalls();
				do {
					// Check the rules
					if (true == CheckPermutation(Balls))
					{
						// Display solution
						ShowBalls(Balls);
					}
					m_PermutationCount++;
					ShowProgressInformation();
				} while (std::next_permutation(Balls.begin(), Balls.end()));
			}

			//******************************************************************************
			//******************************************************************************
			void CBilliardBruteForce::ShowProgressInformation(void)
			{
				static int linelength = 0;

				// Show a dot for each 1000000 permutations with at least
				// maximum 50 dots each line
				if (0 == (m_PermutationCount % CBilliardBruteForce::PermutationsPerDot))
				{
					if (CBilliardBruteForce::DotsPerLine <= linelength)
					{
						std::cout << std::endl;
						linelength = 0;
					}
					std::cout << ".";
					linelength++;
				}
			}
		}
	}
}
