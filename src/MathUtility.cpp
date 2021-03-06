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
 * \file	MathUtility.cpp
 * \author	Cubimon
 * \date	2017-09-20
 * \brief	Implements some math functions
 */

#include "MathUtility.h"

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
		* Namespace of tools
		*/
		namespace various
		{
			//******************************************************************************
			//******************************************************************************
			unsigned long long CMathUtility::fac(unsigned long long n)
			{
				if (n == 0)
				{
					return static_cast<unsigned long long>(1);
				}
				else
				{
					return n * fac(n - static_cast<unsigned long long>(1));
				}
			}

			//******************************************************************************
			//******************************************************************************
			CMathUtility::CMathUtility()
			{
			}

			//******************************************************************************
			//******************************************************************************
			CMathUtility::~CMathUtility()
			{
			}
		}
	}
}