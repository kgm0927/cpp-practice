#include <iostream>
using namespace std;



//
// 10.2 �پ��� ���׸� �Լ� �����
// 
// * �� ���� �Ű� �����κ��� ū �� ���ϱ�
// 
// �� ���� �Ű� ������ �޾� ū ���� �����ϴ� ���׸� �Լ� bigger()�� ������.
// bigger()�� 2���� �Ű� ������ ���� Ÿ���� �����ϴ�, bigger() �Լ��� ���ø� ������ �̷��ϴ�.
// 
// template <class T>
// T bigger(T a,T b);
// 
// 
//

template <class T>
T bigger(T a, T b) {
	if (a > b)return a;
	else return b;
}

int main() {
	int a = 20, b = 50;

	char c = 'a', d = 'z';

	cout << "bigger(20,50)�� �����" << bigger(a, b) << endl;
	cout << "bigger('a','z')�� �����" << bigger(c, d) << endl;
}