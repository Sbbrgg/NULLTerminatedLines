#include<iostream>
#include<windows.h>
using std::cin;
using std::cout;
using std::endl;

int StringLength(const char* str);
char* ToUpper(char* str);
void ToLower(char* str);
char* Shrink(char* str);
bool is_palindrome(const char str[]);
bool is_int_number(const char* str);
int to_int_number(const char* str);
bool is_bin_number(const char* str);
unsigned long long bin_to_dec(const char* str);
bool is_hex_number(const char* str);
unsigned long long hex_to_dec(const char* str);
bool is_IP_adress(const char str[]);
bool is_MAC_adress(const char* str);

//#define BASIC_STRING_OPERATIONS

void main()
{
	cout << sizeof(long int) << endl;
	cout << 'ё' << "\t" << 'Ё' << endl;
	cout << (int)'ё' << "\t" << (int)'Ё' << endl;
	setlocale(LC_ALL, "Russian");
#ifdef BASIC_STRING_OPERATIONS
	//for (int i = 0; i < 256; i++)cout << i << "\t" << (char)i << endl;
	const int SIZE = 90;
	char str[SIZE]/* = "Хорошо      живет     на     свете      Винни      Пух"*/ =
		"Аргентина манит негра";
	cout << "Введите строку" << endl;
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	cout << "Длина: " << strlen(str) << endl;	//Возвращает размер строки в символах
	//cout << "Длина: " << StringLength(str) << endl;
	//cout << ToUpper(str) << endl;
	cout << Shrink(str) << endl;

	cout << "Строка " << (is_palindrome(str) ? "" : "НЕ ") << "является палиндромом" << endl;
	cout << "Строка " << (is_int_number(str) ? "" : "НЕ ") << "является целым числом" << endl;
	int multiplier;
	cout << "Введите множитель: "; cin >> multiplier;
	cout << str << " * " << multiplier << " = " << to_int_number(str) * multiplier << endl;
	cout << str << " * " << multiplier << " = " << atoi(str) * multiplier << endl;
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	//const int SIZE = 100;
	//char str[SIZE];
	//cout << "Введите строку: ";
	//cin.getline(str, SIZE);
	//cout << "Длина: " << StringLength(str) << endl;
	//cout << "Длина: " << strlen(str) << endl;	//Возвращает размер строки в символах
	//ToUpper(str);
	//cout << "В верхнем регистре: " << str << endl;
	//ToLower(str);
	//cout << "В нижнем регистре: " << str << endl;
	//Shrink(str);
	//cout << "После удаления лишних пробелов: " << str << endl;
	//cout << "Палиндром? " << (is_palindrome(str) ? "Да" : "Нет") << endl;  
#endif // BASIC_STRING_OPERATIONS

	const int SIZE = 65;
	char str[SIZE] = {};
	cout << "Введите двоичное число: "; //cin >> str;
	cin.getline(str, SIZE);
	//cout << "Строка " << (is_bin_number(str) ? "" : "НЕ ") << "является двоичным числом" << endl;
	//cout << "Строка " << (is_hex_number(str) ? "" : "НЕ ") << "является шестнадцатеричным числом" << endl;
	//cout << hex_to_dec(str) << endl;

	cout << "Строка " << (is_IP_adress(str) ? "" : "НЕ ") << "является IP-адрессом" << endl;

	main();	//рекурсивынй вызов, чтобы прервать ctrl+c либо ctrl + pausebreake
}

int StringLength(const char* str)
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
char* ToUpper(char* str)
{
	for (int i = 0; str[i]; i++)
	{
		//if(str[i]>='a' &&str[i]<='z')str[i] -= ' '/*str[i] -= 32;*/;
		//if(str[i]>='а' &&str[i]<='я')str[i] -= ' ';
		//if (str[i] == 'ё')str[i] -= 16;
		str[i] = toupper(str[i]);
	}
	return str;
	/*for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
	}*/
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
char* Shrink(char* str)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)str[j] = str[j + 1];
		}
	}
	return str;
	/*bool space = true;
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
	str[j] = '\0';*/
}
char* RemoveSymbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
	return str;
}
bool is_palindrome(const char str[])
{
	int n = strlen(str);
	char* buffer = new char[n + 1] {};
	for (int i = 0; str[i]; i++)buffer[i] = str[i];
	ToUpper(buffer);
	n = strlen(RemoveSymbol(buffer, ' '));
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			return false;
			delete[] buffer;
		}
	}
	delete[] buffer;
	return true;
	/*int len = StringLength(str), index = 0;
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
	return true;*/
}
bool is_int_number(const char* str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ') continue;
		if (str[i] < '0' || str[i] > '9') return false;
	}
	return true;
	/*int i = 0;
	if (str[i] == '\0') return false;
	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9') return false;
	}
	return true;*/
}
int to_int_number(const char* str)
{
	if (!is_int_number(str))return INT_MIN;
	int number = 0;
	int length = strlen(str);
	for (int i = 0; str[i]; i++)
	{
		number = number * 10 + str[i] - '0';
	}
	return number;
	/*int i = 0, num = 0, sign = 1;
	for (; str[i] != '\0'; i++)
	{
		num *= 10;
		num += str[i] - '0';
	}
	return num;*/
}

int contiguousSymbolsCount(const char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != symbol) return i;
	}
}
bool is_bin_number(const char* str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1') return false;
	}
	return true;
	/*for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '0' && str[i] != '1')
		{
			return false;
		}
	}
	return true;*/
}
unsigned long long bin_to_dec(const char* str)
{
	if (!is_bin_number(str)) return ULLONG_MAX;
	unsigned long long int decimal = 0;
	for (int i = 0; str[i]; i++)
	{
		decimal = decimal * 2 + str[i] - '0';
	}
	return decimal;
	/*int rezult = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		rezult = rezult * 2 + (str[i] - '0');
	}
	return rezult;*/
}

bool is_hex_number(const char* str)
{
	for (int i = (str[0] == '0' && str[1] == 'x' ? 2 : 0); str[i]; i++)
	{
		if ((str[i] < '0' || str[i] > '9') &&
			(str[i] < 'a' || str[i] > 'f') &&
			(str[i] < 'A' || str[i] > 'F')) return false;
	}
	return true;
	/*for (int i = 0; str[i] != '\0'; i++)
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F')))
		{
			return false;
		}
	}
	return true;*/
}
unsigned long long hex_to_dec(const char* str)
{
	if (!is_hex_number(str))return ULLONG_MAX;
	unsigned long long decimal = 0;
	for (int i = (str[0] == '0' && str[1] == 'x' ? 2 : 0); str[i]; i++)
	{
		char hex_digit = str[i];
		if (hex_digit >= '0' && hex_digit <= '9')hex_digit -= '0';
		else if (hex_digit >= 'A' && hex_digit <= 'F')(hex_digit -= 'A') += 10;
		else if (hex_digit >= 'a' && hex_digit <= 'f')(hex_digit -= 'a') += 10;
		decimal = decimal * 16 + hex_digit;
	}
	return decimal;
	/*int rezult = 0, i = 0;
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
	return rezult;*/
}

//bool is_IP_adress(const char str[])
//{
//	int n = strlen(str);
//	if (n < 7 || n > 15)return false;
//	char bytes[4][4] = {};
//	//char byte[4] = {};
//	for (int i = 0, j = 0, k = 0, points = 0; str[i]; i++)
//	{
//		if (str[i] == '.')
//		{
//			j++;
//			points++;
//			if (points > 3) return false;
//			k = 0;
//			continue;
//		}
//		bytes[j][k++] = str[i];
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		if (is_int_number(bytes[i]) > 255)return false;
//		cout << bytes[i] << "\t";
//	}
//	cout << endl;
//
//	//					MY VERSION						\\
//
//	/*int len = StringLength(str), num = 0, parts = 0, digitals_of_part = 0;
//	if (len < 7 || len > 15)return false;
//	for (int i = 0; i <= len; i++)
//	{
//		if (isdigit(str[i]))
//		{
//			num = num * 10 + (str[i] - '0');
//			digitals_of_part++;
//			if (num > 255 || digitals_of_part > 3) return false;
//		}
//		else if (str[i] == '.' || str[i] == '\0')
//		{
//			if (digitals_of_part == 0)return false;
//			++parts;
//			num = 0;
//			digitals_of_part = 0;
//			if (parts > 4) return false;
//		}
//		else return false;
//	}
//	return parts == 4;*/
//}
bool is_IP_adress(const char str[])
{
	int n = strlen(str);
	if (n < 7 || n > 15)return false;
	char byte[4] = {};
	for (int i = 0, j = 0; str[i]; i++)
	{
		if (str[i] == '.')
		{
			j=0;
			if (j > 3) return false;
			if (is_int_number(byte) > 255) return false;
			continue;
		}
		byte[j++] = str[i];
		if (j > 3)return false;
	}
	return true;
}
bool is_MAC_adress(const char* str)
{
	int len = StringLength(str);
	if (len != 17)return false;

	for (int i = 0; i < 17; i++)
	{
		if (i % 3 == 2)
		{
			if (str[i] != ':')return false;
		}
		else
		{
			if (!((str[i] >= '0' && str[i] <= '9') ||
				(str[i] >= 'a' && str[i] <= 'f') ||
				(str[i] >= 'A' && str[i] <= 'F')))
				return false;
		}
	}
	return true;
}