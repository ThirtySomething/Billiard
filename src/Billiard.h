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
			/**
			 * Convenience typedef for internal usage
			 */
			typedef std::deque<int> ballset;

			/**
			 * Common base class for all solver classes
			 */
			class CBilliard
			{
			public:
				/**
				 * Default constructor
				 * \param SolverName Name of class for output
				 */
				explicit CBilliard(const std::string &SolverName);

				/**
				 * Default destructor
				 */
				virtual ~CBilliard(void);

				/**
				 * Common entry point for all puzzle solvers
				 */
				void SearchSolution(void);

				/**
				 * To print a solution
				 * \param Balls The ballset containing the solution
				 */
				static void ShowBalls(const ballset &Balls);

			protected:
				/**
				 * The maximum number of balls
				 */
				static const int BallMax;

				/**
				 * Delimiter between two balls in output
				 */
				static const std::string Delimiter;

				/**
				 * The name of the puzzle solver
				 */
				std::string m_SolverName;

				/**
				 * Permutation counter
				 */
				volatile unsigned long long m_PermutationCount;

				/**
				 * Check of a group
				 * \param BallBottom The lower ball
				 * \param BallLeft The ball above the lower ball on the left side
				 * \param BallRight The ball above the lower ball on the right side
				 * \return true on successful ball match, otherwise false
				 */
				bool CheckGroup(int BallBottom, int BallLeft, int BallRight);

				/**
				 * Pure virtual method, requires implementation for each solver
				 */
				virtual void DetermineSolution(void) = 0;

				/**
				 * Convenience method, fills a ballset with all balls
				 * \return Complete ballset
				 */
				static ballset InitBalls(void);
			};
		}
	}
}
