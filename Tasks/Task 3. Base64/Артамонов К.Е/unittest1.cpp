#include "stdafx.h"
#include "CppUnitTest.h"
#include "ConsoleApplication11.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Base64LibUnitTest
{
	TEST_CLASS(Test)
	{
	public:

		TEST_METHOD(encode1)
		{
			string expected = "";
			Base64 testClass;
			string test = testClass.encode("");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(encode2)
		{
			string expected = "YQ==";
			Base64 testClass;
			string test = testClass.encode("a");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(encode3)
		{
			string expected = "YXM=";
			Base64 testClass;
			string test = testClass.encode("as");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(encode4)
		{
			string expected = "YXNk";
			Base64 testClass;
			string test = testClass.encode("asd");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(decode1)
		{
			std::string expected = "";
			Base64 testClass;
			std::string test = testClass.decode("");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(decode2)
		{
			Base64 testClass;
			auto func = [this] { testClass.decode("a"); };
			Assert::ExpecteException< std::exception>(func);
		}

		TEST_METHOD(decode3)
		{
			std::string expected = "a";
			Base64 testClass;
			std::string test = testClass.decode("YQ==");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(decode4)
		{
			std::string expected = "as";
			Base64 testClass;
			std::string test = testClass.decode("YXM=");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(decode5)
		{
			std::string expected = "asd";
			Base64 testClass;
			std::string test = testClass.decode("YXNk");
			Assert::AreEqual(expected, test);
		}
	};
}
