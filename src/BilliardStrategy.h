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
			 * Strategy solver for billard puzzle
			 */
			class CBilliardStrategy : public CBilliard
			{
			public:
				/**
				 * Default constructor
				 */
				CBilliardStrategy(void);

				/**
				 * Default destructor
				 */
				virtual ~CBilliardStrategy(void);

			protected:
				/**
				 * Evaluation of the given permutation
				 * \param Solution Permutation to check
				 * \param BallsAvailable Ballset of unused balls for recursive calls
				 */
				void CheckPermutation(ballset &Solution, ballset &BallsAvailable);

				/**
				 * Check of a group, determination of an abort flag
				 * \param Solution Ballset of current solution
				 * \param BallBottom The lower ball
				 * \param BallLeft The ball above the lower ball on the left side
				 * \param BallRight The ball above the lower ball on the right side
				 * \return true for abort, false for further recursion
				 */
				bool CheckPermutationSingle(const ballset &Solution, int BallBottom, int BallLeft, int BallRight);

				/**
				 * Entry point for the strategy puzzle solver, the algorithm starts here
				 */
				void DetermineSolution(void) override;

				/**
				 * Evaluate the given ballset and returns bool to decide to continue recursion or to abort
				 * \param Solution Ballset of current solution
				 * \return true for abort, false for further recursion
				 */
				bool GetAbortFlag(const ballset &Solution);
			};
		}
	}
}
