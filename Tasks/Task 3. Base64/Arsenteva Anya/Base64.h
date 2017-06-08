#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

const string char64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

class Base64
{
public:
	string Encode(string str);
	string Decode(string str);
};
