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
		if (b==0)
		{
			assert(0);
			return 0;
		}
		return a / b;
	}
};


