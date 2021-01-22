#include <iostream>
#include <ctime>
using namespace std;

int** make_matr(int n, int k)
{
	int** matr;
	int i, j;
	matr = new int* [n];
	for (i = 0; i < n; i++)
	{
		matr[i] = new int[n];
		for (j = 0; j < k; j++)
			matr[i][j] = rand() % 10 + 1;
	}
	return matr;
}

void main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int rows, cols;
	cout << "Введите число строк:\n";
	cin >> rows;
	cout << "Введите число столбцов:\n";
	cin >> cols;

	int** mass = make_matr(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << mass[i][j] << '\t';
		}
		cout << "\n";
	}

	cout << "введите номер строки для удаления: ";
	int key;
	cin >> key;

	delete[] mass[key - 1];
	
	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i >= key - 1)
			{
				mass[i][j] = mass[i + 1][j];
			}
		}
	}

	cout << "Результат: \n";
	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << mass[i][j] << '\t';
		}
		cout << "\n";
	}

	delete mass;
}
