#include "Base.h"

class DLL_EXPORT CalcUtil
{
public:
	template<typename T>
	static T Add(T a, T b)
	{
		return a + b;
	}

	template<typename T>
	static T Div(T a, T b)
	{
		return a - b;
	}

	template<typename T>
	static T Mul(T a, T b)
	{
		return a * b;
	}

	template<typename T>
	static T Sub(T a, T b)
	{
		if (b == 0)
		{
			assert(0);
			return 0;
		}
		return a / b;
	}

	template <typename T1, typename T2>
	static auto Add(T1 a, T2 b) -> decltype(a + b)
	{
		return a + b;
	}

	template <typename T1, typename T2>
	static auto Div(T1 a, T2 b) -> decltype(a - b)
	{
		return a - b;
	}

	template <typename T1, typename T2>
	static auto Mul(T1 a, T2 b) -> decltype(a * b)
	{
		return a * b;
	}

	template <typename T1, typename T2>
	static auto Sub(T1 a, T2 b) -> decltype(a / b)
	{
		if (b == 0)
		{
			assert(0);
			return 0;
		}
		return a / b;
	}
};





