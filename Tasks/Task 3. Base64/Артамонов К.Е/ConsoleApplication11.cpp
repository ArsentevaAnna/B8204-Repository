// ConsoleApplication11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;
	
const string code = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

class Base64
{
public:
	string encode(string input)
	{
		unsigned int length = input.length();
		unsigned char Base64code;
		string out;

		for (unsigned int i = 0; i < length; i += 3) {
			Base64code = (input[i] & 0xFC) >> 2;
			out += code[Base64code];
			Base64code = (input[i] & 0x03) << 4;

			if (i + 1 < length) {
				Base64code += (input[i + 1] & 0xF0) >> 4;
				out += code[Base64code];
				Base64code = (input[i + 1] & 0x0F) << 2;
				if (i + 2 < length) {
					Base64code += (input[i + 2] & 0xC0) >> 6;
					out += code[Base64code];
					Base64code = (input[i + 2] & 0x3F);
					out += code[Base64code];
				}
				else {
					out += code[Base64code];
					out += "=";
				}
			}
			else {
				out += code[Base64code];
				out += "==";
			}
		}
		return out;
	}

	string decode(string input)
	{
		unsigned int length = input.length();
		unsigned char normalCode;
		unsigned char Base64code[4];
		string out;

		if (length % 4 != 0) {
				return "";
			}
		for (size_t i = 0; i < length; i += 4) {
			Base64code[0] = (unsigned char)code.find(input[i]);
			Base64code[1] = (unsigned char)code.find(input[i + 1]);
			Base64code[2] = (unsigned char)code.find(input[i + 2]);
			Base64code[3] = (unsigned char)code.find(input[i + 3]);
			normalCode = Base64code[0] << 2 | Base64code[1] >> 4;
			out += normalCode;

			if (Base64code[2] < 64) {
				normalCode = Base64code[1] << 4 | Base64code[2] >> 2;
				out += normalCode;
				if (Base64code[3] < 64) {
					normalCode = Base64code[2] << 6 | Base64code[3];
					out += normalCode;
				}
			}
		}
		return out;
	}
};

int main()
{
	Base64 a;
	string str;
	str = a.encode("ABC");
	cout << str << endl;
	cout << a.decode(str) << endl;

	system("PAUSE");
	return 0;
}

