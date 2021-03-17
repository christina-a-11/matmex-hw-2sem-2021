#include <iostream>

using namespace std;

void printBits(int x)
{
	int bitlength = sizeof(x) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned int bit = x;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
}
void printBits(long x)
{
	int bitlength = sizeof(x) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned long bit = x;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
}
void printBits(long long x)
{
	int bitlength = sizeof(x) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned long long bit = x;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
}
void printBits(float x)
{
	printBits((int)(x));
	x = x - (int)x;
	for (int i = 0; i <= sizeof(float) * 8 - 8 - 1; i++)
	{
		x = x * 2;
		cout << (int)x;
		x = x - (int)x;
	}
}
void printBits(double x)
{
	printBits((int)(x));
	x = x - (int)x;
	for (int i = 0; i <= sizeof(double) * 8 - 8 -1; i++)
	{
		x = x * 2;
		cout << (int)x;
		x = x - (int)x;
	}
}
void printBits(long double x)
{
	printBits((int)(x));
	x = x - (int)x;
	for (int i = 0; i <= sizeof(long double) * 8 - 8 - 1; i++)
	{
		x = x * 2;
		cout << (int)x;
		x = x - (int)x;
	}
}

int main()
{
	printBits((int)(-15));
	cout << endl;
	printBits((long long)(27));
	cout << endl;
	printBits((long long)(-27));
	cout << endl;
	printBits((double)1.1);

	system("pause>nul");
	return 0;
}