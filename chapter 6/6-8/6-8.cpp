#include <iostream>
using namespace std;

//
// * ���� �Ű� ������ ���� ��ȣ��
// 
// �ߺ��� �Լ� �߿��� ���� �Ű� ������ ���� �Լ��� �ִ� ���, �̵� ���̿� ��ȣ���� ������ �� �ִ�.
// �ߺ��� ���� �� �Լ��� ����.
// 
// 
//


int add(int a, int b) {
	return a + b;
}

int add(int a, int &b) {
	b = b + a;
	return b;
}

int main() {
	int s = 10, t = 20;
	cout << add(s, t); // ������ ����. ���� �Ű� ������ ���� �Լ� ȣ���� ��ȣ��.
}