#include "stdafx.h"

TEST(CalcTest, test_add_01)
{
	EXPECT_EQ(3, CalcUtil::Add(1, 2));
}

TEST(CalcTest, test_add_02)
{
	EXPECT_EQ(3.2, CalcUtil::Add(1, 2.2));
}