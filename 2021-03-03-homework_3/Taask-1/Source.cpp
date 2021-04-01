#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool isNumb(string s, int& index);
bool isMant(string s, int& index);
bool isStep(string s, int& index);
bool isunsigInteger(string s, int& index);
bool isdigits(char x);
bool issign(char a);

using namespace std;

int main()
{
	string str;

	ifstream fin("in.txt");
	if (fin.is_open())
	{
		getline(fin, str);
	}
	fin.close();

	bool flag = false;
	int index = 0;
	flag = isNumb(str, index);
	cout << (flag == true ? "yes" : "no");
	system("pause>nul"); 
	return 0;
}
/*Понятие вещественное число определено следующим образом:
<вещественное число>
::= <мантисса> <порядок> |<знак> <мантисса> <порядок>
<мантисса> ::= <целое без знака> . <целое без знака>
<порядок> ::= E <целое без знака> |
E <знак> <целое без знака>
<целое без знака> ::= <цифра> | <цифра> <целое без знака>
<цифра> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 |7 | 8 | 9
<знак> ::= + | -
*/
bool isNumb(string s, int& index)
{
	if (issign(s[index]))
	{
		index++;
	}
	bool flag = isMant(s, index);
	flag = flag * isStep(s, index);
	return flag;
}

bool isMant(string s, int& index)
{
	bool flag = false;
    flag =	isunsigInteger(s, index);
	
	if (s[index] == '.' && index > 0 && index < s.size())
	{
		index++;
		flag = flag * isunsigInteger(s, index);
	}
	else
	{
		flag = false;
	}
	return flag;
}

bool isStep(string s, int& index)
{
	if (s[index] == 'E')
	{
		index++;
	}
	else
	{
		return false;
	}
	if (issign(s[index]))
	{
		index++;
		return isunsigInteger(s, index);
	}
	else
	{
		return isunsigInteger(s, index);
	}
}

bool isunsigInteger(string s, int& index)
{
	if (isdigit(s[index]))
	{
		while (isdigits(s[index]))
		{
			index++;
		}
		return true;
	}
	return false;
}

bool isdigits(char x)
{
	return (x >= '0' && x <= '9');
}

bool issign(char a)
{
	return (a == '-' || a == '+');
}
