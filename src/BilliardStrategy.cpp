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

namespace org
{
	namespace derpaul
	{
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
			void CBilliardStrategy::DetermineSolution(void)
			{
				ballset BallsAvailable = InitBalls();
				ballset Solution;

				CheckRecurse(Solution, BallsAvailable);
			}

			//******************************************************************************
			//******************************************************************************
			bool CBilliardStrategy::CheckResult(const ballset &Solution, int BallBottom, int BallLeft, int BallRight)
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
			void CBilliardStrategy::CheckRecurse(ballset &Solution, ballset &BallsAvailable)
			{
				for (ballset::iterator CurrentBall = BallsAvailable.begin(); CurrentBall != BallsAvailable.end(); ++CurrentBall)
				{
					int BallNumber = *CurrentBall;
					ballset BallsAvailableNext = BallsAvailable;
					BallsAvailableNext.erase(std::remove(BallsAvailableNext.begin(), BallsAvailableNext.end(), BallNumber), BallsAvailableNext.end());
					m_PermutationCount++;
					bool Abort = false;

					Solution.push_back(BallNumber);

					switch (static_cast<int>(Solution.size()))
					{
					case 3:
						Abort = CheckResult(Solution, Solution[0], Solution[1], Solution[2]);
						break;
					case 5:
						Abort = CheckResult(Solution, Solution[1], Solution[3], Solution[4]);
						break;
					case 6:
						Abort = CheckResult(Solution, Solution[2], Solution[4], Solution[5]);
						break;
					case 8:
						Abort = CheckResult(Solution, Solution[3], Solution[6], Solution[7]);
						break;
					case 9:
						Abort = CheckResult(Solution, Solution[4], Solution[7], Solution[8]);
						break;
					case 10:
						Abort = CheckResult(Solution, Solution[5], Solution[8], Solution[9]);
						break;
					case 12:
						Abort = CheckResult(Solution, Solution[6], Solution[10], Solution[11]);
						break;
					case 13:
						Abort = CheckResult(Solution, Solution[7], Solution[11], Solution[12]);
						break;
					case 14:
						Abort = CheckResult(Solution, Solution[8], Solution[12], Solution[13]);
						break;
					case 15:
						if (true == CheckGroup(Solution[9], Solution[13], Solution[14]))
						{
							ShowBalls(Solution);
							Abort = true;
						}
						break;
					}

					if (true == Abort)
					{
						Solution.pop_back();
						continue;
					}

					CheckRecurse(Solution, BallsAvailableNext);
					Solution.pop_back();
				}
			}
		}
	}
}
