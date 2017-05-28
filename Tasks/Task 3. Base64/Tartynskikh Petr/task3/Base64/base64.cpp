#include <stdexcept>
#include <iostream>
#include "base64.h"

using namespace std;

const string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


bool convertable(char c) //Проверка на переводимость из base64 на человеческий
{
	return (isalnum(c) || (c == '+') || (c == '/'));
}

string Base64encode(string _str) {
	string result;
	const char* str = _str.c_str();
	int str_length = _str.length();
	int i = 0;
	int j = 0;
	char char_array_3[3];
	char char_array_4[4];

	while (str_length--)
	{
		char_array_3[i++] = *(str++);
		if (i == 3) //Берем из строки по 3 символа
		{
			//Магия
			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;

			for (i = 0; (i < 4); i++)
			{
				result += letters[char_array_4[i]];
				//cout << result << endl;
			}

			i = 0;
		}
	}

	if (i) //Если количество букв не делится на 3 (то есть остались еще буквы)
	{
		for (j = i; j < 3; j++)
		{
			char_array_3[j] = '\0';
		}

		//Еще магия
		char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		char_array_4[3] = char_array_3[2] & 0x3f;

		for (j = 0; (j < i + 1); j++)
		{
			result += letters[char_array_4[j]];
			//cout << result << endl;
		}

		while ((i++ < 3))
		{
			result += '=';
			//cout << result << endl;
		}
	}
	return result;
}

string Base64decode(string str)
{
	int str_length = str.size();
	int i = 0;
	int j = 0;
	int in_ = 0;
	char char_array_4[4], char_array_3[3];
	string result;

	while (str_length-- && (str[in_] != '=') && convertable(str[in_]))
	{
		char_array_4[i++] = str[in_];
		in_++;
		if (i == 4)
		{
			for (i = 0; i < 4; i++)
			{
				char_array_4[i] = letters.find(char_array_4[i]);
			}

			//Обратная магия
			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (i = 0; (i < 3); i++)
			{
				result += char_array_3[i];
				//cout << result << endl;
			}

			i = 0;
		}
	}

	if (i)
	{
		for (j = i; j < 4; j++)
		{
			char_array_4[j] = 0;
		}

		for (j = 0; j < 4; j++)
		{
			char_array_4[j] = letters.find(char_array_4[j]);
		}

		//Еще немного обратной магии
		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
		char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

		for (j = 0; (j < i - 1); j++)
		{
			result += char_array_3[j];
			//cout << result << endl;
		}
	}

	return result;
}