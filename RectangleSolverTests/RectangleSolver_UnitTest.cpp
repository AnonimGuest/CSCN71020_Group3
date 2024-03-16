#include "pch.h"
#include <stdbool.h>
#include "CppUnitTest.h"

extern "C" bool isRectangle(int points[4][2]);
extern "C" int calculateSideLength(int point1[2], int point2[2]);
extern "C" int calculatePerimeter(int line1, int line2, int line3, int line4);
extern "C" int calculateArea(int line1, int line2, int line3, int line4);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleSolver_UnitTest
{
	TEST_CLASS(RectangleSolver_UnitTest)
	{
	public:
		//-------------INPUT VALIDATION TESTS --------------//

    TEST_METHOD(gatherAndCheckPointsTest_ValidInput_ReturnsTrue)
        {
        int points[4][2] = { {1, 1}, {2, 2}, {3, 3}, {4, 4} }; // Valid input
        bool Expected = true;
        bool Result = gatherAndCheckPoints(points);
        Assert::AreEqual(Expected, Result);
        }

    TEST_METHOD(gatherAndCheckPointsTest_DuplicatePoints_ReturnsFalse)
        {
        int points[4][2] = { {1, 1}, {2, 2}, {1, 1}, {4, 4} }; // Duplicate points
        bool Expected = false;
        bool Result = gatherAndCheckPoints(points);
        Assert::AreEqual(Expected, Result);
        }

    TEST_METHOD(gatherAndCheckPointsTest_DuplicatePoints_ReturnsFalse)
    {
        int points[4][2] = { {1, 1}, {2, 2}, {h, 1}, {4, 4} }; // letter
        bool Expected = false;
        bool Result = gatherAndCheckPoints(points);
        Assert::AreEqual(Expected, Result);
    }
		
		//-------------RECTANGLE SOLVER TESTS--------------//

		//-------------isRectangle() tests----------------//
		TEST_METHOD(isRectangleTest_integerInputFormsRectangle_returnsTrue)
		{
			int points[4][2] = { {1,1 }, {1, 3}, {5, 1}, {5, 3}
		};
			bool Expected = true;
			bool Result = isRectangle(points);
			Assert::AreEqual(Expected, Result);
		}
		TEST_METHOD(isRectangleTest_decimalInputFormsRectangle_returnsTrue)
		{
			int points[4][2] = { {0.5, 1.5}, {0.5, 3.5}, {5.5, 1.5}, {5.5, 3.5}};
			bool Expected = true;
			bool Result = isRectangle(points);
			Assert::AreEqual(Expected, Result);
		}
		TEST_METHOD(isRectangleTest_pointsFormSquare_returnsFalse) //square does not count as rectangle in this program
		{
			int points[4][2] = { {1,1 }, { 1,2}, { 2,2}, { 2,1 }};
			bool Expected = false;
			bool Result = isRectangle(points);
			Assert::AreEqual(Expected, Result);
		}

		TEST_METHOD(isRectangleTest_duplicatePointsGiven_returnsFalse)
		{
			int points[4][2] = { {1,1 }, { 1,1 }, { 2,2 }, { 2,2 } };
			bool Expected = false;
			bool Result = isRectangle(points);
			Assert::AreEqual(Expected, Result);
		}
		TEST_METHOD(isRectangleTest_notARectangle_returnsFalse) 
		{
			int points[4][2] = { {1,21 }, { 34,4 }, { 7,5 }, { 6,7 }};
			bool Expected = false;
			bool Result = isRectangle(points);
			Assert::AreEqual(Expected, Result);
		}

		
		//---------calculateSideLength() tests-----------//
		TEST_METHOD(calculateSideLength_validInput_returnsCorrectResult)
		{
			int point1[2] = { 1,2 };
			int point2[2] = { 7,2 };
			int Expected = 6;
			int Result = calculateSideLength(point1, point2);
			Assert::AreEqual(Expected, Result);
		}

		//---------calculatePerimeter() tests-----------//
		TEST_METHOD(calculatePerimeter_validInput_returnsCorrectResult)
		{
			int line1 = 2;
			int line2 = 3;
			int line3 = 2;
			int line4 = 3;
			int Expected = 10;
			int Result = calculatePerimeter(line1,line2,line3,line4);
			Assert::AreEqual(Expected, Result);
		}

		//---------calculateArea() tests-----------//
		TEST_METHOD(calculateArea_validInput_returnsCorrectResult)
		{
			int line1 = 2;
			int line2 = 3;
			int line3 = 2;
			int line4 = 3;
			int Expected = 6;
			int Result = calculateArea(line1, line2, line3, line4);
			Assert::AreEqual(Expected, Result);
		}
	};
}
