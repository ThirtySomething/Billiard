#include "billiard.h"
#include <algorithm>
#include <iostream>
#include <cmath>

//******************************************************************************
//******************************************************************************
const std::string CBilliard::Delimiter = "\t";

//******************************************************************************
//******************************************************************************
CBilliard::CBilliard(void)
{
	InitBalls();
}

//******************************************************************************
//******************************************************************************
CBilliard::~CBilliard(void)
{
}

//******************************************************************************
//******************************************************************************
void CBilliard::InitBalls(void)
{
	m_Balls.clear();
	for (int i = BallMax; i > 0; i--)
	{
		m_Balls.push_back(i);
	}
	std::sort(m_Balls.begin(), m_Balls.end());
}

//******************************************************************************
//******************************************************************************
void CBilliard::SearchSolution(void)
{
	volatile int PermutationCount = 0;

	do {
		if (true == CheckRulesFit())
		{
			ShowBalls(true);
		}
		else
		{
			ShowBalls();
		}
		PermutationCount++;
	} while (std::next_permutation(m_Balls.begin(), m_Balls.end()));
	std::cout << "Number of permutations: " << PermutationCount;
}

//******************************************************************************
//******************************************************************************
void CBilliard::ShowBalls(bool Verbose)
{
	if (true == Verbose)
	{
		std::cout << m_Balls[10] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[11] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[12] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[13] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[14] << std::endl << std::endl << std::endl;
		std::cout << CBilliard::Delimiter << m_Balls[6] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[7] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[8] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[9] << std::endl << std::endl;
		std::cout << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[3] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[4] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[5] << std::endl << std::endl;
		std::cout << CBilliard::Delimiter << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[1] << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[2] << std::endl << std::endl;
		std::cout << CBilliard::Delimiter << CBilliard::Delimiter << CBilliard::Delimiter << CBilliard::Delimiter << m_Balls[0] << std::endl << std::endl;
	}
	else
	{
		for (ballset::const_iterator CurrentBall = m_Balls.begin(); CurrentBall != m_Balls.end(); ++CurrentBall)
		{
			std::cout << '|' << *CurrentBall;
		}
		std::cout << '|' << std::endl;
	}
}

//******************************************************************************
//******************************************************************************
bool CBilliard::CheckRulesFit(void)
{
	bool Level1 = CheckTriple(m_Balls[0], m_Balls[1], m_Balls[2]);
	bool Level2 = CheckTriple(m_Balls[2], m_Balls[4], m_Balls[5])
		&& CheckTriple(m_Balls[3], m_Balls[5], m_Balls[6]);
	bool Level3 = CheckTriple(m_Balls[4], m_Balls[7], m_Balls[8])
		&& CheckTriple(m_Balls[5], m_Balls[8], m_Balls[9])
		&& CheckTriple(m_Balls[6], m_Balls[9], m_Balls[10]);
	bool Level4 = CheckTriple(m_Balls[7], m_Balls[11], m_Balls[12])
		&& CheckTriple(m_Balls[8], m_Balls[12], m_Balls[13])
		&& CheckTriple(m_Balls[9], m_Balls[13], m_Balls[14])
		&& CheckTriple(m_Balls[10], m_Balls[13], m_Balls[15]);

	return (Level1 && Level2 && Level3 && Level4);
}

//******************************************************************************
//******************************************************************************
bool CBilliard::CheckTriple(int BallResult, int BallLeft, int BallRight)
{
	return (BallResult == std::abs(BallLeft - BallRight));
}
