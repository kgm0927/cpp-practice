#include <iostream>
using namespace std;



class A {
public:
	A() { cout << "������ A" << endl; }
	A(int x) {
		cout << "�Ű����������� A" << x << endl;
	}
};

class B :public A {
public:
	B() {
		cout << "������ B" << endl;
	}
	B(int x) :A(x+3) {// �Ļ� Ŭ������ �����ڰ� ��������� �⺻ Ŭ������ �����ڸ� ���� ȣ����
		cout << "�Ű����������� B" << x << endl;
	}



}; int main() {
	B b(5); // B(5) ȣ�� �׸��� A(5+3) ȣ���� �Ѵ�.
}