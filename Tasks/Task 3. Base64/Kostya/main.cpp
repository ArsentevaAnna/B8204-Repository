#include "Base.h"
  
using namespace std;

char Base64::getSymbolBase64FromASCII(int p)
{
	if (p >= 0 && p <= 25) return (char)(65 + p);
	else if (p >= 26 && p <= 51) return (char)(71 + p);
	else if (p >= 52 && p <= 61) return (char)(p - 4);
	else if (p == 62) return (char)43;
	else if (p == 63) return (char)47;
}

int Base64::getIndexBase64(char p)
{
	if (p >= 'A' && p <= 'Z') return (int)p - 65;
	else if (p >= 'a' && p <= 'z') return (int)p - 71;
	else if (p >= '0' && p <= '9') return (int)p + 4;
	else if (p == '+') return 62;
	else if (p == '/') return 63;
	return -1;
}

string Base64::Base64ToText(string my)
{
	bitset<14> main;
	string end = "";
	const int size = my.size();
	for (int i = 0, a = 8; i < size; i++)
	{
		if (my[i] == '=') break;
		int s = getIndexBase64(my[i]);
		if (s == -1) return "";
		main |= (bitset<14>(s) << a);
		if (a == 8) a = 2;
		else
		{
			end += (char)((main >> 6).to_ulong());
			main <<= 8;
			a += 2;
		}
	}
	return end;
}

string Base64::TextToBase64(string my)
{
	bitset<14> main;
	string end = "";
	const int size = my.size();
	for (int i = 0, a = 6; i < size; i++)
	{
		main |= (bitset<14>((unsigned char)my[i]) << a);
		end += getSymbolBase64FromASCII((main >> 8).to_ulong());
		main <<= 6;
		a -= 2;
		if (a == 0 || i == size - 1)
		{
			end += getSymbolBase64FromASCII((main >> 8).to_ulong());
			main <<= 6;
			a = 6;
		}
	}
	if ((size + 1) % 3 == 0) end += "=";
	else if ((size + 2) % 3 == 0) end += "==";
	return end;
}

int main()
{
	Base64 p;
	cout << p.TextToBase64("MK") << endl;
	cout << p.Base64ToText("TUs=") << endl;
	cout << p.Base64ToText(p.TextToBase64("MK")) << endl;
	return 0;
}