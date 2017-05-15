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
 * \file	Billiard.h
 * \author	ThirtySomething
 * \date	2017-05-12
 * \brief	Header of Billiard puzzle
 */
#pragma once

#include <deque>
#include <string>

namespace org
{
	namespace derpaul
	{
		namespace various
		{
			typedef std::deque<int> ballset;

			class CBilliard
			{
			public:
				CBilliard(void);
				virtual ~CBilliard(void);

				void SearchSolution(void);
				static void ShowBalls(const ballset &Balls, bool Verbose = false);

			protected:
				static const int BallMax;
				static const std::string Delimiter;

				volatile unsigned long long m_PermutationCount;
				virtual void DetermineSolution(void) = 0;
				static ballset InitBalls(void);
				bool GroupCheck(int BallBottom, int BallLeft, int BallRight);
				bool CheckRulesFit(const ballset &Balls);
			};
		}
	}
}
