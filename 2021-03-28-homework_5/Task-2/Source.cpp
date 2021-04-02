#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//Дан текстовый файл.Заменить в нем все гласные буквы на #.Работать с файлом как с бинарным.
/*считаю из файла в массив, в масииве заменю на решетку, сотру все из файла, запишу в файл новый измененый массив*/
int main()
{
	int n = 0;
	cout << "n = ";
	cin >> n;
	int t = n * sizeof(char);
	n++;
	cout << endl;
	char* a = new char[n] {' '};

    fstream fbin;
	//считывание
	fbin.open("in.txt", ios::binary | ios::in);
	if (!fbin)
	{
		cout << "NO OPEN" << endl;
	}
	fbin.read(a, t);
	fbin.close();

	//проходимся по массиву а
	for (int i = 0; i < n; i++)
	{
		if ((a[i] == 'a' || a[i] == 'e' || a[i] == 'o'|| a[i] == 'y' || a[i] == 'i' || a[i] == 'u')||
			(a[i] == 'A' || a[i] == 'E' || a[i] == 'O' || a[i] == 'Y' || a[i] == 'I' || a[i] == 'U'))
		{
			a[i] = '#';
		}
	}
	

	//очистка
	fbin.open("in.txt", std::ofstream::out | std::ofstream::trunc);
	fbin.close();

	//запись
	fbin.open("in.txt", ios::binary | ios::out);
	if (!fbin)
	{
		cout << "NO OPEN" << endl;
	}
	fbin.write(a, t);
	fbin.close();

	return 0;
}