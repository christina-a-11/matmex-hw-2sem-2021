#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//��� ��������� ����.�������� � ��� ��� ������� ����� �� #.�������� � ������ ��� � ��������.
/*������ �� ����� � ������, � ������� ������ �� �������, ����� ��� �� �����, ������ � ���� ����� ��������� ������*/
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
	//����������
	fbin.open("in.txt", ios::binary | ios::in);
	if (!fbin)
	{
		cout << "NO OPEN" << endl;
	}
	fbin.read(a, t);
	fbin.close();

	//���������� �� ������� �
	for (int i = 0; i < n; i++)
	{
		if ((a[i] == 'a' || a[i] == 'e' || a[i] == 'o'|| a[i] == 'y' || a[i] == 'i' || a[i] == 'u')||
			(a[i] == 'A' || a[i] == 'E' || a[i] == 'O' || a[i] == 'Y' || a[i] == 'I' || a[i] == 'U'))
		{
			a[i] = '#';
		}
	}
	

	//�������
	fbin.open("in.txt", std::ofstream::out | std::ofstream::trunc);
	fbin.close();

	//������
	fbin.open("in.txt", ios::binary | ios::out);
	if (!fbin)
	{
		cout << "NO OPEN" << endl;
	}
	fbin.write(a, t);
	fbin.close();

	return 0;
}