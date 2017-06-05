﻿
#include "stdafx.h"
#include <CppUnitTest.h>
#include "base64.h"

; using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Base64LibUnitTest
{
	TEST_CLASS(Test)
	{
	public:

		TEST_METHOD(a_codeBase64)
		{
			std::string expected = "YQ==";
			std::string test = Base64::codeBase64("a");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(ab_codeBase64)
		{
			std::string expected = "YWI=";
			std::string test = Base64::codeBase64("ab");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abc_codeBase64)
		{
			std::string expected = "YWJj";
			std::string test = Base64::codeBase64("abc");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcd_codeBase64)
		{
			std::string expected = "YWJjZA==";
			std::string test = Base64::codeBase64("abcd");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcde_codeBase64)
		{
			std::string expected = "YWJjZGU=";
			std::string test = Base64::codeBase64("abcde");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcdef_codeBase64)
		{
			std::string expected = "YWJjZGVm";
			std::string test = Base64::codeBase64("abcdef");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(empty_codeBase64)
		{
			std::string expected = "";
			std::string test = Base64::codeBase64("");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(empty_decodeBase64)
		{
			std::string expected = "";
			std::string test = Base64::decodeBase64("");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(one_sym_decodeBase64)
		{
			std::string expected = "";
			std::string test = Base64::decodeBase64("h");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(a_decodeBase64)
		{
			std::string expected = "a";
			std::string test = Base64::decodeBase64("YQ==");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(ab_decodeBase64)
		{
			std::string expected = "ab";
			std::string test = Base64::decodeBase64("YWI=");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abc_decodeBase64)
		{
			std::string expected = "abc";
			std::string test = Base64::decodeBase64("YWJj");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcd_decodeBase64)
		{
			std::string expected = "abcd";
			std::string test = Base64::decodeBase64("YWJjZA==");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcde_decodeBase64)
		{
			std::string expected = "abcde";
			std::string test = Base64::decodeBase64("YWJjZGU=");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcdef_decodeBase64)
		{
			std::string expected = "abcdef";
			std::string test = Base64::decodeBase64("YWJjZGVm");
			Assert::AreEqual(expected, test);
		}
		TEST_METHOD(error_decodeBase64)
		{
			try{
				std::string test = Base64::decodeBase64("***");
			}
			catch (std::string e)
			{
				Assert::IsTrue;
			}
			Assert::IsFalse	;
		}
	};
}
