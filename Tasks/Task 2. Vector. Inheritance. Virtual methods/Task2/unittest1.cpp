
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
			vector<IShape*> v;
			v.push_back(&a);
			v.push_back(&b);
			v.push_back(&c);
			v.push_back(&d);
			ShapesProcessor SP(v);
			float k = 12.56;
			Assert::AreEqual(SP.MaxS(), k);

			// TODO: Разместите здесь код своего теста
		}

		TEST_METHOD(TestMethod2) {
			Square a(3);
			Rectangle b(1, 4);
			Rectangle d(3, 1);
			Circle c(2);
			vector<IShape*> v;
			v.push_back(&a);
			v.push_back(&b);
			v.push_back(&c);
			v.push_back(&d);

			ShapesProcessor SP(v);
			float k = 3.0;
			
			Assert::AreEqual(SP.MinS(), k);
			}
		
			TEST_METHOD(TestMethod3) {
			Square a(2);
			Rectangle b(1, 4);
			Rectangle d(4, 1);
			vector<IShape*> v;
			v.push_back(&a);
			v.push_back(&b);
			v.push_back(&d);

			ShapesProcessor SP(v);
			float k = 12.0;
			
			Assert::AreEqual(SP.SumSquares(), k);
			}

			TEST_METHOD(TestMethod4) {
				Square a(2);
				Rectangle b(1, 4);
				Circle c(2);
				vector<IShape*> v;
				v.push_back(&a);
				v.push_back(&b);
				v.push_back(&c);

				ShapesProcessor SP(v);

				Assert::AreEqual(SP.EqSquares(), 2);
			}

			TEST_METHOD(TestMethod5) {
				Square a(2);
				Rectangle b(1, 4);
				Circle c(2);
				Rectangle d(2, 2);
				vector<IShape*> v;
				v.push_back(&a);
				v.push_back(&b);
				v.push_back(&c);
				v.push_back(&d);

				ShapesProcessor SP(v);
				vector<IShape*> w;
				w.push_back(&a);
				w.push_back(&b);


				Assert::AreEqual(SP.EqSquaresVec(), w);
			}

	};
}