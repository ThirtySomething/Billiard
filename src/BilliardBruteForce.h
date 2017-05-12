#pragma once

#include "Billiard.h"

namespace org
{
	namespace derpaul
	{
		namespace various
		{
			class CBilliardBruteForce : public CBilliard
			{
			public:
				CBilliardBruteForce(void);
				virtual ~CBilliardBruteForce(void);

				void SearchSolution(void) override;
			};
		}
	}
}
