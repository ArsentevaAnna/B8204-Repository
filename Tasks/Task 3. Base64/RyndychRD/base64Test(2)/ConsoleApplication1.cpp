
#include "stdafx.h"
#include <string.h>
#include <bitset>
#include <iostream>
#include "base64.h"
using namespace std;
const char base64[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
'+', '/','=' };
const char pad = '=';
char NumToBase64(int chrNum) {
	//rewrite in switch
	if (chrNum < 64 && chrNum >= 0) {
		return base64[chrNum];
	}
	return pad;
}
int base64ToNum(char baseChar) {
	for (int i = 0; i < 64; i++) {
		if (base64[i] == baseChar) {
			return i;
		}
	}
	if (baseChar == '=') {
		return 0;
	}
	return -1;
}

int countToUpdateStr(string inStr) {
	int count = 0;
	int length = inStr.length();
	while ((length * 8 % 6) != 0) {
		count++;
		length++;
	}
	return count;
}

string convert(string inStr, int count) {
	string result;
	for (int i = 0; i < inStr.length(); i++) {
		bitset<8> charByte(inStr[i]);
		result += charByte.to_string();
	}
	for (int i = 0; i < count; i++) {
		result += "00000000";
	}
	return result;
}
string codeBit6(string bitStr) {
	string result;
	int countSimb = bitStr.length() / 6;
	for (int i = 0; i < countSimb; i++) {
		bitset<6> bit6(bitStr.substr(i*6, (i+1)*6));
		long temp = bit6.to_ullong();
		result += NumToBase64(temp);
	}
	return result;
}

string addPad(string outStr, int count) {
	int length = outStr.length();
	if (count == 2) {
		//in order to not to delete/0 i had to add -1, sorry(((
		outStr[length-1] = pad;     
		outStr[length - 2] = pad;
	}
	if (count == 1) {
		//in order to not to delete/0 i had to add -1, sorry(((
		outStr[length-1] = pad;
	}
	return outStr;
}



int countToDelete(string inStr) {
	int res=0;
	while (inStr[inStr.length() - 1 - res] == '=') {
		res++;
	}
	return res;
}

string convert(string inStr) {
	string res;
	for (int i = 0; i < inStr.length(); i++) {
		bitset<6> bit6(base64ToNum(inStr[i]));
		res += bit6.to_string();
	}
	return res;
}

string codeBit8(string inStr, int count) {
	string result;
	inStr = inStr.substr(0, inStr.length() - (count * 8));
	int countSimb = inStr.length() / 8;
	for (int i = 0; i < countSimb; i++) {
		bitset<8> bit8(inStr.substr(i * 8, (i + 1) * 8));
		long temp = bit8.to_ullong();
		result += char(temp);
	}
	return result;
}

string Base64::decodeBase64(string inStr) {
	//what if not enough base64 simb
	string outStr;
	if (inStr == "") {
		return "";
	}
	if (inStr.length() * 6 % 8 != 0) {
		return "Error in count of simb base64";
	}
	int count = countToDelete(inStr);
	inStr = convert(inStr);
	outStr = codeBit8(inStr, count);
	return outStr;
}

string Base64::codeBase64(string inStr) {
	string outStr;
	string tempBitStr;
	int countUpdateSimb = 0;
	countUpdateSimb = countToUpdateStr(inStr);
	tempBitStr = convert(inStr, countUpdateSimb);
	outStr = codeBit6(tempBitStr);
	outStr = addPad(outStr, countUpdateSimb);
	return outStr;
}
