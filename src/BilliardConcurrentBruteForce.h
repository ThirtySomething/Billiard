#pragma once

#include <thread>
#include <mutex>

#include "Billiard.h"

namespace net
{
namespace derpaul
{
namespace various
{
	/**
	 * Brute force solver for billard puzzle working concurrently to improve performance
	 */
	class CBilliardConcurrentBruteForce : public CBilliard
	{
	public:
		/**
		 * uses std::thread::hardware_concurrency() to get a good number of threads
		 */
		CBilliardConcurrentBruteForce();

		CBilliardConcurrentBruteForce(int n_threads);

		virtual ~CBilliardConcurrentBruteForce();

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
		void DetermineSolution() override;

		/**
		 * To display some progress information
		 */
		void ShowProgressInformation(unsigned long long n_permutations);

		/**
		 * Number of threads
		 */
		int m_n_threads;

		/**
		 * Stdout mutex
		 */
		std::mutex m_mutex;
	};
}
}
}
