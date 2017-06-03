#include "stdafx.h"
#include "CppUnitTest.h"
#include "shapes.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace task2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Метод для подсчёта площади всех фигур внутри вектора фигур
			Square S1(1);
			Rectangle S2(1, 3);
			Rectangle S3(1, 4);
			Circle S4 (1);
			Circle S5(2);
			ShapesProcessor Shapes;
			Shapes.add(S1);
			Shapes.add(S2);
			Shapes.add(S3);
			Shapes.add(S4);
			Shapes.add(S5);
			vector<float> expected;
			expected.push_back(S1.getSquare());
			expected.push_back(S2.getSquare());
			expected.push_back(S3.getSquare());
			expected.push_back(S4.getSquare());
			expected.push_back(S5.getSquare());
			for (int i = 0; i < 5; i++)
				Assert::AreEqual(expected[i], Shapes.getSquare()[i]);
		}
		TEST_METHOD(TestMethod2)
		{
			// Метод для поиска фигуры с наибольшей площадью
			Square S1(1);
			Rectangle S2(1, 3);
			Rectangle S3(1, 4);
			Circle S4(1);
			Circle S5(2);
			ShapesProcessor Shapes;
			Shapes.add(S1);
			Shapes.add(S2);
			Shapes.add(S3);
			Shapes.add(S4);
			Shapes.add(S5);
			Assert::AreEqual(S5.getSquare(), Shapes.maxSquare()->getSquare());
		}
		TEST_METHOD(TestMethod3)
		{
			// Метод для поиска фигуры с наименьшей площадью
			Square S1(1);
			Rectangle S2(1, 3);
			Rectangle S3(1, 4);
			Circle S4(1);
			Circle S5(2);
			ShapesProcessor Shapes;
			Shapes.add(S1);
			Shapes.add(S2);
			Shapes.add(S3);
			Shapes.add(S4);
			Shapes.add(S5);
			Assert::AreEqual(S1.getSquare(), Shapes.minSquare()->getSquare());
		}TEST_METHOD(TestMethod4)
		{
			// Метод для поиска фигур с одинаковой площадью, возвращает максимальное число фигур одинаковой площади
			Square S1(1);
			Rectangle S2(1, 3.14);
			Rectangle S3(3.14, 1);
			Circle S4(1);
			Circle S5(2);
			Square S6(1);
			ShapesProcessor Shapes;
			Shapes.add(S1);
			Shapes.add(S2);
			Shapes.add(S3);
			Shapes.add(S4);
			Shapes.add(S5);
			Shapes.add(S6);
			int expected = 3;
			Assert::AreEqual(expected, Shapes.sameSquare());
		}TEST_METHOD(TestMethod5)
		{
			// Метод для поиска фигур с одинаковой площадью, но разного типа, возвращает вектор из этих фигур
			Square S1(1);
			Rectangle S2(1, 3.14);
			Rectangle S3(3.14, 1);
			Circle S4(1);
			Circle S5(2);
			Square S6(1);
			ShapesProcessor Shapes;
			Shapes.add(S1);
			Shapes.add(S2);
			Shapes.add(S3);
			Shapes.add(S4);
			Shapes.add(S5);
			Shapes.add(S6);
			ShapesProcessor expected;
			expected.add(S2);
			expected.add(S4);
			for (int i = 0; i < 2; i++)
				Assert::AreEqual(expected.getSquare()[i], Shapes.sameSquareType()->getSquare()[i]);
		}
	};
}