#include <iostream>
#include <string>
#include<vector>
using namespace std;

int main() {
	vector<string> v;
	string name;

	cout << "이름을 5개 입력하라." << endl;
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
	cout << "사전에서 가장 뒤에 나오는 이름은" << name << endl;
}