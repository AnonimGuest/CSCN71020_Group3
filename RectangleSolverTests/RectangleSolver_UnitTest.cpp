#include "pch.h"
#include "CppUnitTest.h"

extern "C" int isRectangle(int points[2][4]);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleSolver_UnitTest
{
	TEST_CLASS(RectangleSolver_UnitTest)
	{
	public:
		
		//-------------RECTANGLE SOLVER TESTS--------------//
		TEST_METHOD(isRectangleTest_validInput_returnsTrue)
		{
			int points[2][4] = { (1,2), (3,4), (4,5), (6,7) };
			bool Expected = true;
			bool Result = isRectangle(points);
			Assert::AreEqual(Expected, Result);

		}

		TEST_METHOD(isRectangleTest_invalidInput_returnsFalse)
		{
			int points[2][4] = { (1,2), (3,4), (-7,5), (6,7) };
			bool Expected = false;
			bool Result = isRectangle(points);
			Assert::AreEqual(Expected, Result);
		}

	};
}
