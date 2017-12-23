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
 * \file	main.cpp
 * \author	ThirtySomething
 * \date	2017-05-12
 * \brief	Start of Billiard puzzle
 */
#include <iostream>

#include "BilliardConcurrentBruteForce.h"
#include "BilliardBruteForce.h"
#include "BilliardStrategy.h"

 /**
  * Start of puzzle solver(s)
  * \param argc Number of command line arguments
  * \param argv Array of passed command line arguments as strings
  * \return Signal normal termination to OS
  */
int main(int argc, char* argv[])
{
	net::derpaul::various::CBilliardStrategy TableStragegy;
	net::derpaul::various::CBilliardConcurrentBruteForce TableConcurrentBruteForce;
	net::derpaul::various::CBilliardBruteForce TableBruteForce;

	TableStragegy.SearchSolution();
	TableConcurrentBruteForce.SearchSolution();
	TableBruteForce.SearchSolution();

	return 0;
}