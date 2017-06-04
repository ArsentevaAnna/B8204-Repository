#pragma once
#include <string.h>
#include <iostream>
#include <string>

typedef unsigned char uchar;

class Base64
{
public:
	// Returns encoded string
	static std::string codeBase64(std::string inStr);

	// Returns decoded string
	static std::string decodeBase64(std::string inStr);

};
