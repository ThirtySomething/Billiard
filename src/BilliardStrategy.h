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
 * \file	BilliardStrategy.h
 * \author	ThirtySomething
 * \date	2017-05-12
 * \brief	Strategy algorithm
 */
#pragma once

#include "Billiard.h"

namespace org
{
	namespace derpaul
	{
		namespace various
		{
			class CBilliardStrategy : public CBilliard
			{
			public:
				CBilliardStrategy(void);
				virtual ~CBilliardStrategy(void);

			protected:
				enum NextAction {
					BALL_FETCH,
					SOLUTION,
					STEP_BACK,
					UNDEFINED
				};
				void DetermineSolution(void) override;
				NextAction PerformCheck(const ballset &Solution);
				NextAction DetermineAction(int BallBottom, int BallLeft, int BallRight);
			};
		}
	}
}
