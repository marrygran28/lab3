#include "lab3.h"
#include "lab4.h"
#include "lab5.h"

//Вариант 10


void main()
{
	setlocale(LC_ALL, "Russian");
	int option;

#define LAB 5

#if LAB == 3
	while (true)
	{
		system("cls");
		cout << "линейные алгоритмы и ветвления:\n"
			<< "0. выход\n"
			<< "1. 3.1\n"
			<< "2. 3.2\n"
			<< "3. 3.3\n"
			<< "4. 3.4\n"
			<< "5. 3.5\n"
			<< "6. 3.6\n"
			<< "7. 3.7\n"
			<< "\nвведите номер задания:\t";

		option = valid_input(option = 0);

		switch (option)
		{
		case 0: return;
		case 1: task_3_1(); break;
		case 2: task_3_2(); break;
		case 3: task_3_3(); break;
		case 4: task_3_4(); break;
		case 5: task_3_5(); break;
		case 6: task_3_6(); break;
		case 7: task_3_7(); break;
		default: cout << "\nнажмите любую клавишу чтобы повторить выполнение программы\n\n";  break;
		}
		system("pause");
	}
#endif

#if LAB == 4
	while (true)
	{
		system("CLS");
		cout << "СТРОКИ:\n"
			<< "0. ВЫХОД\n"
			<< "1. 4.1\n"
			<< "2. 4.2\n"
			<< "3. 4.3\n"
			<< "\nВВЕДИТЕ НОМЕР ЗАДАНИЯ:\t";

		option = valid_input(option = 0);

		switch (option)
		{
		case 0: return;
		case 1: task_4_1(); break;
		case 2: task_4_2(); break;
		case 3: task_4_3(); break;
		default: cout << "\nНажмите любую клавишу чтобы повторить выполнение программы\n\n";  break;
		}
		system("PAUSE");
	}
#endif	
#if LAB == 5
	while (true)
	{
		system("CLS");
		cout << "ФУНКЦИИ:\n"
			<< "0. ВЫХОД\n"
			<< "1. 5.1\n"
			<< "2. 5.2\n"
			<< "3. 5.3\n"
			<< "\nВВЕДИТЕ НОМЕР ЗАДАНИЯ:\t";

		option = valid_input(option = 0);

		switch (option)
		{
		case 0: return;
		case 1: task_5_1(); break;
		case 2: task_5_2(); break;
		case 3: task_5_3(); break;
		default: cout << "\nНажмите любую клавишу чтобы повторить выполнение программы\n\n";  break;
		}
		system("PAUSE");
	}
#endif
}
