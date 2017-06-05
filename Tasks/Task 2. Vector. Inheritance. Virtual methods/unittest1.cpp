#include "stdafx.h"
#include "CppUnitTest.h"
#include "ShapeProc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Shape1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Square a(2);
			Rectangle b(1, 4);
			Circle c(2);
			Rectangle d(4, 1);;
			ShapeProcessor Shapes;
			Shapes.push(a);
			Shapes.push(b);
			Shapes.push(c);
			Shapes.push(d);

			Assert::AreEqual(Shapes.getAllSquare(),float( 4 + 4 + 4 * 3.14 + 4));

		}

		TEST_METHOD(TestMethod2)
		{
			Square a(3);
			Rectangle b(1, 4);
			Circle c(2);
			Rectangle d(3, 1);
			ShapeProcessor Shapes;
			Shapes.push(a);
			Shapes.push(b);
			Shapes.push(c);
			Shapes.push(d);

			Assert::AreEqual(Shapes.maxSquare(),float( 3.14 * 4));

		}

		TEST_METHOD(TestMethod3)
		{
			Square a(3);
			Rectangle b(1, 4);
			Circle c(2);
			Rectangle d(3, 1);
			ShapeProcessor Shapes;
			Shapes.push(a);
			Shapes.push(b);
			Shapes.push(c);
			Shapes.push(d);

			Assert::AreEqual(Shapes.minSquare(),float( 3.0));
		}

		TEST_METHOD(TestMethod4)
		{
			Square a(2);
			Rectangle b(1, 4);
			Circle c(2);
			Rectangle d(4, 1);;
			ShapeProcessor Shapes;
			Shapes.push(a);
			Shapes.push(b);
			Shapes.push(c);
			Shapes.push(d);

			Assert::AreEqual(Shapes.sameSquare(), 3);

		}

	};
}