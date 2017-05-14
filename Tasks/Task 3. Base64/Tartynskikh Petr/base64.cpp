#include "stdafx.h"
#include <iostream>
#include "base64.h"

using namespace std;

const string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


bool convertable(char c) //�������� �� ������������� �� base64 �� ������������
{
	return (isalnum(c) || (c == '+') || (c == '/'));
}

string encode(const char* str, int str_length) {
	string result;
	int i = 0;
	int j = 0;
	char char_array_3[3];
	char char_array_4[4];

	while (str_length--) 
	{
		char_array_3[i++] = *(str++);
		if (i == 3) //����� �� ������ �� 3 �������
		{
			//�����
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

	if (i) //���� ���������� ���� �� ������� �� 3 (�� ���� �������� ��� �����)
	{
		for (j = i; j < 3; j++)
		{
			char_array_3[j] = '\0';
		}

		//��� �����
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

string decode(string str) 
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

			//�������� �����
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

		//��� ������� �������� �����
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