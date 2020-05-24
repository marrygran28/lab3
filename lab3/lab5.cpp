#include "lab5.h"

#define R 3 
#define C 6 
void task_5_1()
{
	const int MAX = 102; 
	int n;
	cin >> n;

	int matrix[MAX][MAX] = { 0 };
	
}

///////////////////////////////////////////////////////////////////////////

void task_5_2()
{
	//Íàïèñàòü ôóíêöèþ óäàëåíèÿ n ñèìâîëîâ ñ óêàçàííîé ïîçèöèè èç
	//ñòðîêè S. Èñïîëüçóÿ ýòó ôóíêöèþ, óäàëèòü èç çàäàííîé ñòðîêè òåêñò
	//çàêëþ÷åííûé â “”.
	const int size = 256;
	char s[size];
	unsigned int n = 0, position;

	cout << "Ââåäèòå ñòðîêó, ñîäåðæàùóþ “ ” " << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(s, size);

	int start_position = 0;
	while (start_position < strlen(s))
	{
		position = quotes_check(s, start_position);
		n = number_check(s, position);
		strndelete(s, n, position);	
		start_position += n + 1;
	}
	cout << endl << s << endl;
}

unsigned int quotes_check(char* str, int start_position)	//âîçâðàùàåò ïîçèöèþ ïåðâîé êàâû÷êè â ñòðîêå
{
	for (int i = start_position; i < strlen(str); i++)
		if (str[i] == '\"') return i;
	return INT_MAX;
}
unsigned int number_check(char *str, unsigned position)	//âîçâðàùàåò êîëè÷åñòâî ñèìâîëîâ â êàâû÷êàõ
{
	unsigned int number = 0;
	for (int i = position + 1; i < strlen(str); i++, number++)
		if (str[i] == '\"') return number;
	return 0;
}
char* strndelete(char* str, unsigned int number, unsigned int position)
{
	if (number >= strlen(str) - position)
		while (number)
		{
			str[position++] = '\0';
			number--;
		}
	if (number == 0) return str;

	int i = position + 1;
	int j = position + number + 1;
	while (str[j] != '\0')
		str[i++] = str[j++];
	str[i] = '\0';
		
	return str;
}

////////////////////////////////////////////////////////////////////////////////

void task_5_3()
{
	//10. В предложении все слова начинаются с различных букв. Получить текст
	//(если можно), в котором слова предложения расположены в таком порядке,
	//чтобы последняя буква каждого слова совпадала с первой буквой следующего слова.

	char str[256];
	cin.ignore(cin.rdbuf()->in_avail());
	cin.get(str, 256);
	string str1 = str;
	int k = 0;
	for (unsigned int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ') k++;
	}

	char *words[256];

	k = 0;
	for (unsigned int i = 0; i < strlen(str); i++)
	{
		if (str1[i] == ' ') k++;
		else words[k] = words[k] + str[i];
	}
	int n = 0;
	char con[256];
	*con = *words[0];
	for (int i = 0; i <= k; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (con[(strlen(con) - 1)] == words[j][0])
			{
				con = con + " " + words[j];
				n++;
				words[j] = "0";
			}
			if (n > 0) break;
		}
		if (n == 0 && words[i] != "0")
			con = con + " " + words[i];
		n = 0;
	}
	cout << endl;
	cout << con << endl;
	return;
}
