#pragma once
#include <string>
using namespace std;
class Base64
{
private:
	static const string CODE64LIST;

public:
	static string BASE64Decode(string input);

	static string BASE64Encode(string input);
};