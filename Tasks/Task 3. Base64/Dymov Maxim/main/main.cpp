#include <iostream>
#include "Base64Lib.h"

using namespace std;

int main()
{
	cout << "[ENCODE] " << Base64::BASE64Encode("Hello, World!") << endl;
	cout << "[DECODE] " << Base64::BASE64Decode("SGVsbG8sIFdvcmxkIQ==") << endl;
	return 0;
}