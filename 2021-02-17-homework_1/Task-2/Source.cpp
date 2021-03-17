#include<iostream>

using namespace std;

double average(int n, int& arr)
{
	double ans = 0;
	int qua = n;
	for (int* ptr = &arr; n > 0; n--)
	{
		ans += *(ptr);
		++ptr;
	}
	return ans / qua;
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> *(arr + i);
	}
	cout << average(n, arr[0]) << endl;
	delete[] arr;
	return 0;
}