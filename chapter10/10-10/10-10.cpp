#include <iostream>
#include <string>
#include<vector>
using namespace std;

int main() {
	vector<string> v;	// ���ڿ� ���� ����
	string name;		// �������� ���� �ڿ� ������ �̸��� �����ϱ� ���� ����		

	cout << "�̸��� 5�� �Է��϶�." << endl;
	for (int i = 0; i < 5; i++)
	{	// �� �ٿ� �� ���� 5���� �̸��� �����޴´�.
		cout << i + 1 << ">>";
		getline(cin, name);
		v.push_back(name);// �̸��� ���Ϳ� ����

	}

	name = v.at(0);// ������ ù ��° �̸�
	for (int i = 0; i < v.size(); i++)
	{
		if (name < v[i])	//v[i]�� ���ڿ��� name���� �������� �ڿ� ����
			name = v[i];	// name�� v[i]�� ���ڿ��� ����

	}
	cout << "�������� ���� �ڿ� ������ �̸���" << name << endl;
}