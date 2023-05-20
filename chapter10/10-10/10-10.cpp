#include <iostream>
#include <string>
#include<vector>
using namespace std;

int main() {
	vector<string> v;	// 문자열 벡터 생성
	string name;		// 사전에서 가장 뒤에 나오는 이름을 저장하기 위한 변수		

	cout << "이름을 5개 입력하라." << endl;
	for (int i = 0; i < 5; i++)
	{	// 한 줄에 한 개씩 5개의 이름을 물려받는다.
		cout << i + 1 << ">>";
		getline(cin, name);
		v.push_back(name);// 이름을 벡터에 삽입

	}

	name = v.at(0);// 벡터의 첫 번째 이름
	for (int i = 0; i < v.size(); i++)
	{
		if (name < v[i])	//v[i]의 문자열이 name보다 사전에서 뒤에 나옴
			name = v[i];	// name을 v[i]의 문자열로 변경

	}
	cout << "사전에서 가장 뒤에 나오는 이름은" << name << endl;
}