
#include "stdafx.h"


/************************************************************************/
/* So GoogleMock ²»Ö§³Ö std::wstring                                                                     */
/************************************************************************/
class User
{
public:
	bool Login(std::string username, std::string password)
	{
		return false;
	}

	bool WStringTest(OChar* name)
	{
		return false;
	}

	int Add(int a,int b)
	{
		return a+b;
	}

	bool SetAge(int nAge)
	{
		return false;
	}

	int GetAge()
	{
		return 0;
	}
};

class MockUser :public User
{
public:
	MOCK_METHOD2(Login, bool(std::string username, std::string password));
	MOCK_METHOD2(Add, int(int, int));
	MOCK_METHOD1(SetAge, int(int nAge));
	MOCK_METHOD1(WStringTest, bool(OChar*));
	MOCK_METHOD0(GetAge, int());
};

TEST(MockTest, test_GetAge_01)
{
	MockUser user;
	EXPECT_CALL(user, GetAge()).WillRepeatedly(testing::Return(12));
	EXPECT_EQ(user.GetAge(), 12);
}

TEST(MockTest, test_SetAge_01)
{
	MockUser user;
	EXPECT_CALL(user, SetAge(2)).WillRepeatedly(testing::Return(true));
	EXPECT_EQ(user.SetAge(2), true);
}

TEST(MockTest, test_Add_01)
{
	MockUser user;
	EXPECT_CALL(user, Add(2,2)).WillRepeatedly(testing::Return(333));
	EXPECT_EQ(user.Add(2,2), 333);
}

TEST(MockTest, test_Login_01)
{
	MockUser user;
	EXPECT_CALL(user, Login("1", "2")).WillRepeatedly(testing::Return(true));
	EXPECT_EQ(user.Login("1", "2"), true);
}

TEST(MockTest, test_WStringTest_01)
{
	MockUser user;
	EXPECT_CALL(user, WStringTest(_T("1"))).WillRepeatedly(testing::Return(true));
	EXPECT_EQ(user.WStringTest(_T("1")), true);
}


TEST(MockTest, test_Add_02)
{
	testing::internal::AnythingMatcher _any = {};
	MockUser user;
	EXPECT_CALL(user, Add(_any, _any)).WillRepeatedly(testing::Return(12));
	EXPECT_EQ(user.Add(2, 2), 12);
	EXPECT_EQ(user.Add(2, 2), 12);
	EXPECT_EQ(user.Add(2, 2), 12);
}

TEST(MockTest, test_Add_03)
{
	testing::internal::AnythingMatcher _any = {};
	MockUser user;
	EXPECT_CALL(user, Add(_any, _any)).WillOnce(testing::Return(12));
	EXPECT_EQ(user.Add(2, 2), 12);
	/*EXPECT_EQ(user.Add(2, 2), 0);
	EXPECT_EQ(user.Add(2, 2), 0);*/
}

