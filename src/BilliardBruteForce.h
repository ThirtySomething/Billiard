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
 * \file	BilliardBruteForce.h
 * \author	ThirtySomething
 * \date	2017-05-12
 * \brief	Brute force algorithm
 */
#pragma once

#include "Billiard.h"

 /**
  * Namespace of Billiard
  */
namespace net
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
			 * Brute force solver for billard puzzle
			 */
			class CBilliardBruteForce : public CBilliard
			{
			public:
				/**
				 * Default constructor
				 */
				CBilliardBruteForce(void);

				/**
				 * Default destructor
				 */
				virtual ~CBilliardBruteForce(void);

			protected:
				/**
				 * Number of dots per line for the progress information
				 */
				static const int DotsPerLine;

				/**
				 * Number of permutations per dot for the progress information
				 */
				static const unsigned long long PermutationsPerDot;

				/**
				 * Evaluation of the given permutation
				 * \param Balls Permutation to check
				 * \return true if all conditions matches (=> solution), otherwise false
				 */
				bool CheckPermutation(const ballset &Balls);

				/**
				 * Entry point for the brute force puzzle solver, the brute force algorithm starts here
				 */
				void DetermineSolution(void) override;

				/**
				 * To display some progress information
				 */
				void ShowProgressInformation(void);
			};
		}
	}
}
