#include "pch.h"
#include "CppUnitTest.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerUnitTest
{
	TEST_CLASS(PolygonCheckerUnitTest)
	{
	public:

//-------------TRIANGLE SOLVER TESTS--------------//

		TEST_METHOD(TestMethod1)
		{


		}


//-------------RECTANGLE SOLVER TESTS--------------//
		TEST_METHOD(isRectangleTest_validInput_returnsTrue)
		{
			int points[2][4] = {(1,2), (3,4), (4,5), (6,7)};
			bool Expected = true;
			bool Result = isRectangle(points);
			Assert::AreEqual(Expected, Result);

		}

	};
}
