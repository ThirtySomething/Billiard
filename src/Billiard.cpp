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
 * \file	Billiard.cpp
 * \author	ThirtySomething
 * \date	2017-05-12
 * \brief	Implementation of Billiard puzzle
 */
#include "billiard.h"
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
			const int CBilliard::BallMax = 15;
			const std::string CBilliard::Delimiter = "\t";

			//******************************************************************************
			//******************************************************************************
			CBilliard::CBilliard(void)
			{
				InitBalls();
			}

			//******************************************************************************
			//******************************************************************************
			CBilliard::~CBilliard(void)
			{
			}

			//******************************************************************************
			//******************************************************************************
			void CBilliard::InitBalls(void)
			{
				// Empty vector
				m_Balls.clear();
				// Add ball numbers
				for (int i = BallMax; i > 0; i--)
				{
					m_Balls.push_back(i);
				}
				// Sort in ascending order for the C++ permutation algorithm
				std::sort(m_Balls.begin(), m_Balls.end());
			}

			//******************************************************************************
			//******************************************************************************
			void CBilliard::SearchSolution(void)
			{
				// Should be volatile in case of parallel tasks
				volatile unsigned long long PermutationCount = 0;

				do {
					// Check the rules
					if (true == CheckRulesFit())
					{
						// Display solution
						ShowBalls(true);
					}
					// We do not need to see the invalid permutations
					// else
					// {
					// 	ShowBalls();
					// }
					PermutationCount++;
				} while (std::next_permutation(m_Balls.begin(), m_Balls.end()));
				std::cout << "Number of permutations: " << PermutationCount;
			}

			//******************************************************************************
			//******************************************************************************
			void CBilliard::ShowBalls(bool Verbose)
			{
				if (true == Verbose)
				{
					// Show all balls in the shape of a triangle
					std::cout << m_Balls[10] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[11] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[12] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[13] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[14] << std::endl << std::endl << std::endl;
					std::cout << CBilliard::Delimiter << m_Balls[6] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[7] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[8] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[9] << std::endl << std::endl;
					std::cout << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[3] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[4] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[5] << std::endl << std::endl;
					std::cout << CBilliard::Delimiter << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[1] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[2] << std::endl << std::endl;
					std::cout << CBilliard::Delimiter << CBilliard::Delimiter << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[0] << std::endl << std::endl;
				}
				else
				{
					// Show all balls in a sequence
					for (ballset::const_iterator CurrentBall = m_Balls.begin(); CurrentBall != m_Balls.end(); ++CurrentBall)
					{
						std::cout << '|' << *CurrentBall;
					}
					std::cout << '|' << std::endl;
				}
			}

			//******************************************************************************
			//******************************************************************************
			bool CBilliard::CheckRulesFit(void)
			{
				// The ruleset for all 10 groups
				bool Level1 = CheckTriple(m_Balls[0], m_Balls[1], m_Balls[2]);
				bool Level2 = CheckTriple(m_Balls[2], m_Balls[4], m_Balls[5])
					&& CheckTriple(m_Balls[3], m_Balls[5], m_Balls[6]);
				bool Level3 = CheckTriple(m_Balls[4], m_Balls[7], m_Balls[8])
					&& CheckTriple(m_Balls[5], m_Balls[8], m_Balls[9])
					&& CheckTriple(m_Balls[6], m_Balls[9], m_Balls[10]);
				bool Level4 = CheckTriple(m_Balls[7], m_Balls[11], m_Balls[12])
					&& CheckTriple(m_Balls[8], m_Balls[12], m_Balls[13])
					&& CheckTriple(m_Balls[9], m_Balls[13], m_Balls[14])
					&& CheckTriple(m_Balls[10], m_Balls[13], m_Balls[15]);

				// Returns true if its a solution, otherwise false
				return (Level1 && Level2 && Level3 && Level4);
			}

			//******************************************************************************
			//******************************************************************************
			bool CBilliard::CheckTriple(int BallResult, int BallLeft, int BallRight)
			{
				// The group check
				// BallLeft - BallRight
				//     BallResult
				return (BallResult == std::abs(BallLeft - BallRight));
			}
		}
	}
}
