#include "stdafx.h"
#include "Header.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Square a(2);
			Rectangle b(1, 4);
			Rectangle d(4, 1);
			Circle c(2);
			ShapesProcessor Shapes;
			Shapes.push(a);
			Shapes.push(b);
			Shapes.push(c);
			Shapes.push(d);

			Assert::AreEqual(Shapes.maxSquare()->getSquare(), 12.56);
		
		}

		TEST_METHOD(TestMethod2)
		{
			Square a(3);
			Rectangle b(1, 4);
			Rectangle d(3, 1);
			Circle c(2);
			ShapesProcessor Shapes;
			Shapes.push(a);
			Shapes.push(b);
			Shapes.push(c);
			Shapes.push(d);

			Assert::AreEqual(Shapes.minSquare()->getSquare(), 3.0);

		}

		TEST_METHOD(TestMethod3)
		{
			Square a(2);
			Rectangle b(1, 4);
			Rectangle d(4, 1);
			ShapesProcessor Shapes;
			Shapes.push(a);
			Shapes.push(b);
			Shapes.push(d);

			Assert::AreEqual(Shapes.SumSquare(), 12.0);
		}


	};


}