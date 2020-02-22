#include "lab3.h"

void input_menu()
{
	cout << "Выберите способ инициализации массива" << endl
		<< "1 - инициализация при описании" << endl
		<< "2 - генерация произвольных значений" << endl
		<< "3 - ввод значений\n" << endl
		<< "ВАШ ВЫБОР:\t";
}

void task_3_1()
{
	// Дан массив целых чисел, содержащий n элементов. 
	// Для тестирования предусмотреть возможность задавать элементы массива различным образом: 
	//при описании с инициализацией, присвоением значений (в том числе случайных), или вводом необходимых значений.

	//10.	Найти максимальную по длине монотонную (неубывающую или невозраста-ющую) подпоследовательность 
	//подряд идущих элементов заданной последова-тельности целых чисел

	int option;
	cout << "Введите размерность массива [1-15]\t";
	int n = valid_input_int(n = 0);
	int a[15] = { 1, 2, 3, 4, 6, 5, 4, 3, 0, 0, 6, 3, 1, 1, 1 };
	cout << "Выберите способ инициализации массива" << endl
		<< "1 - инициализация при описании" << endl
		<< "2 - генерация произвольных значений" << endl
		<< "3 - ввод значений\n" << endl
		<< "ВАШ ВЫБОР:\t";
	option = valid_input_option(option = 0);
	

	switch (option)
	{
	case 1:
	{
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << endl;
		break;
	}
	case 2:
	{
		for (int i = 0; i < n; i++)
		{
			a[i] = rand() % 15 - 10;
			cout << a[i] << " ";
		}
		cout << endl;
		break;
	}
	case 3:
	{
		for (int i = 0; i < n; i++)
			a[i] = valid_input(a[i] = 0);
		cout << endl;
		break;
	}
	default: break;
}
	cout << endl;

//---------------------------------------------------------//

	int ind,	//индекс последнего элемента монотонной подпоследовательности(м.п.)
		counter, //количество элементов в рассматриваемой м.п.
		max_ind = 0, //индекс последнего элемента в максимальной по длинне м.п.
		max_counter = 0;	//количество элементов в максимальной по длинне м.п.

	//поиск неубывающих п-стей
	for (ind = 0; ind < n; ind++)
	{
		counter = 0;
		int k = ind;
		while (a[k] <= a[k + 1] && k + 1 < n)
		{
			counter++;
			k++;
			ind = k;
		}
		if (max_counter < counter)
		{
			max_counter = counter;
			max_ind = ind;
		}
	}

	//поиск невозрастающих п-стей
	for (ind = 0; ind < n; ind++)
	{
		counter = 0;
		int k = ind;
		while (a[k] >= a[k + 1] && k + 1 <= n)
		{
			counter++;
			k++;
			ind = k;
		}

		if (max_counter < counter)
		{
			max_counter = counter;
			max_ind = ind;
		}
	}

	//вывод подпоследовательности
	for (int k = max_ind - max_counter; k <= max_ind; k++)
		cout << a[k] << " ";
	cout << endl;
}

int valid_input_option(int num)
{
	while (true)
	{
		cin >> num;
		if (cin && num == 1 || num == 2 || num == 3) return num;
		fflush(stdin);
		cout << "Неверное значение. Повторите ввод.\n";
	}
}

int valid_input(int num)
{
	while (true)
	{
		cin >> num;
		if (cin) return num;
		cin.clear();
		rewind(stdin);
		cout << "Неверное значение. Повторите ввод.\n";
	}
}

int valid_input_int(int num)
{
	while (true)
	{
		cin >> num;
		if (cin && num > 0) return num;
		rewind(stdin);
		cout << "Неверное значение. Повторите ввод.\n";
	}
}

void task_3_2()
{
	//По матрице A построить матрицу B того же размера, где элемент b ij
	//определяется следующим образом.Через a ij проведем в A линии, параллельные
	//сторонам прямоугольника до пересечения с побочной диагональю; b ij
	//определяется как максимум среди элементов треугольника в А.

	int option;
	cout << "Введите размерность массива [1-15]\t";
	int n = valid_input_int(n = 0);
	int  b[15][15], a[15][15] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
				      {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
					  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4}, 
					  {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},
				      {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
					  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
					  {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
					  {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
					  {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
					  {11,11,11,11,11,11,11,11,11,11,11,11,11,11,11},
					  {12,12,12,12,12,12,12,12,12,12,12,12,12,12,12},
					  {13,13,13,13,13,13,13,13,13,13,13,13,13,13,13},
					  {14,14,14,14,14,14,14,14,14,14,14,14,14,14,14} };
	cout << "Выберите способ инициализации массива" << endl
		<< "1 - инициализация при описании" << endl
		<< "2 - генерация произвольных значений" << endl
		<< "3 - ввод значений\n" << endl
		<< "ВАШ ВЫБОР:\t";
	option = valid_input_option(option = 0);


	switch (option)
	{
	case 1:
	{
		break;
	}
	case 2:
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = rand() % 15 -5;
			}
			cout << endl;
		}
		cout << endl;
		break;
	}
	case 3:
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = valid_input(a[i][j] = 0);
			}
		}
		cout << endl;
		break;
	}
	default: break;
	}
	system("CLS");
	//output
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(3) << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	int max; //максимальный элемент в треугольнике
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= n - i - 1; j++)
		{			
			max = a[i][j];
			for (int k = i; k <= n - j - 1; k++)
				for (int m = j; m <= n - k - 1; m++)
				{
					if (a[k][m] > max)
						max = a[k][m];
				}
			b[i][j] = max;
		}

	for (int i = n; i > 0; i--)
		for (int j = n; j >= n - i - 1; j--)
		{
			max = a[i][j];
			for (int k = i; k >= n - j - 1; k--)
				for (int m = j; m >= n - k - 1; m--)
				{
					if (a[k][m] > max)
						max = a[k][m];
				}
			b[i][j] = max;
		}
				
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(3) << b[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

const int s = 100;  //1.5e9;
bool max[s];

void task_3_3()
{
	//Выполнить задания 2.3, используя алгоритм «решето Эратосфена» для
	//нахождения простых чисел.Найти максимальное простое число, которое
	//возможно определить по этому алгоритму в данной системе программирования.

	//Найти все четырехзначные сверхпростые числа.

	const unsigned int M = 10000, m = 1000;
	const unsigned int SIZE = M + 1;
	UINT_MAX;
	bool arr[M];	
	unsigned int n, i, j, k;

	for (i = 2; i < M; i++)
		arr[i] = 1;
	
	n = sqrt(double(M));
	int _i;

	//обнуление составных чисел
	for (i = 2; i <= n; i++)
		if (arr[i])
			for (j = i; j < M; j+=1)
			{
				if (i*j >= M) break;
				arr[i*j] = 0;
			}

	//обнуление простых чисел, не являющихся суперпростыми
	for (i = 1000; i < SIZE/2; i++)
		if (arr[i]) 
		{
			_i = inverse(i);
			for (k = 2; k < sqrt(_i) + 1; k++)
				if (_i%k == 0)
					arr[i] = 0;
		}

	//вывод
	int count = 0;	//счетчик сверхпростых чисел
	for (i = m; i < M/2; i++)
		if (arr[i])
		{
			cout << i << '\t' << inverse(i) << endl; // вывод простых чисел
			count++;
		}
	
	cout << endl<< "AMOUNT = " << count << endl;
	cout << endl;

//////////////////////////////////////////////////////////////
	int num, _num, a, b, c, d;
	int flag = 0;	//если 0 - число простое, 1 - составное

	count = 0;
	for (int num = 1001; num <= 5000; num += 2)
	{
		d = num % 10;
		c = num / 10 % 10;
		b = num / 100 % 10;
		a = num / 1000;
		_num = a + 10 * b + 100 * c + 1000 * d;

		flag = 0;
		for (int div = 2; div < sqrt(num) + 1; div++)
		{
			if (num % div == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag) continue;

		for (int div = 2; div < sqrt(_num) + 1; div++)
		{
			if (_num % div == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag) continue;

		cout << num << '\t' << _num << endl;
		count++;
	}
	cout << endl << "AMOUNT = " << count << endl;



//////////////////////////////////////////////////////////////
	//поиск максимального
	n = sqrt(double(s));

	for (i = 2; i < s; i++)
		max[i] = 1;

	cout << endl << "Идет вычисление СБПЧ..." << endl;
	for (i = 2; i <= n; i++)
	{
		if (max[i])
			for (j = i; j < s; j++)
			{
				if (i*j >= s) break;
				max[i*j] = 0;
			}
	}

	//1499999957
	for (i = s-100; i < s; i++)
		if (max[i])
			cout << i << ' ';
}

int inverse(int num) 
{
	int _num = 0;
	for (; num >= 1; num /= 10)
	{
		_num = _num * 10 + num % 10;
	}
	return _num;
}

void task_3_4()
{
	//Дана действительная матрица порядка n × m. Перебор строк/столбцов
	//матрицы осуществить с использованием указателей.

	//Упорядочить строки по убыванию наименьших элементов.

	cout << "Введите количество строк[1-15]\t";
	int n = valid_input_int(n = 0);
	cout << "Введите количество столбцов[1-15]\t";
	int m = valid_input_int(m = 0);

	input_menu();
	int option = valid_input_option(option = 0);

	int min[15], a[15][15];
	
	//initialization
	switch (option)
	{
	case 1:
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = i;
		break;
	}
	case 2:
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				a[i][j] = rand() % 15 - 5;
			cout << endl;
		}
		cout << endl;
		break;
	}
	case 3:
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = valid_input(a[i][j] = 0);
		cout << endl;
		break;
	}
	default: break;
	}
	system("CLS");

	for (int i = 0; i < n; i++)
		*(min + i) = **(a + i);

	//min's search
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (*(min + i) > *(*(a + i) + j))
				*(min + i) = *(*(a + i) + j);

	//output A
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(3) << *(*(a + i) + j) << ' ';
		cout << '\t' << min[i] << endl;
	}
	cout << endl;

	//sort
	for (int i = 1; i < n; i++)  
			for (int k = 1; k < n; k++)
				for (int l = i; l > 0 && *(min + l - 1) < *(min + l); l--)
				{
					for (int j = 0; j < m; j++)
						swap(*(*(a + l) + j), *(*(a + l - 1) + j));
					swap(*(min + l - 1), *(min + l));
				}
	
	//output B
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(3) << *(*(a + i) + j) << ' ';
		cout << '\t' << min[i] <<  endl;
	}
	cout << endl;
}

void task_3_5()
{
	//Построить матрицу В такого же размера, как А, элементы которой
	//обладают следующим свойством : элемент В[i, j] равен минимальному из
	//элементов матрицы А, расположенных ниже диагонали, параллельной главной,
	//пересекающей этот элемент, не включая саму диагональ.

	const int max = 100;
	int A[max][max] = { 0 }, B[max][max] = { 0 };

	int option;

	cout << "Введите количество строк[1-15]\t";
	int n = valid_input_int(n = 0);
	cout << "Введите количество столбцов[1-15]\t";
	int m = valid_input_int(m = 0);

	cout << "Выберите способ инициализации массива" << endl
		<< "1 - инициализация при описании" << endl
		<< "2 - генерация произвольных значений" << endl
		<< "3 - ввод значений\n" << endl
		<< "ВАШ ВЫБОР:\t";
	option = valid_input_option(option = 0);

	//initialization
	switch (option)
	{
	case 1: {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				A[i][j] = i;
		break; 
	}
	case 2:
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				A[i][j] = rand() % 15 - 5;
		break;
	}
	case 3:
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				A[i][j] = valid_input(A[i][j] = 0);
		cout << endl;
		break;
	}
	default: break;
	}

	//output A
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(3) << A[i][j];
		cout << endl;
	}

	cout << endl;	

	//int min;
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		min = A[n - 1][0];
	//		if (i < j)	//верхняя часть матрицы	
	//		{
	//			for (int l, k = 0; k < n; k++)
	//			{
	//				l = j + k - 1;
	//				do
	//				{
	//					if (min > A[k][l])
	//						min = A[k][l];
	//					l--;
	//				} while (l > 0);
	//			}
	//			B[i][j] = min;
	//		}
	//		else //нижняя часть матрицы + г.д.
	//		{
	//			for (int l, k = n - 1; k > abs(i-j); k--)
	//			{
	//				l = m - 2 - abs(i - j);
	//				do
	//				{
	//					if (min > A[k][l])
	//						min = A[k][l];
	//					l--;
	//				} while (l > 0);
	//			}
	//			B[i][j] = min;
	//		}
	//		cout << setw(3) << B[i][j];
	//	}
	//cout << endl;
	//}

	int min, i;
	for (i = n - 1, min = A[i][0], B[i][0] = A[i][0]; i >= 0; i--)
		for (int j = 0; j < m; j++)
		{
			if(i < n - 1) min = B[i + 1][j];
			if (i == n - 1 && j == 0) continue;
			if (i >= j)	//нижняя часть матрицы + г.д.	
			{
				for (int l = 1, k = n - 1; l > 0; k--)
				{
					l = k - abs(i - j) - 1;
					if (min > A[k][l])
						min = A[k][l];
				}
				B[i][j] = min;
			}
			else //верхняя часть матрицы
			{
				for (int l = 0, k = 0; l < n; k++)
				{
					l = abs(i - j) + k - 1;
					if (min > A[k][l])
						min = A[k][l];
				}
				B[i][j] = min;
			}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(3) << B[i][j];
		cout << endl;
	}
}

void task_3_6()
{
	//Вводится натуральное число N. Найти количество 3 в числе N!.
	int number; //num >= 100
	

	cout << endl << "Enter natural number (number <= 25000)" << endl;
	number = valid_input(number = 0);

	if (number > 25000)
	{
		cout << "Слишком большое число\n Выход из программы\n";
		return;
	}

	const int SIZE = 1e5;
	int fact[SIZE] = { 0 }, c = 0;

	if (number == 0) {
		cout << "0" << endl;
		return;
	}
	
	fact[SIZE - 1] = 1;
	int k;
	for (int i = 1; i <= number; i++) 
	{

		for (int j = SIZE - 1; j >= 0; j--) 
		{
			fact[j] = fact[j] * i + c;
			c = fact[j] / 10;
			fact[j] %= 10;
		}

		if (c > 0) 
		{
			for (int l = 0; l < SIZE; l++) 
			{
				if (fact[l] != 0) 
				{
					k = l;
					break;
				}
			}
			while (c > 0) 
			{
				k--;
				fact[k] = c % 10;
				c = c / 10;
			}
		}

	}

	int i, j;
	for (i = 0; i < SIZE; i++)
		if (fact[i] != 0) break;

	int counter = 0;
	cout << endl << number << "! = ";
	for (j = i; j < SIZE; ++j)
	{
		if (fact[j] == 3)
			counter++;
		cout << fact[j];
	}

	
	cout << endl << counter  << " " << SIZE - i << endl;
}



void task_3_7()
{
	//Заданы две целочисленные симметричные матрицы А и B. Найти матрицу С = A*B.
	const int size = 120;
	cout << "Введите размерность матриц [1-15]\t";
	int n = valid_input_int(n = 0);
	int  a[size], b[size];
	
	for (int i = 0; i < (n+1)*n/2; i++)
	{
		a[i] = rand() % 10;
		cout << endl;
	}

	for (int i = 0; i < (n+1)*n/2; i++)
	{
		b[i] = rand() % 15;
		cout << endl;
	}

	cout << endl;

	//for(int i = 0; i < n;)

	//output
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
				cout << setw(3) << a[i] << ' ';
			cout << endl;
		}
	cout << endl;
}



