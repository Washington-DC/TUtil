#include "stdafx.h"

class BaseEnvironment :public testing::Environment
{
public:
	virtual void SetUp()
	{
		std::cout << "_______________ Environment SetUp _______________" << std::endl;
	}
	virtual void TearDown()
	{
		std::cout << "______________ Environment TearDown _____________" << std::endl;
	}
};


class BaseTestSuite :public testing::Test
{
public:
	static void SetUpTestCase()
	{
		std::cout << "_______________ SetUpTestCase _______________" << std::endl;
	}

	static void TearDownTestCase()
	{
		std::cout << "______________ TearDownTestCase ______________" << std::endl;
	}

protected:
	virtual void SetUp()
	{
		std::cout << "_______________ SetUp _______________" << std::endl;
	}

	virtual void TearDown()
	{
		std::cout << "______________ TearDown ______________" << std::endl;
	}
};


class BaseTestCase :public testing::Test
{
protected:
	virtual void SetUp()
	{
		std::cout << "_______________ SetUp _______________" << std::endl;
	}

	virtual void TearDown()
	{
		std::cout << "______________ TearDown ______________" << std::endl;
	}
};


TEST_F(BaseTestSuite, test_add_03)
{
	EXPECT_EQ(CalcUtil::Add(1, 2), 3);
}

TEST_F(BaseTestCase, test_add_04)
{
	EXPECT_EQ(CalcUtil::Add(1, 2), 3);
}