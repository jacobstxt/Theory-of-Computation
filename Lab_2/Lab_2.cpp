#include <iostream>
#include "Sort.h"
#include <windows.h>
#include <ctime>

int main()
{
	srand(static_cast<unsigned int>(time(0)));
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
	int* B = new int[n];

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
	QuickSort(A, 0, n - 1);
	show(A, n);


	int i_stat;    
	std::cout << "\nВведіть номер порядкової статистики (1..." << n << "): ";
	std::cin >> i_stat;
	int result = RandomizedSelect(A, 0, n - 1, i_stat);
	std::cout << i_stat << "-та порядкова статистика: " << result << "\n";


	int min = RandomizedSelect(A, 0, n - 1, 1);  
	std::cout << "Мінімальне значення: " << min << "\n";

	int max = RandomizedSelect(A, 0, n - 1, n);   
	std::cout << "Максимальне значення: " << max << "\n";

	if (n % 2 == 1)
	{
		int median = RandomizedSelect(A, 0, n - 1, (n + 1) / 2);
		std::cout << "Медіана: " << median << "\n";
	}
	else
	{
		int m1 = RandomizedSelect(A, 0, n - 1, n / 2);
		int m2 = RandomizedSelect(A, 0, n - 1, n / 2 + 1);
		std::cout << "Медіани: " << m1 << " і " << m2 << "\n";
	}


	
	delete[] A;
	delete[] B;
}

