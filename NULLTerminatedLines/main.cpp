#include<iostream>
#include<windows.h>
using namespace std;

int StrLength(const char* str);
void ToUpper(char* str);
void ToLower(char* str);
void Shrink(char* str);
bool is_palindrome(const char* str);
bool is_int_number(const char* str);
int to_int_number(const char* str);
bool is_bin_number(const char* str);
int bin_to_dec(const char* str);
bool is_hex_number(const char* str);
int hex_to_dec(const char* str);

void main()
{
	//setlocale(LC_ALL, "");
	////char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	////char str[] = "Hello";
	//const int SIZE = 20;
	//char str[SIZE] = {};
	//cout << "Hello world!" << endl;
	//SetConsoleCP(1251);
	//cin.getline(str, SIZE);
	//SetConsoleCP(866);
	//cout << StrLength(str);

}

int StrLength(const char* str)
{
	int length = 0;
	while (str[length] != '\0')length++;
	return length;
}
void ToUpper(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
	}
}
void ToLower(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
	}
}
void Shrink(char* str)
{
	bool space = true;
	int i = 0, j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			str[j++] = str[i++];
			space = false;
		}
		else
		{
			if (!space)
			{
				str[j++] = ' ';
				space = true;
			}
			i++;
		}
	}
	if (str[j - 1] == ' ')--j;
	str[j] = '\0';
}
bool is_palindrome(const char* str)
{
	int len = StrLength(str), index = 0;
	char filtered[50] = { };
	for (int i = 0; i < len; i++)
	{
		char element = str[i];
		if (str[i] >= 'A' && str[i] <= 'Z') element += 32;
		if ((element >= 'a' && element <= 'z') || (element >= '0' && element <= '9'))
		{
			filtered[index++] = element;
		}
	}
	for (int i = 0; i < index/2; i++)
	{
		if (filtered[i] != filtered[index - i - 1])
		{
			return false;
		}
	}
	return true;
}
bool is_int_number(const char* str)
{
	int i = 0;
	if (str[i] == '\0') return false;
	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9') return false;
	}
	return true;
}
int to_int_number(const char* str)
{
	int i = 0, num = 0, sign = 1;
	for (; str[i] != '0'; i++)
	{
		num *= 10;
		num += str[i] - '0';
	}
	return num;
}
bool is_bin_number(const char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '0' && str[i] != '1')
		{
			return false;
		}
	}
	return true;
}
int bin_to_dec(const char* str)
{
	int rezult = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		rezult = rezult * 2 + (str[i] - '0');
	}
	return rezult;
}
bool is_hex_number(const char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F')))
		{
			return false;
		}
	}
}
int hex_to_dec(const char* str)
{
	int rezult = 0, i = 0;
	while (str[i] != '\0')
	{
		int digit;
		if (str[i] >= '0' && str[i] <= '9') digit = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'z') digit = str[i] - 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z') digit = str[i] - 'A';
		else digit = 0;
		rezult = rezult * 16 + digit;
	}
	return rezult;
}
