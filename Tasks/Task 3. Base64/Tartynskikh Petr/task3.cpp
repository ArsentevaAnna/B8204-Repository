#include "stdafx.h"
#include <iostream>
#include "base64.h"

using namespace std;

int main() 
{
	string s = "Shaz bi v dotku";

	string encoded = encode(s.c_str(), s.length());
	string decoded = decode(encoded);
	cout << "Encoded: " << encoded << endl;
	cout << "Decoded: " << decoded << endl;

	getchar();

	return 0;
}