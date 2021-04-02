#include <iostream>
using namespace std;
//Реализовать сортировку подсчетом.
//Реализовать быструю сортировку.
//Реализовать слияние двух отсортированных массивов в один отсортированный.

void sortCount(int* arr, int n)
{
	int a[1000]{ 0 };
	for (int i = 0; i < n; i++)
	{
		a[arr[i]] += 1;
	}
	for (int i = 0, j = 0; i < 1000; i++)
	{
		while (a[i] != 0)
		{
			arr[j] = i;
			j++;
			a[i]--;
		}
	}
}

void sortFast(int* arr, int n, int b, int e)
{
		int l = b, r = e;
		int piv = arr[(l + r) / 2];
		while (l <= r)
		{
			while (arr[l] < piv)
			{
				l++;
			}
			while (arr[r] > piv)
			{
				r--;
			}
			if (l <= r)
			{
				swap(arr[l++], arr[r--]);
			}
		}
		if (b < r)
		{
			sortFast(arr, n, b, r);
		}
		if (e > l)
		{
			sortFast(arr, n, l, e);
		}
}

int* merge(int* a, int* b, int x, int y)
{    // первый массив не короче второго
	if (x < y)
	{
		int* temp = a;
		a = b;
		b = temp;
		int tmp = x;
		x = y;
		y = tmp;
	}
	int* c = new int[x + y]{ 0 };
	for (int i = 0, k = 0, l = 0; i < x + y; i++)
	{
		if (a[k] < b[l])
		{
			c[i] = a[k];
			k++;
		}
		else
		{
			c[i] = b[l];
			l++;
		}
		if (k > x)
		{
			for (int j = i; j < x + y; j++, i++)
			{
				c[j] = b[l];
				l++;
            }
		}
		else if (l > y)
		{
			for (int j = i; j < x + y; j++, i++)
			{
				c[j] = a[k];
				k++;
			}
		}
	}

	return c;
}

void init(int* arr, int n)
{
	//srand(8);
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 1000;
	}
}

void print(int* arr, int n)
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

int main()
{
	int n = 0;
	cin >> n;
	int* arr1 = new int[n];
	init(arr1, n);
	cout << "arr1 : ";
	print(arr1, n);
	cout << endl;
	sortCount(arr1, n);
	cout << "arr1 : ";
	print(arr1, n);
    //
	int m = 0;
	cin >> m;
	int* arr2 = new int[m];
	init(arr2, m);
	cout << "arr2 : ";
	print(arr2, m);
	cout << endl;
	sortFast(arr2, m, 0, m - 1);
	cout << "arr2 : ";
	print(arr2, m);
	//
	int* c = merge(arr1, arr2, n, m);
	cout << "arr1 + arr2 : ";
	print(c, n + m);
	delete[] arr1;
	delete[] arr2;
	delete[] c;
system("pause>nul");
return 0;
}