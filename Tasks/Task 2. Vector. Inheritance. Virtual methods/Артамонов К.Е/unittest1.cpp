#include "stdafx.h"
#include "CppUnitTest.h"
#include "ConsoleApplication10.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(SquareS)
		{
			Square s(3.334);
			double square = 11.12;
			Assert::AreEqual(square, s.getSquare());
		}

		TEST_METHOD(SquareC)
		{
			Circle c(2);
			double square = 12.56;
			Assert::AreEqual(square, c.getSquare());
		}

		TEST_METHOD(SquareR)
		{
			Rectangle r(2.2, 3.3);
			double square = 7.26;
			Assert::AreEqual(square, r.getSquare());
		}

		TEST_METHOD(SquareV)
		{
			Square s1(6);
			Rectangle r1(4, 3);
			Circle c1(2.2);

			ShapesProcessor Shapes;
			Shapes.push(s1);
			Shapes.push(r1);
			Shapes.push(c1);

			vector<double> Squares;

			Squares.push_back(s1.getSquare());
			Squares.push_back(r1.getSquare());
			Squares.push_back(c1.getSquare());
			Assert::IsTrue(Squares == Shapes.getSquare());
		}

		TEST_METHOD(MaxSquare)
		{
			Square s1(6);
			Rectangle r1(4, 3);
			Circle c1(2.2);

			ShapesProcessor Shapes;
			Shapes.push(s1);
			Shapes.push(r1);
			Shapes.push(c1);

			Assert::AreEqual(s1.getSquare(), Shapes.maxSquare()->getSquare());
		}

		TEST_METHOD(MinSquare)
		{
			Square s1(6);
			Rectangle r1(4, 3);
			Circle c1(2.2);

			ShapesProcessor Shapes;
			Shapes.push(s1);
			Shapes.push(r1);
			Shapes.push(c1);

			Assert::AreEqual(r1.getSquare(), Shapes.minSquare()->getSquare());
		}

		TEST_METHOD(SameSquare)
		{
			Square s1(5);
			Rectangle r1(9, 3.14);
			Circle c1(3);
			Circle c2(3);
			Circle c3(3);

			ShapesProcessor Shapes;
			Shapes.push(s1);
			Shapes.push(r1);
			Shapes.push(c1);
			Shapes.push(c2);
			Shapes.push(c3);

			unsigned int amount = 3;
			Assert::AreEqual(amount, Shapes.sameSquare());
		}
	};
}