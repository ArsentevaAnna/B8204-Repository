#include "stdafx.h"
#include <iostream>
#include "base64.h"

using namespace std;

int main()
{
	string s = "Shaz bi v dotku";

	string encoded = Base64encode(s);
	string decoded = Base64decode(encoded);
	cout << "Encoded: " << encoded << endl;
	cout << "Decoded: " << decoded << endl;

	getchar();

	return 0;
}