// Lab_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

	std::cout << "Enter the number of elements: ";
	std::cin >> n;

	if (n <= 0) {
		std::cout << "Invalid number of elements. Exiting." << std::endl;
		return 1;
	}


	int* A = new int[n];

	std::cout << "Enter the elements: " << std::endl;
	for (int i = 0; i < n; i++) {
		if (!(std::cin >> A[i])) {
			std::cout << "Помилка: введіть число!" << std::endl;
			std::cin.clear(); 
			std::cin.ignore(10000, '\n'); 
			--i; 
		}
	}

	std::cout << "Array before sorting: " << std::endl;
	show(A, n);


	std::cout << "Array after merge sorting: " << std::endl;
	MergeSort(A, 0, n - 1);
	show(A, n);


	delete[] A;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
