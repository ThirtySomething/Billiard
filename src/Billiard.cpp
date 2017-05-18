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

/**
 * Namespace of Billiard
 */
namespace org
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
			const int CBilliard::BallMax = 15;
			const std::string CBilliard::Delimiter = "\t";

			//******************************************************************************
			//******************************************************************************
			CBilliard::CBilliard(const std::string &CalculationMethod)
				: m_SolverName(CalculationMethod)
				, m_PermutationCount(0)
			{
			}

			//******************************************************************************
			//******************************************************************************
			CBilliard::~CBilliard(void)
			{
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

			//******************************************************************************
			//******************************************************************************
			ballset CBilliard::InitBalls(void)
			{
				// Empty vector
				ballset Balls;
				// Add ball numbers
				for (int i = 1; i <= BallMax; i++)
				{
					Balls.push_back(i);
				}

				return Balls;
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

				std::cout << "[" << m_SolverName << "] finished, [" << m_PermutationCount << "] permutations, [" << Milliseconds.count() << "] milliseconds duration" << std::endl;
			}

			//******************************************************************************
			//******************************************************************************
			void CBilliard::ShowBalls(const ballset &Balls)
			{
				// Show all balls in the shape of a triangle
				std::cout << std::endl << std::endl;
				std::cout << Balls[10] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[11] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[12] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[13] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[14] << std::endl << std::endl;
				std::cout << CBilliard::Delimiter << Balls[6] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[7] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[8] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[9] << std::endl << std::endl;
				std::cout << CBilliard::Delimiter << CBilliard::Delimiter << Balls[3] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[4] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[5] << std::endl << std::endl;
				std::cout << CBilliard::Delimiter << CBilliard::Delimiter << CBilliard::Delimiter << Balls[1] << CBilliard::Delimiter << CBilliard::Delimiter << Balls[2] << std::endl << std::endl;
				std::cout << CBilliard::Delimiter << CBilliard::Delimiter << CBilliard::Delimiter << CBilliard::Delimiter << Balls[0] << std::endl << std::endl;
				std::cout << std::endl << std::endl;
			}
		}
	}
}
