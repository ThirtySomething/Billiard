#pragma once

#include <vector>
#include <string>

class CBilliard
{
public:
	CBilliard(void);
	virtual ~CBilliard(void);

	void SearchSolution(void);
	void ShowBalls(bool Verbose = false);
	bool CheckRulesFit(void);

protected:
	static const std::string Delimiter;

	typedef std::vector<int> ballset;
	static const int BallMax = 15;
	ballset m_Balls;

	void InitBalls(void);
	bool CheckTriple(int BallResult, int BallLeft, int BallRight);
};
