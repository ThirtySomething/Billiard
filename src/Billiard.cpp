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
#include <chrono>

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
			CBilliard::CBilliard(std::string CalculationMethod)
				: m_PermutationCount(0)
				, m_CalculationMethod(CalculationMethod)
			{
			}

			//******************************************************************************
			//******************************************************************************
			CBilliard::~CBilliard(void)
			{
			}

			//******************************************************************************
			//******************************************************************************
			unsigned long long CBilliard::GetLimit(unsigned long long Base)
			{
				return ((0 == Base) || (1 == Base)) ? 1 : GetLimit(Base - 1) * Base;
			}

			//******************************************************************************
			//******************************************************************************
			void CBilliard::SearchSolution(void)
			{
				auto TimeStart = std::chrono::high_resolution_clock::now();

				DetermineSolution();

				auto TimeEnd = std::chrono::high_resolution_clock::now();
				auto Duration = TimeEnd - TimeStart;
				auto Milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(Duration);

				std::cout << "[" << m_CalculationMethod << "] finished, [" << m_PermutationCount << "] permutations, [" << Milliseconds.count() << "] milliseconds duration" << std::endl;
			}

			//******************************************************************************
			//******************************************************************************
			ballset CBilliard::InitBalls(void)
			{
				// Empty vector
				ballset Balls;
				// Add ball numbers
				for (int i = BallMax; i > 0; i--)
				{
					Balls.push_back(i);
				}
				// Sort in ascending order for the C++ permutation algorithm
				std::sort(Balls.begin(), Balls.end());

				return Balls;
			}

			//******************************************************************************
			//******************************************************************************
			void CBilliard::ShowBalls(const ballset &Balls, bool Verbose)
			{
				if (true == Verbose)
				{
					// Show all balls in the shape of a triangle
					std::cout << std::endl << std::endl;
					std::cout << Balls[10] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[11] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[12] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[13] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[14] << std::endl << std::endl << std::endl;
					std::cout << CBilliard::Delimiter << Balls[6] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[7] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[8] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[9] << std::endl << std::endl;
					std::cout << CBilliard::Delimiter << CBilliard::Delimiter << Balls[3] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[4] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[5] << std::endl << std::endl;
					std::cout << CBilliard::Delimiter << CBilliard::Delimiter << CBilliard::Delimiter << Balls[1] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[2] << std::endl << std::endl;
					std::cout << CBilliard::Delimiter << CBilliard::Delimiter << CBilliard::Delimiter << CBilliard::Delimiter << Balls[0] << std::endl << std::endl;
					std::cout << std::endl << std::endl;
				}
				else
				{
					// Show all balls in a sequence
					for (ballset::const_iterator CurrentBall = Balls.begin(); CurrentBall != Balls.end(); ++CurrentBall)
					{
						std::cout << '|' << *CurrentBall;
					}
					std::cout << '|' << std::endl;
				}
			}

			//******************************************************************************
			//******************************************************************************
			bool CBilliard::CheckRulesFit(const ballset &Balls)
			{
				// The ruleset for all 10 groups
				bool Level1 = CheckGroup(Balls[0], Balls[1], Balls[2]);
				bool Level2 = Level1
					&& CheckGroup(Balls[2], Balls[4], Balls[5])
					&& CheckGroup(Balls[3], Balls[5], Balls[6]);
				bool Level3 = Level2
					&& CheckGroup(Balls[4], Balls[7], Balls[8])
					&& CheckGroup(Balls[5], Balls[8], Balls[9])
					&& CheckGroup(Balls[6], Balls[9], Balls[10]);
				bool Level4 = Level3
					&& CheckGroup(Balls[7], Balls[11], Balls[12])
					&& CheckGroup(Balls[8], Balls[12], Balls[13])
					&& CheckGroup(Balls[9], Balls[13], Balls[14])
					&& CheckGroup(Balls[10], Balls[13], Balls[15]);

				// Returns true if its a solution, otherwise false
				return (Level1 && Level2 && Level3 && Level4);
			}

			//******************************************************************************
			//******************************************************************************
			bool CBilliard::CheckGroup(int BallBottom, int BallLeft, int BallRight)
			{
				// The group check
				// |BallLeft - BallRight|
				//       BallBottom
				return (BallBottom == std::abs(BallLeft - BallRight));
			}
		}
	}
}
