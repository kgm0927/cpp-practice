#include <iostream>
#include <string>
#include<vector>
using namespace std;

int main() {
	vector<string> v;
	string name;

	cout << "�̸��� 5�� �Է��϶�." << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ">>";
		getline(cin, name);
		v.push_back(name);

	}

	name = v.at(0);
	for (int i = 0; i < v.size(); i++)
	{
		if (name < v[i])
			name = v[i];

	}
	cout << "�������� ���� �ڿ� ������ �̸���" << name << endl;
}