#pragma once

#include "Billiard.h"

namespace org
{
	namespace derpaul
	{
		namespace various
		{
			class CBilliardClever : public CBilliard
			{
			public:
				CBilliardClever(void);
				virtual ~CBilliardClever(void);

				void SearchSolution(void) override;
			};
		}
	}
}
