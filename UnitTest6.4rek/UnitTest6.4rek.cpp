#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.4rek/lab6.4rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64rek
{
	TEST_CLASS(UnitTest64rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 5;
			double a[n] = { 1.0, 5.3, -5, -1.5, 0 };
			int lastNegativeIndex = -1;
			int negIndex = FindLastNegativeIndex(a, n, 0, lastNegativeIndex);
			Assert::AreEqual(3, negIndex);
		}
	};
}
