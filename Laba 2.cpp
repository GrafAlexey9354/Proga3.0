// ConsoleApplication533.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


	
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <chrono>

using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	const int n = 100;
	int min, max, a, b, H;
	short A[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 199 - 99;
		cout << A[i] << " "; //- вывод неотсортированного масива
	}
	cin.sync();
	system("pause");

	// Нахождение минимального и максимального зачения массива
	auto start1 = chrono::high_resolution_clock::now();
	max = A[0];
	min = A[0];
	for (int i = 0; i < n; ++i)
	{
		if (max < A[i]) max = A[i];
		if (min > A[i]) min = A[i];
	}
	cout << "\n\nМинимальное значение = " << min << endl;
	cout << "Максимальное значение = " << max << endl;
	cout << endl;
	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<float> duration1 = end1 - start1;
	cout << "Время на поиск макс и мин значений: " << duration1.count() << "s" << endl;

	system("pause");
	// bubble sort пузырьковая сортировка массива
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < n - (i + 1); j++) { //уменьшать отрезок внутреннего цикла на 1, после каждого полного прохода внешнего цикла
			if (A[j] > A[j + 1]) {
				flag = false;
				swap(A[j], A[j + 1]);
			}
		}
		if (flag) {
			break;
		}
	}
	cout << "\n\n\n";
	for (int i = 0; i < n; i++) {
		cout << A[i] << " "; // вывод отсортированного массива методом bubble sort
	}
	cout << "\n\n\n";
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << "Время на сортировку bubble sort: " << duration.count() << "s" << endl;
	system("pause");
	
	// shaker-sort сортировка
	auto start0 = chrono::high_resolution_clock::now();
	bool sort_or_not = true;
	int right = n - 1; // n - размер массива
	int left = 1;
	do {
		bool sort_or_not = true;
		for (int i = left; i <= right; i++) {
			if (A[i - 1] > A[i]) {
				swap(A[i - 1], A[i]);
				sort_or_not = false;
			}
		}
		right--;
		for (int i = right; i >= left; i--) {
			if (A[i] < A[i - 1]) {
				swap(A[i], A[i - 1]);
				sort_or_not = false;
			}
		}
		left++;
	} while (sort_or_not == false);
	
	cout << "\n\n\n";
	for (int i = 0; i < n; i++) {
		cout << A[i] << " "; // вывод отсортированного массива методом shaker-sort
	}
	cout << "\n\n\n";
	auto end0 = chrono::high_resolution_clock::now();
	chrono::duration<float> duration0 = end0 - start0;
	cout << "Время на сортировку shaker-sort: " << duration0.count() << "s" << endl;
	
	system("pause");
	// Нахождение минимального и максимального зачения массива
	auto start2 = chrono::high_resolution_clock::now();
	max = A[0];
	min = A[0];
	for (int i = 0; i < n; ++i)
	{
		if (max < A[i]) max = A[i];
		if (min > A[i]) min = A[i];
	}
	cout << "\n\nМинимальное значение = " << min << endl;
	cout << "Максимальное значение = " << max << endl;
	cout << endl;
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<float> duration2 = end2 - start2;
	cout << "Время на поиск макс и мин значений: " << duration2.count() << "s" << endl;
	system("pause");

	double num;
	num = (max + min)/n;
	printf("\n\nСреднее значение = %.2lf ", num);
	system("pause");

	cin >> a;
	cout << "номера элементов масива, которые меньше заданого числа: ";
	for (int i = 0; i < n; ++i) {
		if (A[i] < a)
		cout << A[i] << " ";
	}	
	system("pause");

	cin >> b;
	cout << "номера элементов масива, которые больше заданого числа: ";
	for (int i = 0; i < n; ++i) {
		if (A[i] > b)
		cout << A[i] << " ";
	}
	system("pause");
	return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
