#include "stdafx.h"
#include "shape.cpp"
#include "CppUnitTest.h"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ShapeTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(SqCircle)
		{
		    Circle C (2.8);
			float sq = 24.6176;
			Assert::AreEqual(sq, C.getSquare());
		}

		TEST_METHOD(SqSquare)
		{
			Square S(4.27);
			float sq = 18.2329;
			Assert::AreEqual(sq, S.getSquare());
		}

		TEST_METHOD(SqRectangle)
		{
			Rectangle R(3.25,2.4);
			float sq = 7.8;
			Assert::AreEqual(sq, R.getSquare());
		}

		TEST_METHOD(min)
		{
			Square S1(1);
			Rectangle S2(1, 3);
			Circle S3(1);
			Square S4(3);
			Rectangle S5(1, 1);
			ShapesProcessor Shapes;
			Shapes.Add(S1);
			Shapes.Add(S2);
			Shapes.Add(S3);
			Shapes.Add(S4);
			Shapes.Add(S5);			
			float S = S5.getSquare();
			Assert::AreEqual(float(1), S);
		}
		TEST_METHOD(max)
		{
			Square S1(2);
			Rectangle S2(1, 3);
			Circle S3(1);
			Square S4(3);
			Rectangle S5(1, 1);
			ShapesProcessor Shapes;
			Shapes.Add(S1);
			Shapes.Add(S2);
			Shapes.Add(S3);
			Shapes.Add(S4);
			Shapes.Add(S5);
			float S = S4.getSquare();
			Assert::AreEqual(float(9), S);
		}

		TEST_METHOD(getSquare)
		{
			Square S1(2);
			Rectangle S2(1, 3);
			Circle S3(1);
			Square S4(3);
			Rectangle S5(1, 1);
			ShapesProcessor Shapes;
			Shapes.Add(S1);
			Shapes.Add(S2);
			Shapes.Add(S3);
			Shapes.Add(S4);
			Shapes.Add(S5);
			vector <float> expected;
			expected.push_back(S1.getSquare());
			expected.push_back(S2.getSquare());
			expected.push_back(S3.getSquare());
			expected.push_back(S4.getSquare());
			expected.push_back(S5.getSquare());
			for (int i = 0; i < 5; i++)
			Assert::AreEqual(expected[i], Shapes.getSquare()[i]);
		}

		TEST_METHOD(same)
		{
			Square S1(2);
			Rectangle S2(2, 2);
			Circle S3(1);
			Square S4(3);
			Rectangle S5(1, 4);
			ShapesProcessor Shapes;
			Shapes.Add(S1);
			Shapes.Add(S2);
			Shapes.Add(S3);
			Shapes.Add(S4);
			Shapes.Add(S5);
			Assert::AreEqual(3, Shapes.sameSquare());
		}
		TEST_METHOD(difType)
		{
			Square S1(1);
			Rectangle S2(1, 3.14);
			Rectangle S3(3.14, 1);
			Circle S4(1);
			Circle S5(2);
			Square S6(1);
			ShapesProcessor Shapes;
			Shapes.Add(S1);
			Shapes.Add(S2);
			Shapes.Add(S3);
			Shapes.Add(S4);
			Shapes.Add(S5);
			Shapes.Add(S6);
			ShapesProcessor expected;
			expected.Add(S2);
			expected.Add(S4);
			for (int i = 0; i < 2; i++)
				Assert::IsTrue ((expected.getSquare()[i] == Shapes.sameSquareDifType().getSquare()[i]));
		}
	};
}