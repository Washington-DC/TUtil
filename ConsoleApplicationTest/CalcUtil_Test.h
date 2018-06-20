#include "stdafx.h"

TEST(CalcUtil_Test, test_add_01)
{
	EXPECT_EQ(3, CalcUtil::Add(1, 2));
}

TEST(CalcUtil_Test, test_add_02)
{
	EXPECT_EQ(3.2, CalcUtil::Add(1, 2.2));
}

TEST(CalcUtil_Test, test_div_01)
{
	EXPECT_EQ(1, CalcUtil::Div(3, 2));
}

TEST(CalcUtil_Test, test_div_02)
{
	EXPECT_DOUBLE_EQ(1.5, CalcUtil::Div(3, 1.5));
}

TEST(CalcUtil_Test, test_mul_01)
{
	EXPECT_DOUBLE_EQ(6, CalcUtil::Mul(3, 2));
}

TEST(CalcUtil_Test, test_mul_02)
{
	EXPECT_DOUBLE_EQ(1.5, CalcUtil::Mul(3, 0.5));
}

TEST(CalcUtil_Test, test_sub_01)
{
	EXPECT_DOUBLE_EQ(3, CalcUtil::Sub(3, 1));
}

TEST(CalcUtil_Test, test_sub_02)
{
	EXPECT_DOUBLE_EQ(2, CalcUtil::Sub(3, 1.5));
}

TEST(CalcUtil_Test, test_sub_03)
{
	EXPECT_ANY_THROW(CalcUtil::Sub(3, 0));
	EXPECT_THROW(CalcUtil::Sub(3.2, 0),int);
}

