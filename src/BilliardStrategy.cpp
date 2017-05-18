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
 * \file	BilliardStrategy.cpp
 * \author	ThirtySomething
 * \date	2017-05-12
 * \brief	Strategy algorithm algorithm implementation
 */
#include "BilliardStrategy.h"
#include <algorithm>

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
			CBilliardStrategy::CBilliardStrategy(void)
				: CBilliard(__FUNCTION__)
			{
			}

			//******************************************************************************
			//******************************************************************************
			CBilliardStrategy::~CBilliardStrategy(void)
			{
			}

			//******************************************************************************
			//******************************************************************************
			void CBilliardStrategy::CheckPermutation(ballset &Solution, ballset &BallsAvailable)
			{
				for (ballset::iterator CurrentBall = BallsAvailable.begin(); CurrentBall != BallsAvailable.end(); ++CurrentBall)
				{
					int BallNumber = *CurrentBall;
					ballset BallsAvailableNext = BallsAvailable;
					BallsAvailableNext.erase(std::remove(BallsAvailableNext.begin(), BallsAvailableNext.end(), BallNumber), BallsAvailableNext.end());
					m_PermutationCount++;
					bool Abort = false;

					Solution.push_back(BallNumber);

					if (true == GetAbortFlag(Solution))
					{
						Solution.pop_back();
						continue;
					}

					CheckPermutation(Solution, BallsAvailableNext);
					Solution.pop_back();
				}
			}

			//******************************************************************************
			//******************************************************************************
			bool CBilliardStrategy::CheckPermutationSingle(const ballset &Solution, int BallBottom, int BallLeft, int BallRight)
			{
				bool Abort = false;

				if (false == CheckGroup(BallBottom, BallLeft, BallRight))
				{
					Abort = true;
				}

				return Abort;
			}

			//******************************************************************************
			//******************************************************************************
			void CBilliardStrategy::DetermineSolution(void)
			{
				ballset BallsAvailable = InitBalls();
				ballset Solution;

				CheckPermutation(Solution, BallsAvailable);
			}

			//******************************************************************************
			//******************************************************************************
			bool CBilliardStrategy::GetAbortFlag(const ballset &Solution)
			{
				bool Abort;

				switch (static_cast<int>(Solution.size()))
				{
				case 3:
					Abort = CheckPermutationSingle(Solution, Solution[0], Solution[1], Solution[2]);
					break;
				case 5:
					Abort = CheckPermutationSingle(Solution, Solution[1], Solution[3], Solution[4]);
					break;
				case 6:
					Abort = CheckPermutationSingle(Solution, Solution[2], Solution[4], Solution[5]);
					break;
				case 8:
					Abort = CheckPermutationSingle(Solution, Solution[3], Solution[6], Solution[7]);
					break;
				case 9:
					Abort = CheckPermutationSingle(Solution, Solution[4], Solution[7], Solution[8]);
					break;
				case 10:
					Abort = CheckPermutationSingle(Solution, Solution[5], Solution[8], Solution[9]);
					break;
				case 12:
					Abort = CheckPermutationSingle(Solution, Solution[6], Solution[10], Solution[11]);
					break;
				case 13:
					Abort = CheckPermutationSingle(Solution, Solution[7], Solution[11], Solution[12]);
					break;
				case 14:
					Abort = CheckPermutationSingle(Solution, Solution[8], Solution[12], Solution[13]);
					break;
				case 15:
					if (true == CheckGroup(Solution[9], Solution[13], Solution[14]))
					{
						ShowBalls(Solution);
						Abort = true;
					}
					break;
				default:
					Abort = false;
					break;
				}

				return Abort;
			}
		}
	}
}
