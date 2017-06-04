#include "stdafx.h"
#include "CppUnitTest.h"
#include "shapes.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ShapesTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestGetSquares)
		{
			ShapesProcessor shapesProcessor;

			Rectangle R(10, 15);
			Circle C(3);
			Square S(5);

			shapesProcessor.addShape(R);
			shapesProcessor.addShape(C);
			shapesProcessor.addShape(S);

			vector<float> result = shapesProcessor.getSquareAllShapes();
			float arrayCheck[3] = { 10 * 15, 3 * 3 * 3.14, 5 * 5};

			for (int i = 0; i < 3; i++)
			{
				Assert::AreEqual(arrayCheck[i], result[i]);
			}
		}

		TEST_METHOD(TestMaxSquare)
		{
			ShapesProcessor shapesProcessor;

			Rectangle R(10, 15);
			Circle C(3);
			Square S(5);

			shapesProcessor.addShape(R);
			shapesProcessor.addShape(C);
			shapesProcessor.addShape(S);

			Shape* result = shapesProcessor.getMaxSquare();
			float checkRes = 10 * 15;

			Assert::AreEqual(checkRes, result->getSquare());
		}

		TEST_METHOD(TestMinSquare)
		{
			ShapesProcessor shapesProcessor;

			Rectangle R(10, 15);
			Circle C(3);
			Square S(5);

			shapesProcessor.addShape(R);
			shapesProcessor.addShape(C);
			shapesProcessor.addShape(S);

			Shape* result = shapesProcessor.getMinSquare();
			float checkRes = 5 * 5;

			Assert::AreEqual(checkRes, result->getSquare());
		}

		TEST_METHOD(TestGetSameSquare)
		{
			ShapesProcessor shapesProcessor;

			Rectangle R(10, 10);
			Circle C(3);
			Square S(10);

			shapesProcessor.addShape(R);
			shapesProcessor.addShape(C);
			shapesProcessor.addShape(S);

			Assert::AreEqual(shapesProcessor.getSameSquare(), 2);
		}

		TEST_METHOD(TestGetSameSquareType)
		{
			ShapesProcessor shapesProcessor;

			Rectangle R(10, 10);
			Circle C(3);
			Square S(10);

			shapesProcessor.addShape(R);
			shapesProcessor.addShape(R);
			shapesProcessor.addShape(C);
			shapesProcessor.addShape(S);
			shapesProcessor.addShape(S);

			ShapesProcessor result = shapesProcessor.getSameSquareType();
			vector<float> newresult = result.getSquareAllShapes();

			float checkSquare = 10 * 10;

			for (int i = 0; i < 2; i++)
			{
				Assert::AreEqual(newresult[i], checkSquare);
			}
		}

	};
}