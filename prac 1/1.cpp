#include <iostream>
#include <algorithm>
#include <vector>
#include<string>  
using namespace std;

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

void pal(int mas[], int& n,int& tp) {
	for (int i = 0; i < n; i++) {
		if (func1(mas[i]) == 1) {
			tp = i;
			break;
		}
		else
			tp=-1;
	}
}
void pal1(vector <int> &mas, int& n, int& tp) {
	for (int i = 0; i < n; i++) {
		if (func1(mas[i]) == 1) {
			tp = i;
			break;
		}
	}
}

void func2(int mas[], int& n,int& i)
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

void func3(int mas[], int& n, int i,int newelem) { 
	for (int j = n; j > i; j--)
		mas[j] = mas[j - 1];
	mas[i+1] = newelem;
	n++;
}

void func2d(int*& mas, int& n, int& i) {
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
void func3d(int*& mas, int &n, int i, int newelem) { //���������� ��������
	mas = (int*)realloc(mas, (n + 1) * sizeof(int));
	for (int j = n; j > i; j--)
		mas[j] = mas[j - 1];
	mas[i + 1] = newelem;
	n++;
}

void v(int n, int mas[]) {
	cout << "array: ";
	for (int j = 0; j < n; j++) cout << mas[j] << " ";
	cout << endl;
}

void vv(int n,int mas[]) {
	cout << "������� " << n << " ���������: ";
	for (int i = 0; i < n; i++) cin >> mas[i];
	v(n, mas);
}

int main()
{
	setlocale(LC_ALL, "ru");
	int menu, ns, nd, nv, tempint, tempint1;
	int* mas_d;
	vector<int>mas_v;
	const int n_max = 10;
	int mas_s[n_max];
	cout << "������������ ������ �1 '���������� ������'. ���������� ������" << endl;
	do {
		cout << "�������� ������, ���� �������� �� ������ ������������: ";
		cout << "1:static array  2:dynamic array  3:vector array \n";
		cin >> menu;
		switch (menu) {
		case 1: //static
			cout << "������� ������ ���������(�������� = 10): ";
			int mas_s[n_max];
			ns = 0;
			do
			{
				cin >> ns;
				if (ns > 10)
					cout << "�� ����� ��������, ������� ������ ������������� ������� ������������ �������! ���������� ��� ���.\n������� ������ ���������(�������� = 10): ";
			} while (ns > n_max);
			vv(ns, mas_s);
			tempint = -1;
			pal(mas_s, ns, tempint);
				do {
					cout << "1:����� ������ �������� �������, ������� �������� �����������.\n2:������� �������� �������, ������������� ��������������� ����� ���������, ���������� ����� ���������. \n3:�������� ����� ������� � ������ ����� �������� �������, ������� �������� �����������. \n";
					cin >> menu;
					switch (menu) {
					case 1:
						if (tempint == -1) {
							cout << "� ������� ��� ����������" << endl;
							menu = 'f';
							break;
						}
						else
							cout << "������ ��������, ����������� ���������: " << tempint << endl;
						break;
					case 2:
						if (tempint == -1) {
							cout << "� ������� ��� ����������" << endl;
							menu = 'f';
							break;
						}
						func2(mas_s, ns,tempint);
						v(ns, mas_s);
						break;

					case 3:
						if (tempint == -1) {
							cout << "� ������� ��� ����������" << endl;
							menu = 'f';
							break;
						}
						if (ns == n_max) {
							cout << "no space" << endl;
							break;
						}
						else {
							cout << "������� �������, ������� ���� �������� � ������: " << endl;
							cin >> tempint1;
							func3(mas_s, ns, tempint, tempint1);
							v(ns, mas_s);
						}
						break;
					}
				} while (menu != 'f');
			break;

		case 2: //dynamic
			nd = 0;
			cout << "������� ������ ���������: ";
			do {
				cin >> nd;
			} while (nd < 0);
			mas_d = new int[nd];
			vv(nd, mas_d);
			tempint = -1;
			pal(mas_d, nd, tempint);
				do {
					cout << "1:����� ������ �������� �������, ������� �������� �����������.\n2:������� �������� �������, ������������� ��������������� ����� ���������, ���������� ����� ���������. \n3:�������� ����� ������� � ������ ����� �������� �������, ������� �������� �����������. \n";
					cin >> menu;
					switch (menu) {
					case 1:
						if (tempint == -1) {
							cout << "� ������� ��� ����������" << endl;
							menu = 'f';
							break;
						}
						else
							cout << "������ ��������, ����������� ���������: " << tempint << endl;
						break;
					case 2:
						if (tempint == -1) {
							cout << "� ������� ��� ����������" << endl;
							menu = 'f';
							break;
						}
						func2d(mas_d, nd, tempint);
						v(nd, mas_d);
						break;
					case 3:
						if (tempint == -1) {
							cout << "� ������� ��� ����������" << endl;
							menu = 'f';
							break;
						}
						cout << "������� �������, ������� ���� �������� � ������: " << endl;
						cin >> tempint1;
						func3d(mas_d, nd, tempint, tempint1);
						v(nd, mas_d);
						break;
					}
				} while (menu != 'f');
				break;
		case 3: //vector
			mas_v.clear();
			cout << "C������ ������ ���������: ";
			cin >> nv;;
			cout << "������� " << nv << " ���������: ";
			for (int i = 0; i < nv; i++) {
				cin >> tempint1;
				mas_v.push_back(tempint1);
			}
			cout << "array: ";
			for (int j = 0; j < mas_v.size(); j++) cout << mas_v[j] << " ";
			cout << endl;
			tempint = -1;
			pal1(mas_v, nv, tempint);
				do {
					cout << "1:����� ������ �������� �������, ������� �������� �����������.\n2:������� �������� �������, ������������� ��������������� ����� ���������, ���������� ����� ���������. \n3:�������� ����� ������� � ������ ����� �������� �������, ������� �������� �����������. \n";
					cin >> menu;
					switch (menu) {
					case 1:
						if (tempint == -1) {
							cout << "� ������� ��� ����������" << endl;
							menu = 'f';
							break;
						}
						else
							cout << "������ ��������, ����������� ���������: " << tempint << endl;
						break;
					case 2:
						if (tempint == -1) {
							cout << "� ������� ��� ����������" << endl;
							menu = 'f';
							break;
						}
						mas_v.erase(mas_v.begin(), mas_v.begin() + tempint);
						tempint = 0;
						cout << " new array: ";
						for (int j = 0; j < mas_v.size(); j++) cout << mas_v[j] << " ";
						cout << endl;
						break;
					case 3:
						if (tempint == -1) {
							cout << "� ������� ��� ����������" << endl;
							menu = 'f';
							break;
							mas_v.clear();
						}
						cout << "�������, ������� ������ ��������: " << endl;
						cin >> tempint1;
						mas_v.insert(mas_v.begin() + tempint+1, tempint1);
						cout << " new array: ";
						for (int j = 0; j < mas_v.size(); j++) cout << mas_v[j] << " ";
						cout << endl;
						break;
					}
				} while (menu != 'f');

			break;
			}
		} while (menu != 0);
	}
