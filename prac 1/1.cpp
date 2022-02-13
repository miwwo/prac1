#include <iostream>
#include <algorithm>
#include <vector>
#include<string>  


using namespace std;

/* 
1)����� ������ �������� �������, ������� �������� �����������.
2) ������� �������� �������, ������������� ��������������� ����� ���������, ���������� ����� ���������.
3) �������� ����� ������� � ������ ����� �������� �������, ������� �������� �����������.
*/

int func1 (int num) //���������� ����������
{
	string str;
	str = to_string(num);
	int len = str.length();
	for (int i = 0; i < len / 2; ++i)
	{
		if ((str[i] != str[len - i - 1]) or (len == 1))
			return 0;
		else
			return 1;
	}
}



void func2(int mas[], int& n,int& i)//�������� ���������
{
	int t = 0;
	while (t < i) {
		for (int j = 0; j < n - 1; j++)
			mas[j] = mas[j + 1];
		t++;
		n--;
	}
	i = i-i;
}

void func3(int mas[], int& n, int i,int newelem) { //���������� ��������
	for (int j = n; j > i; j--)
		mas[j] = mas[j - 1];
	mas[i+1] = newelem;
	n++;
}

void func2d(int mas[], int& n, int& i) {
	int t = 0;
	while (t < i) {
		for (int j = 0; j < n - 1; j++)
			mas[j] = mas[j + 1];
		t++;
		n--;
		mas = (int*)realloc(mas, n * sizeof(int));
	}
	i = i - i;

}
void func3d(int mas[], int& n, int i, int newelem) { //���������� ��������
	mas = (int*)realloc(mas, (n + 1) * sizeof(int));
	for (int j = n; j > i; j--)
		mas[j] = mas[j - 1];
	mas[i + 1] = newelem;
	n++;
}
void vv(int n,int mas[]) {
	cout << "������� " << n << " ���������: ";
	for (int i = 0; i < n; i++) cin >> mas[i];
	cout << "array: ";
	for (int j = 0; j < n; j++) cout << mas[j] << " ";
	cout << endl;
}
void v(int n, int mas[]) {
	cout << "array: ";
	for (int j = 0; j < n; j++) cout << mas[j] << " ";
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "ru");
	int menu, ns, nd, nv, tempint, tempint1;
	int* mas_d;
	vector<int>mas_v;
	const int n_max = 10;
	int mas_s[n_max];
	do {
		cout << "1:static array  2:dynamic array  3:vector array \n";
		cin >> menu;
		switch (menu) {
		case 1: //static
			cout << "������� ������ ���������: ";
			int mas_s[n_max];
			ns = 0;
			do
			{
				cin >> ns;
			} while (ns > n_max);
			vv(ns, mas_s);
			tempint = -1;
			for (int i = 0; i < ns; i++) {
				if (func1(mas_s[i]) == 1) {
					tempint = i;
					break;
				}
			}
			cout <<"+++++" << tempint << endl;
			if (tempint == -1)
				cout << "� ������� ��� ����������" << endl;
			else {
				do {
					cout << "1:������� �������� �������, ������������� ��������������� ����� ���������, ���������� ����� ���������. \n2:�������� ����� ������� � ������ ����� �������� �������, ������� �������� �����������. \n";
					cin >> menu;
					switch (menu) {
					case 1:
						func2(mas_s, ns,tempint);
						v(ns, mas_s);
						break;

					case 2:
						if (ns == n_max)
							cout << "no space" << endl;
						else {
							cout << "������� �������, ������� ���� �������� � ������: " << endl;
							cin >> tempint1;
							func3(mas_s, ns, tempint, tempint1);
							v(ns, mas_s);
						}
						break;
					}
				} while (menu != 0);
			}
			break;

		case 2: //dynamic
			nd = 0;
			cout << "������� ������ ���������: ";
			do {
				cin >> nd;
			} while (nd > n_max);
			mas_d = new int[nd];
			vv(nd, mas_d);
			tempint = -1;
			for (int i = 0; i < nd; i++) {
				if (func1(mas_d[i]) == 1) {
					tempint = i;
					break;
				}
			}
			if (tempint == -1)
				cout << "� ������� ��� ����������" << endl;
			else {
				do {
					cout << "1:������� �������� �������, ������������� ��������������� ����� ���������, ���������� ����� ���������. \n2:�������� ����� ������� � ������ ����� �������� �������, ������� �������� �����������. \n";
					cin >> menu;
					switch (menu) {
					case 1:
						func2d(mas_d, nd, tempint);
						v(nd, mas_d);
						break;
					case 2:
						cout << "������� �������, ������� ���� �������� � ������: " << endl;
						cin >> tempint1;
						func3d(mas_d, nd, tempint, tempint1);
						v(nd, mas_d);
						break;
					}
				} while (menu != 0);
			}
				break;

		case 3: //vector
			cout << "C������ ������ ���������: ";
			cin >> nv;;
			cout << "������� " << nv << " ���������: ";
			for (int i = 0; i < nv; i++) {
				cin >> tempint;
				mas_v.push_back(tempint);
			}
			cout << "array: ";
			for (int j = 0; j < mas_v.size(); j++) cout << mas_v[j] << " ";
			cout << endl;
			for (int i = 0; i < nv; i++) {
				if (func1(mas_v[i]) == 1) {
					tempint = i;
					break;
				}
			}
			if (tempint == -1)
				cout << "� ������� ��� ����������" << endl;
			else {
				do {
					cout << "1:������� �������� �������, ������������� ��������������� ����� ���������, ���������� ����� ���������. \n2:�������� ����� ������� � ������ ����� �������� �������, ������� �������� �����������. \n";
					cin >> menu;
					switch (menu) {
					case 1:
						mas_v.erase(mas_v.begin(), mas_v.begin() + tempint);
						tempint = 0;
						cout << " new array: ";
						for (int j = 0; j < mas_v.size(); j++) cout << mas_v[j] << " ";
						cout << endl;
						break;
					case 2:
						cout << "�������, ������� ������ ��������: " << endl;
						cin >> tempint1;
						mas_v.insert(mas_v.begin() + tempint+1, tempint1);
						cout << " new array: ";
						for (int j = 0; j < mas_v.size(); j++) cout << mas_v[j] << " ";
						cout << endl;
						break;
					}
				} while (menu != 0);
			}

			break;
			}
		} while (menu != 0);
	}
