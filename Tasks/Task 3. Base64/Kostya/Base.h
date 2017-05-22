#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <bitset>

using namespace std;

class Base64 {
public:
    char getSymbolBase64FromASCII(int p);
    int getIndexBase64(char p);
    string Base64ToText(string my);
    string TextToBase64(string my);
};

#endif