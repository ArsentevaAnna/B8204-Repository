#include "stdafx.h"
#include "Base64.h"
#include "CppUnitTest.h"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Base64Test
{
	TEST_CLASS(UnitTest1)
	{
	public:
		// encode  
		TEST_METHOD(Str_0symbol_encode) // 0 символов
		{
			Base64 a;
			string expected = "";
			string s = "";
			int len = s.length();
			string test = a.Encode(s);
			Assert::AreEqual(expected, test);
		}
		TEST_METHOD(Str_1symbol_encode) // 1 символ
		{
			Base64 a;
			string expected = "YQ==";
			string s = "a";
			int len = s.length();
			string test = a.Encode(s);
			Assert::AreEqual(expected, test);
		}
		TEST_METHOD(Str_2symbols_encode) // 2 символа
		{
			Base64 a;
			string expected = "QW4=";
			string s = "An";
			int len = s.length();
			string test = a.Encode(s);
			Assert::AreEqual(expected, test);
		}
		TEST_METHOD(Str_3symbols_encode) // 3 символа
		{
			Base64 a;
			string expected = "QW55";
			string s = "Any";
			int len = s.length();
			string test = a.Encode(s);
			Assert::AreEqual(expected, test);
		}
		TEST_METHOD(Str_4symbols_encode) // 4 символа
		{
			Base64 a;
			string expected = "QW55YQ==";
			string s = "Anya";
			int len = s.length();
			string test = a.Encode(s);
			Assert::AreEqual(expected, test);
		}
		TEST_METHOD(Str_5symbols_encode) // 5 символов
		{
			Base64 a;
			string expected = "TXlDYSs=";
			string s = "MyCa+";
			int len = s.length();
			string test = a.Encode(s);
			Assert::AreEqual(expected, test);
		}
		TEST_METHOD(Str_6symbols_encode) // 6 символов
		{
			Base64 a;
			string expected = "MTJQNXI3";
			string s = "12P5r7";
			int len = s.length();
			string test = a.Encode(s);
			Assert::AreEqual(expected, test);
		}
		TEST_METHOD(Russian_encode) // ввод русских букв
		{
			Base64 a;
			string expected = "";
			string s = "КлМн";
			int len = s.length();
			string test = a.Encode(s);
			Assert::AreEqual(expected, test);
		}


		//decode
		TEST_METHOD(Str_0symbol_decode) // 0 символов
		{
			Base64 a;
			string expected = "";
			string s = "";
			string test = a.Decode(s);
			Assert::AreEqual(expected, test);
		}
		TEST_METHOD(Str_1symbol_decode) // 1 символ
		{
			Base64 a;
			string expected = "7";
			string s = "Nw==";
			string test = a.Decode(s);
			Assert::AreEqual(expected, test);
		}
		TEST_METHOD(Str_2symbols_decode) // 2 символа
		{
			Base64 a;
			string expected = "My";
			string s = "TXk=";
			string test = a.Decode(s);
			Assert::AreEqual(expected, test);
		}
		TEST_METHOD(Str_3symbols_decode) // 3 символа
		{
			Base64 a;
			string expected = "Any";
			string s = "QW55";
			string test = a.Decode(s);
			Assert::AreEqual(expected, test);
		}
		TEST_METHOD(Str_4symbols_decode) // 4 символа
		{
			Base64 a;
			string expected = "nine";
			string s = "bmluZQ==";
			string test = a.Decode(s);
			Assert::AreEqual(expected, test);
		}
		TEST_METHOD(Str_5symbols_decode) // 5 символов
		{
			Base64 a;
			string expected = "12+T/";
			string s = "MTIrVC8=";
			string test = a.Decode(s);
			Assert::AreEqual(expected, test);
		}
		TEST_METHOD(Str_6symbols_decode) // 6 символов
		{
			Base64 a;
			string expected = "Dragon";
			string s = "RHJhZ29u";
			string test = a.Decode(s);
			Assert::AreEqual(expected, test);
		}
		TEST_METHOD(Russian_decode) // ввод русских букв
		{
			Base64 a;
			string expected = "";
			string s = "Ё";
			string test = a.Decode(s);
			Assert::AreEqual(expected, test);
		}
	};
}