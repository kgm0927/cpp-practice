#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//
// STL �˰��� ����ϱ�
// 
// STL �˰����� ���� �Լ��μ�, STL �����̳� Ŭ������ ��� �Լ��� �ƴϸ� ���ø����� �ۼ��Ǿ� �ִ�.
// STL �˰����� iterator�� �Բ� �ۼ��Ѵ�.
// 
// STL sort() �Լ��� ��� ���� ����. sort() �Լ��� �� ���� �Ű� ������ ������ �ִ�. ù ��° �Ű� ������ ������
// ������ ���ҿ� ���� iterator �ּҸ�, �� ��° �Ű������� ������ ���� ������ interator �ּҸ� �־�� �Ѵ�.
//


int main() {
	vector<int> v;	// ���� ���� ����

	cout << "5���� ������ �Է��ϼ���.>>";
	for (int i = 0; i < 5; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);// Ű���忡�� ���� ���� ���Ϳ� ����
	}

	// v.begin()���� v.end() ������ ���� ������������ ����
	// sort() �Լ��� ���� ��� ���� v�� ���� ������ �����

	sort(v.begin(), v.end());

		vector<int>::iterator it;// ���� ���� ���Ҹ� Ž���ϴ� iterator ���� ����

		for ( it = v.begin(); it < v.end(); it++)// ���� v�� ��� ���� ���
		{
			cout << *it << ' ';
		}
		cout << endl;

}