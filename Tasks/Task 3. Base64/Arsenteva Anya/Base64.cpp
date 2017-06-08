#include "stdafx.h"
#include "base64.h"
#include <iostream>
using namespace std;

string Base64::Encode(string str)
{
	string exitStr;
    unsigned int length = str.length();
	const char* _str = str.c_str(); // �� ������ �������� ������ ��������
	for (unsigned int i = 0; i < length; i++)
	{
		if ((_str[i] >= '�' && _str[i] <= '�') || _str[i] == '�' || _str[i] == '�')
		{
			return "";
		}
	}
	
	int i = 0; int j = 0;
	char char_3[3];
	char char_4[4];

	while (length--)
	{
		char_3[i++] = *(_str++);
		if (i == 3) //����� �� ������ �� 3 �������
		{
			//�� 8 ��������� �� 6 �����
			char_4[0] = (char_3[0] & 0xfc) >> 2; //1111 1100
			char_4[1] = ((char_3[0] & 0x03) << 4) + ((char_3[1] & 0xf0) >> 4); //0000 0011 //1111 0000
			char_4[2] = ((char_3[1] & 0x0f) << 2) + ((char_3[2] & 0xc0) >> 6); //0000 1111 //1100 0000
			char_4[3] = char_3[2] & 0x3f; //0011 1111

			for (i = 0; (i < 4); i++)
			{
				exitStr = exitStr + char64[char_4[i]];
			}
			i = 0;
		}
	}

	if (i % 3 != 0) // ���������� �������� �� ������ 3
	{
		for (j = i; j < 3; j++)
		{
			char_3[j] = '\0';
		}

		//�� 8 ��������� �� 6 �����
		char_4[0] = (char_3[0] & 0xfc) >> 2; //1111 1100
		char_4[1] = ((char_3[0] & 0x03) << 4) + ((char_3[1] & 0xf0) >> 4); //0000 0011 //1111 0000
		char_4[2] = ((char_3[1] & 0x0f) << 2) + ((char_3[2] & 0xc0) >> 6); //0000 1111 //1100 0000
		char_4[3] = char_3[2] & 0x3f; //0011 1111

		for (j = 0; (j < i + 1); j++)
		{
			exitStr = exitStr + char64[char_4[j]];
			//cout << result << endl;
		}

		while ((i++ < 3))
		{
			exitStr = exitStr + '=';
			//cout << result << endl;
		}
	}
	return exitStr;
}

string Base64::Decode(string str)
{
	string exitStr;
	unsigned int length = str.length();
	for (unsigned int i = 0; i < length; i++)
	{
		if (str[i] >= 'A' && str[i] <= '�' || str[i] == '�' || str[i] == '�')
		{
			return "";
		}
	}

	int i = 0; int j = 0;  int k = 0;
	char char_3[3], char_4[4];

	while (length-- && (str[k] != '='))
	{
		char_4[i++] = str[k];
		k++;
		if (i == 4)
		{
			for (i = 0; i < 4; i++)
			{
				char_4[i] = char64.find(char_4[i]); //�������� ������� ������� � ������
			}

			//�� 6 ������ 8 �����
			char_3[0] = (char_4[0] << 2) + ((char_4[1] & 0x30) >> 4); //110 000
			char_3[1] = ((char_4[1] & 0xf) << 4) + ((char_4[2] & 0x3c) >> 2); //001 111 //111 100
			char_3[2] = ((char_4[2] & 0x3) << 6) + char_4[3]; //000 011


			for (i = 0; (i < 3); i++)
			{
				exitStr = exitStr + char_3[i];
			}
			i = 0;
		}
	}

	if (i % 4 != 0) //���������� �������� �� ������ 4
	{
		for (j = i; j < 4; j++)
		{
			char_4[j] = 0;
		}

		for (j = 0; j < 4; j++)
		{
			char_4[j] = char64.find(char_4[j]); //�������� ������� ������� � ������
		}

		//�� 6 ������ �� 8 �����
		char_3[0] = (char_4[0] << 2) + ((char_4[1] & 0x30) >> 4);
		char_3[1] = ((char_4[1] & 0xf) << 4) + ((char_4[2] & 0x3c) >> 2);
		char_3[2] = ((char_4[2] & 0x3) << 6) + char_4[3];

		for (j = 0; (j < i - 1); j++)
		{
			exitStr = exitStr + char_3[j];
		}
	}
	return exitStr;
}
