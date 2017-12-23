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
 * \file	MathUtility.h
 * \author	Cubimon
 * \date	2017-09-20
 * \brief	Implements some math functions
 */
#pragma once

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
			/**
			 * Implements some math functions
			 */
			class CMathUtility
			{
			public:
				/**
				 * simple recursive factorial function, because boost is unavailable and math does not provide it =(
				 */
				static unsigned long long fac(unsigned long long n);

			private:
				/**
				 * Disabled constructor
				 */
				CMathUtility(void);

				/**
				 * Default destructor
				 */
				virtual ~CMathUtility(void);
			};
		}
	}
}