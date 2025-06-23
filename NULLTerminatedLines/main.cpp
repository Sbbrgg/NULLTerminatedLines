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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int SIZE = 100;
	char str[SIZE];

	cout << "Введите строку: ";
	cin.getline(str, SIZE);

	cout << "Длина: " << StrLength(str) << endl;

	ToUpper(str);
	cout << "В верхнем регистре: " << str << endl;

	ToLower(str);
	cout << "В нижнем регистре: " << str << endl;

	Shrink(str);
	cout << "После удаления лишних пробелов: " << str << endl;

	cout << "Палиндром? " << (is_palindrome(str) ? "Да" : "Нет") << endl;

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
	for (; str[i] != '\0'; i++)
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
	return true;
}
int hex_to_dec(const char* str)
{
	int rezult = 0, i = 0;
	while (str[i] != '\0')
	{
		int digit;
		if (str[i] >= '0' && str[i] <= '9') digit = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f') digit = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F') digit = str[i] - 'A' + 10;
		else digit = 0;
		rezult = rezult * 16 + digit;
		i++;
	}
	return rezult;
}
