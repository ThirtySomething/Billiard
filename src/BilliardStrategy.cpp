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
				bool SearchSolution = true;
				ballset Solution;
				ballset BallsAvailable = InitBalls();
				int BallCurrent;

				while (true == SearchSolution)
				{
					CBilliardStrategy::NextAction Action = PerformCheck(Solution);

					ShowBalls(Solution);

					switch (Action)
					{
					case BALL_FETCH:
						BallCurrent = BallsAvailable.front();
						Solution.push_back(BallCurrent);
						BallsAvailable.pop_front();
						break;
					case SOLUTION:
						ShowBalls(Solution, true);
						SearchSolution = false;
						break;
					case STEP_BACK:
						BallCurrent = Solution.back();
						BallsAvailable.push_back(BallCurrent);
						Solution.pop_back();
						break;
                    case UNDEFINED:
                    default:
                        break;
					}
				}
			}

			//******************************************************************************
			//******************************************************************************
			CBilliardStrategy::NextAction CBilliardStrategy::PerformCheck(const ballset &Solution)
			{
				CBilliardStrategy::NextAction Action = UNDEFINED;
				int Size = static_cast<int>(Solution.size());

				switch (Size)
				{
				case 0:
				case 1:
				case 2:
				case 4:
				case 7:
				case 11:
					Action = BALL_FETCH;
					break;
				case 3:
					Action = DetermineAction(Solution[0], Solution[1], Solution[2]);
					break;
				case 5:
					Action = DetermineAction(Solution[1], Solution[3], Solution[4]);
					break;
				case 6:
					Action = DetermineAction(Solution[2], Solution[4], Solution[5]);
					break;
				case 8:
					Action = DetermineAction(Solution[3], Solution[6], Solution[7]);
					break;
				case 9:
					Action = DetermineAction(Solution[4], Solution[7], Solution[8]);
					break;
				case 10:
					Action = DetermineAction(Solution[5], Solution[8], Solution[9]);
					break;
				case 12:
					Action = DetermineAction(Solution[6], Solution[10], Solution[11]);
					break;
				case 13:
					Action = DetermineAction(Solution[7], Solution[11], Solution[12]);
					break;
				case 14:
					Action = DetermineAction(Solution[8], Solution[12], Solution[13]);
					break;
				case 15:
					Action = DetermineAction(Solution[9], Solution[13], Solution[14]);
					if (BALL_FETCH == Action)
					{
						Action = SOLUTION;
					}
					break;
				}

				return Action;
			}

			//******************************************************************************
			//******************************************************************************
			CBilliardStrategy::NextAction CBilliardStrategy::DetermineAction(int BallBottom, int BallLeft, int BallRight)
			{
				CBilliardStrategy::NextAction Action = STEP_BACK;

				if (true == CheckGroup(BallBottom, BallLeft, BallRight))
				{
					Action = BALL_FETCH;
				}

				return Action;
			}
		}
	}
}
