#include <iostream>

using namespace std;
void iip(int n, int* arr);
void iim(int n, int* arr);
void ii(int n, int* arr, int x )
{
	if (x == 2)
	{
		return iip(n, arr);
	}
	if (x == 3)
	{
		return iim(n, arr);
	}
	srand(8);
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 1000;
    }
}

void iip(int n, int* arr)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = i;
	}
}

void iim(int n, int* arr)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = n - i;
	}
}

void print(int n, int* arr)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i);
		if (i != n - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
}

void bubbleSort(int n, int* a, int* comp, int* perm)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			*comp = *comp + 1;
			if (a[j] > a[j + 1])
			{
				*perm = *perm + 1;
				auto t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

void insertionSort(int n, int* a, int* comp = 0, int* perm = 0)
{
	for (int i = 1; i < n; ++i)
	{
		int t = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > t)
		{
			*comp = *comp + 1;
			*perm = *perm + 1;
			a[j] = a[j - 1];
			--j;
		}
		*perm = *perm + 1;
		a[j] = t;
		
	}
}

void selectionSort(int n, int* a, int* comp = 0, int* perm = 0)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int index = i;
		for (int j = i + 1; j < n; ++j)
		{
			*comp = *comp + 1;
			if (a[j] < a[index])
			{
				index = j;
			}
		}
		*perm = *perm + 1;
		auto t = a[i];
		a[i] = a[index];
		a[index] = t;
	}
}

void check(int n, int* a, int x)
{
	int comp1 = 0;
	int comp2 = 0;
	int comp3 = 0;
	int perm1 = 0;
	int perm2 = 0;
	int perm3 = 0;
	for (int i = 0; i < 1000; i++)
	{
		ii(n, a, x);
		//
		bubbleSort(n, a, &comp1, &perm1);
		insertionSort(n, a, &comp2, &perm2);
		selectionSort(n, a, &comp3, &perm3);
	}
	cout << "bubbleSort : " << endl;
	cout << "comp = " << comp1/n << endl;
	cout << "perm = " << perm1/n << endl;

	cout << endl;

	cout << "insertionSort : " << endl;
	cout << "comp = " << comp2 / n << endl;
	cout << "perm = " << perm2 / n << endl;

	cout << endl;

	cout << "selectionSort : " << endl;
	cout << "comp = " << comp3 / n << endl;
	cout << "perm = " << perm3 / n << endl;

	cout << endl;
}

int main()
{
	int n = 5;
	int* arr = new int[n];
	cout << "CHECK N = 5 " << endl << endl;
	cout << "rand : " << endl;
	check(5, arr, 1);
	cout << endl;
	cout << "plus : " << endl;
	check(5, arr, 2);
	cout << endl;
	cout << "minus : " << endl;
	check(5, arr, 3);
	cout << endl;
	delete[] arr;

	cout << "CHECK N = 10 " << endl  << endl;
	n = 10;
	arr = new int[n];
	cout << "rand : " << endl;
	check(10, arr, 1);
	cout << endl;
	cout << "plus : " << endl;
	check(10, arr, 2);
	cout << endl;
	cout << "minus : " << endl;
	check(10, arr, 3);
	cout << endl;
	delete[] arr;

	cout << "CHECK N = 15 " << endl << endl;
	n = 15;
	arr = new int[n];
	cout << "rand : " << endl;
	check(15, arr, 1);
	cout << endl;
	cout << "plus : " << endl;
	check(15, arr, 2);
	cout << endl;
	cout << "minus : " << endl;
	check(15, arr, 3);
	cout << endl;
	delete[] arr;

	cout << "CHECK N = 20 " << endl << endl;
	n = 20;
	arr = new int[n];
	cout << "srand : " << endl;
	check(20, arr, 1);
	cout << endl;
	cout << "plus : " << endl;
	check(20, arr, 2);
	cout << endl;
	cout << "minus : " << endl;
	check(20, arr, 3);
	cout << endl;
	delete[] arr;
	
	system("pause>null");
	return 0;
}