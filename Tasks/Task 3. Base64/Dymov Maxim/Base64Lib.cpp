#include "Base64Lib.h"
#include <bitset>
#include <stdexcept>

using namespace std;

const string Base64::CODE64LIST = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

string Base64::BASE64Decode(string input)
{
	string output;

	int lengthInput = input.length();
	int validBits = 6;
	bitset <8> bitsContainer;
	int bitShift = 2;

	for (int i = 0; i < lengthInput; i++)
	{
		if (input[i] != '=')
		{
			if ((i % 4) == 0)
			{
				bitsContainer.reset();
				bitsContainer = Base64::CODE64LIST.find(input[i]) << 2;
				bitShift = 2;
			}
			else
			{
				bitsContainer |= ((bitset <8>) Base64::CODE64LIST.find(input[i])) >> (bitShift * 2 % 6);
				validBits += 2;

				if (validBits == 8)
				{
					output += (char)(bitsContainer.to_ulong());
					validBits = 6;
					bitShift += 2 % 8;
					bitsContainer = ((bitset <8>) Base64::CODE64LIST.find(input[i])) << bitShift;
				}
			}
		}
	}
	return output;
}

string Base64::BASE64Encode(string input)
{
	string output;

	short int bitShift = 2;
	int lengthInput = input.length();

	bitset <6> bitsContainer;

	for (int i = 0; i < lengthInput; i++)
	{
		bitsContainer |= (bitset <6>) ((unsigned char)input[i] >> bitShift);
		output += Base64::CODE64LIST[bitsContainer.to_ulong()];
		bitsContainer.reset();

		if ((bitShift * 2 % 6) != 0) bitsContainer = (bitset <6>) (input[i] << (bitShift * 2 % 6));

		if (bitShift == 6)
		{
			output += Base64::CODE64LIST[((bitset <6>) input[i]).to_ulong()];
			bitShift = 0;
		}

		if (i == input.length() - 1 && bitShift != 0)
		{
			output += Base64::CODE64LIST[((bitset <6>) (input[i] << (bitShift * 2 % 6))).to_ulong()];
		}

		bitShift += 2;
	}

	if ((lengthInput + 1) % 3 == 0) output += "=";
	else if ((lengthInput + 2) % 3 == 0) output += "==";

	return output;
}