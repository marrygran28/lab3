#include "lab4.h"

void task_4_1() 
{
	//Определить  является  ли  введенный текст: идентификатором, записью целого числа.

	const int SIZE = 50;
	char text[SIZE];

	cout << "\nВведите строку:\t";
	cin >> setw(SIZE) >> text;	//setw определяет макс кол-во символов которое может принять буфер

	bool is_num = 1, is_id = 0;

	//проверка на запись целого числа
	for (int i = 0; text[i] != '\0'; i++)
		if (!(text[i] >= '0' && text[i] <= '9' || text[0] == '-' || text[0] == '+'))
		{
			is_num = 0;
			break;
		}

	if (is_num)
		cout << "Введено целое число";
	else
	{		
		if (!(text[0] >= '0' && text[0] <= '9'))
			is_id = 1;
		for (int i = 0; text[i] != '\0'; i++)
			//латинские буквы, цифры, символ подчеркивания
			if (!(text[i] >= 'A' && text[i] <= 'Z' ||
				text[i] >= 'a' && text[i] <= 'z' ||
				text[i] >= '0' && text[i] <= '9' || text[i] == '_'))
				is_id = 0;
	}

	if (is_id)
		cout << "\nВведен идентификатор\n";
	else if(!is_num && !is_id)
		cout << "\nВведенный текст не явяется идентификатором/записью целого числа\n";
}

bool is_number4(char *str)
{
	bool dot_flag = 0, is_num = 1;

	//проверка на запись целого числа
	for (int i = 0; str[i] != '\0'; i++)
		if (!(str[i] >= '0' && str[i] <= '9' || 
			str[0] == '-' || str[0] == '+' ||
			(str[i] == '.')? dot_flag = 1: dot_flag = 0) &&
			dot_flag? 0: 1)
			return is_num = 0;
	return is_num;
}

void task_4_2()
{
	//Преобразовать заданное целое число из p-ичной системы счисления в q-ичную (р, q ≤ 16);
	//исходное число имеет не более n знаков).
	//с 88

	int p, q;
	cout << "Cистема счисления №1: "; p = valid_input(p = 0);
	cout << "Сиситема счисления №2: "; q = valid_input(q = 0);

	char c[1000];
	cout << "Число в с/с №1: "; cin >> c;

	int dec = 0;
	int length = strlen(c);
	int n = 1;

	for (int i = length - 1; i >= 0; i--)
	{
		if (c[i] >= '0' && c[i] <= '9')
			dec += int(c[i] - '0') * n;
		else
			dec += (10 + int(c[i] - 'A')) * n;
		n *= p;
	}

	n = 0;
	int rest;
	char result[1000] = "";

	do {
		rest = dec % q;
		if (rest < 10)
			result[n] = char('0' + rest);
		else
			result[n] = char('A' + rest - 10);
		n++;
		dec /= q;
	} while (dec);

	length = strlen(result);

	cout << "Число в с/с №2: ";
	for (int i = length - 1; i >= 0; i--)
		cout << result[i];

	cout << endl;
}

void task_4_3()
{
	//Текст – непустая последовательность символов.
	//Символы - разделители: «пробел», «.», «,», «:», «;», «!», «?», 
	//«-», «(», «)».
	//Записать в новую строку слова исходной строки, в которых нет одинаковых символов. 

	const int size = 256;
	char str[size], new_str[size] = "";

	cout << "Введите строку:\n";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(str, size);
	
	for (int i = 0, end_word; i < strlen(str); i = end_word + 1)
	{
		if (!same_symbol_check(str, i))
			write_new_word(str, i, new_str);
		do
		{
			end_word = i;
		} while (!separator(str[i++]));
	}

	cout << endl<< new_str << endl;
}

bool same_symbol_check(char *str, int position) 
{
	for(position; !separator(str[position]); position++)
		for(int k = position + 1; !separator(str[k]); k++)
			if(str[position] == str[k])
				return true;
	return false;
}

void write_new_word(char* str, int index, char* new_str)
{
	int i;
	for (i = strlen(new_str); !separator(str[index]); i++, index++)
		new_str[i] = str[index];
	new_str[i] = ' ';
}

bool separator(char symbol)
{
	if (symbol == ' ' || symbol == '.' || symbol == ',' ||
		symbol == ':' || symbol == ';' || symbol == '!' || symbol == '?' ||
		symbol == '-' || symbol == '(' || symbol == ')' || symbol == '\0')
		return true;
	else return false;
}


