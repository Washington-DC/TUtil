#include "stdafx.h"
#include "BaseEnvironment.h"
#include <vector>

class BaseAddTestSuite :public testing::TestWithParam<std::tuple<int, int, int>>
{
public:
	virtual void SetUp()
	{
		auto sParam = GetParam();
		a = std::get<0>(sParam);
		b = std::get<1>(sParam);
		sum = std::get<2>(sParam);
	}
	int a;
	int b;
	int sum;
};


INSTANTIATE_TEST_CASE_P(,		\
	BaseAddTestSuite,			\
	testing::Values(			\
	std::make_tuple(1, 2, 3),	\
	std::make_tuple(1, 3, 4),	\
	std::make_tuple(2, 3, 5)	\
	)											
	);

TEST_P(BaseAddTestSuite, test_add)
{
	EXPECT_EQ(CalcUtil::Add(a, b), sum);
}



