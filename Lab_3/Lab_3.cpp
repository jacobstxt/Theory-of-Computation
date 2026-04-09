#include <iostream>
#include "Sort.h"
#include <windows.h>


void copyArray(int src[], int dest[], int n) {
	for (int i = 0; i < n; i++)
		dest[i] = src[i];
} 

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	int n = 0;

	std::cout << "Введіть кількість елементів :";
	std::cin >> n;

	if (n <= 0) {
		std::cout << "Некоректне число" << std::endl;
		return 1;
	}

	int* A = new int[n];
	int* backup = new int[n];

	std::cout << "Введіть елементи :" << std::endl;
	for (int i = 0; i < n; i++) {
		if (!(std::cin >> A[i])) {
			std::cout << "Помилка: введіть число!" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			--i;
		}
	}

	copyArray(A, backup, n);


	std::cout << "Масив перед сортуванням:" << std::endl;
	show(A, n);

	std::cout << "Масив після сортування:" << std::endl;
	RadixSort(A, n, true, 10,true);
	show(A, n);


	copyArray(backup, A, n);


	RadixSort(A, n, true,10, false);
	std::cout << "\n3.1 Результат (обернений останній цикл):" << std::endl;
	show(A, n);
	

	copyArray(backup, A, n);


	RadixSort(A, n, false,10, true);

	std::cout << "\n3.2 Результат (розряди від старшого до молодшого):" << std::endl;
	show(A, n);
	
	delete[] A;
	delete[] backup;
}