#include "BilliardConcurrentBruteForce.h"

#include <iostream>
#include <vector>

#include "PermutationGenerator.h"
#include "MathUtility.h"

namespace net
{
namespace derpaul
{
namespace various
{
	const int CBilliardConcurrentBruteForce::DotsPerLine = 50;
	const unsigned long long CBilliardConcurrentBruteForce::PermutationsPerDot = 200000;


	CBilliardConcurrentBruteForce::CBilliardConcurrentBruteForce()
		: CBilliardConcurrentBruteForce(std::thread::hardware_concurrency())
	{
	}

	CBilliardConcurrentBruteForce::CBilliardConcurrentBruteForce(int n_threads)
		: CBilliard(__FUNCTION__), m_n_threads(n_threads)
	{
	}

	CBilliardConcurrentBruteForce::~CBilliardConcurrentBruteForce()
	{
	}

	bool CBilliardConcurrentBruteForce::CheckPermutation(const ballset &Balls)
	{
		// The ruleset for all 10 groups
		bool Level1 = CheckGroup(Balls[0], Balls[1], Balls[2]);
		bool Level2 = Level1
			&& CheckGroup(Balls[1], Balls[3], Balls[4])
			&& CheckGroup(Balls[2], Balls[4], Balls[5]);
		bool Level3 = Level2
			&& CheckGroup(Balls[3], Balls[6], Balls[7])
			&& CheckGroup(Balls[4], Balls[7], Balls[8])
			&& CheckGroup(Balls[5], Balls[8], Balls[9]);
		bool Level4 = Level3
			&& CheckGroup(Balls[6], Balls[10], Balls[11])
			&& CheckGroup(Balls[7], Balls[11], Balls[12])
			&& CheckGroup(Balls[8], Balls[12], Balls[13])
			&& CheckGroup(Balls[9], Balls[13], Balls[14]);

		// Returns true if its a solution, otherwise false
		return (Level1 && Level2 && Level3 && Level4);
	}

	void CBilliardConcurrentBruteForce::DetermineSolution()
	{
		// split BallMax into equidistant number ranges/prepare data per thread
		std::vector<std::thread> threads(m_n_threads);
		std::vector<CPermutationGenerator*> generators(m_n_threads);
		std::vector<unsigned long long> permutations_per_thread(m_n_threads);
		unsigned long long n_permutations = CMathUtility::fac(BallMax);
		// no boost::irange =(
		for (unsigned long long i = 0; i < m_n_threads; i++)
		{
			// many math operations are not commutative, so be careful
			generators[i] = new CPermutationGenerator(BallMax, 
				(n_permutations * i) / m_n_threads, 
				(n_permutations * (i + 1)) / m_n_threads);
			permutations_per_thread[i] = 0;
		}

		// check a permutation range per thread
		for (int i = 0; i < m_n_threads; i++)
		{
			threads[i] = std::thread([this](CPermutationGenerator* generator, unsigned long long& counter)
			{
				do
				{
					ballset balls = generator->GetPermutation();
					if (CheckPermutation(balls) == true)
					{
						std::lock_guard<std::mutex> lock(this->m_mutex);
						ShowBalls(balls);
					}
					counter++;
					ShowProgressInformation(counter);
				} 
				while (generator->Next());
			}, generators[i], std::ref(permutations_per_thread[i]));
		}

		for (int i = 0; i < m_n_threads; i++)
		{
			// wait for threads to finish
			threads[i].join();

			// release PermutationGenerator
			delete generators[i];

			// sum permutations
			m_PermutationCount += permutations_per_thread[i];
		}
	}

	void CBilliardConcurrentBruteForce::ShowProgressInformation(unsigned long long n_permutations)
	{
		static int linelength = 0;

		// Show a dot for each 1000000 permutations with at least
		// maximum 50 dots each line
		if (0 == (n_permutations % CBilliardConcurrentBruteForce::PermutationsPerDot))
		{
			std::lock_guard<std::mutex> lock(this->m_mutex);
			if (CBilliardConcurrentBruteForce::DotsPerLine <= linelength)
			{
				std::cout << std::endl;
				linelength = 0;
			}
			std::cout << ".";
			linelength++;
		}
	}
}
}
}
