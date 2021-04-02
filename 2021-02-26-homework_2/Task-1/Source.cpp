#include<iostream>
#include<string>

using namespace std;

template<typename T1, typename T2>
T1 sum(T1 a, T2 b)
{
	return a + b;
}

template<typename T1, typename T2>
T1 diff(T1 a, T2 b)
{
	return a - b;
}

template<typename T1, typename T2>
T1 mult(T1 a, T2 b)
{
	return a * b;
}

template<typename T1, typename T2>
T1 div(T1 a, T2 b)
{
	if (b != 0)
	{
		return a / b;
	}
	else
	{
		return -1;
	}
}

template<typename T1, typename T2>
T1 mod(T1 a, T2 b)
{
	if (b != 0)
	{
		return a % b;
	}
	else
	{
		return -1;
	}
}

int operationIndex(char operation)
{
	switch (operation)
	{
	case '+':return 0;
	case '-':return 1;
	case '*':return 2;
	case '/':return 3;
	case '%':return 4;
	}
	return 0;
}
 
template<typename T1, typename T2>
T1 calculate(T1 a, T2 b, char operation)
{
	T1(*operations[5])(T1, T2) { sum, diff, mult, div, mod };
	return operations[operationIndex(operation)](a, b);
}

int transformint(string s)
{
	int x = 0;
	if (s[0] == '0')
	{
		return x;
	}
	for (int i = 0, j = 1; i < s.size(); i++, j*=10)
	{
		if (s[0] == '-')
		{
			for (int i = 0, j = 1; i < s.size() - 1; i++, j *= 10)
			{
				x += j * (s[s.size() - 1 - i] - '0');
			}
			x *= -1;
			return x;
		}
		x += j * (s[s.size() - 1 - i] - '0');
	}
	return x;
}

//Пример работы :
//       0         1     2     3       4     5      6             
//mycalc.exe --operand1 45 --operand2 8 --operator %
//45 % 8 = 5

int main(int argc, char* argv[])
{
	string operd1;
	string operd2;
	string operr;
	int x1 = 0;
	int x2 = 0;
    char t = 0;
	string s1 = "/0";
	s1 = argv[1];
	string s2 = "/0";
	s2 = argv[2];
	string s3 = "/0";
	s3 = argv[3];
	string s4 = "/0";
	s4 = argv[4];
	string s5 = "/0";
	s5 = argv[5];
	string s6 = "/0";
	s6 = argv[6];
	if (s1 == "--operand1")
	{
		x1 = transformint(s2);
		if (s3 == "--operand2")
		{
			x2 = transformint(s4);
			t = *(argv[6]);
		}
		else
		{
			x2 = transformint(s6);
			t = *(argv[4]);
		}
	}
	else if (s1 == "--operand2")
	{
		x2 = transformint(s2);
		if (s3 == "--operand1")
		{
			x1 = transformint(s4);
			t = *(argv[6]);
		}
		else
		{
			x1 = transformint(s6);
			t = *(argv[4]);
		}
	}
	else if (s1 == "--operator")
	{
		t = *(argv[2]);
		if (s3 == "--operand2")
		{
			x2 = transformint(s4);
			x1 = transformint(s6);
		}
		else
		{
			x2 = transformint(s6);
			x1 = transformint(s4);
		}
	}
	cout << calculate(x1, x2, t);
	system("pause>nul");
	return 0;
}