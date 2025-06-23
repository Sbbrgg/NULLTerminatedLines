#include<iostream>
#include<windows.h>
using namespace std;

int StrLength(const char* str);
void ToUpper(char* str);
void ToLower(char* str);
void Shrink(char* str);
bool is_palindrome(const char* str);
bool is_int_number(const char* str);
int to_int_number(char* str);
bool is_bin_number(const char* str);

void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	//char str[] = "Hello";
	const int SIZE = 20;
	char str[SIZE] = {};
	cout << "Hello world!" << endl;
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	cout << StrLength(str);
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
			str[i] -= 20;
		}
	}
}
void ToLower(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 20;
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
		if (str[i] >= 'A' && str[i] <= 'Z') element += 20;
		if ((element >= 'a' && element <= 'z') || (element >= '0' && element <= '9'))
		{
			filtered[index++] = element;
		}
	}
	for (int i = 0; i < index; i++)
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
int to_int_number(char* str)
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
