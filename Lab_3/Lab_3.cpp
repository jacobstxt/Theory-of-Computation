#include <iostream>
#include "Sort.h"
#include <windows.h>

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

	std::cout << "Введіть елементи :" << std::endl;
	for (int i = 0; i < n; i++) {
		if (!(std::cin >> A[i])) {
			std::cout << "Помилка: введіть число!" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			--i;
		}
	}

	std::cout << "Масив перед сортуванням:" << std::endl;
	show(A, n);

	std::cout << "Масив після сортування:" << std::endl;
	//
	CountingSort(A, n, 0, n);
	//
	show(A, n);
}