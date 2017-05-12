#include "BilliardBruteForce.h"
#include <algorithm>
#include <iostream>
#include <cmath>

namespace org
{
	namespace derpaul
	{
		namespace various
		{
			//******************************************************************************
			//******************************************************************************
			CBilliardBruteForce::CBilliardBruteForce(void)
				: CBilliard()
			{
			}

			//******************************************************************************
			//******************************************************************************
			CBilliardBruteForce::~CBilliardBruteForce(void)
			{
			}

			//******************************************************************************
			//******************************************************************************
			void CBilliardBruteForce::SearchSolution(void)
			{
				// Should be volatile in case of parallel tasks
				volatile unsigned long long PermutationCount = 0;
				ballset Balls = InitBalls();

				do {
					// Check the rules
					if (true == CheckRulesFit(Balls))
					{
						// Display solution
						ShowBalls(Balls, true);
					}
					// We do not need to see the invalid permutations
					//else
					//{
					//	ShowBalls(Balls);
					//}
					PermutationCount++;
				} while (std::next_permutation(Balls.begin(), Balls.end()));
				std::cout << "Number of permutations: " << PermutationCount;
			}
		}
	}
}
