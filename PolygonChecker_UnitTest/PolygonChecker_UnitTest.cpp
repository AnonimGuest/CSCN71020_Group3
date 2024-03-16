#include "pch.h"
#include "CppUnitTest.h"
#include <stdbool.h>

extern "C" char* analyzeTriangle(int side1, int side2, int side3);

extern "C" int triangleEqual(int side1, int side2, int side3);

extern "C" int triangleScalene(int side1, int side2, int side3);

extern "C" int triangleIsos(int side1, int side2, int side3);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerUnitTest
{
	TEST_CLASS(PolygonCheckerUnitTest)
	{
	public:

//-------------TRIANGLE SOLVER TESTS--------------//

		TEST_METHOD(No_Triangle_True)
		{
			int side1 = 0;
			int side2 = 12;
			int side3 = 15;

			bool expected = false;
			bool result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Negative_Triangle)
		{
			int side1 = -3;
			int side2 = 10;
			int side3 = 12;

			bool expected = false;
			bool result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Equal_Triangle)
		{
			int side1 = 12;
			int side2 = 12;
			int side3 = 12;

			bool expected = true;
			bool result = triangleEqual(side1, side2, side3);
			Assert:: AreEqual(expected, result);
		}

		TEST_METHOD(Isos_Traingle_Case1)
		{
			int side1 = 12;
			int side2 = 12;
			int side3 = 14;

			bool expected = true;
			bool result = triangleIsos(side1, side2, side3);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Isos_Traingle_Case2)
		{
			int side1 = 10;
			int side2 = 12;
			int side3 = 12;

			bool expected = true;
			bool result = triangleIsos(side1, side2, side3);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Isos_Traingle_Case3)
		{
			int side1 = 12;
			int side2 = 10;
			int side3 = 12;

			bool expected = true;
			bool result = triangleIsos(side1, side2, side3);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Scalene_Triangle)
		{
			int side1 = 12;
			int side2 = 14;
			int side3 = 16;

			bool expected = true;
			bool result = triangleScalene(side1, side2, side3);
			Assert::AreEqual(expected, result);
		}
	};
}
