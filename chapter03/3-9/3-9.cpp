#include <iostream>
using namespace std;

// ���� ������(access specifier): ��ü�� ĸ��ȭ�ϰ�, �ܺο��� ���� ������ ���� ����� �ܺ��� ������ ������� �ʴ� ����� ����� �����Ѵ�.
// private : private ���� �������� ����� ����μ�, Ŭ���� ���� ��� �Լ��鿡�Ը� ������ ��� �����ϴ�.
// public : public ���� �������� ����� ����μ�, Ŭ���� ���ܸ� �����ϰ� ���α׷��� ��� �Լ��鿡�� ������ ���ȴ�.
// protected : protected ���� �������� ����� ����μ�, Ŭ���� ���� ��� �Լ��� �� Ŭ������ ��ӹ��� �Ļ� Ŭ������ ��� �Լ����Ը� ������ ���ȴ�.
class PrivateAccessError {
private:
	int a;
	void f();
	PrivateAccessError();
public:
	int b;
	PrivateAccessError(int r);
	void g();
};

PrivateAccessError::PrivateAccessError() {
	a = 1;
	b = 1;
}

PrivateAccessError::PrivateAccessError(int x) {
	a = x;
	b = x;
}


void PrivateAccessError :: f() {
	a = 5;
	b = 5;

}

void PrivateAccessError::g() {

	PrivateAccessError objA;

	cout << "private a:" << objA.a << " private b:" << objA.b << endl;

	a = 6;
	b = 6;
}


int main() {
	PrivateAccessError objA; // ������ PrivateAccessError()�� private�̹Ƿ� main()���� ȣ���� �� ����.
	PrivateAccessError objB(100);
	objB.a = 10; //a�� PrivateAccessError Ŭ������ private�� ����̹Ƿ� main()���� ������ �� ����.
	objB.b = 20;
	objB.f(); //f() PrivateAccessError Ŭ������ private ����̹Ƿ� main()���� ȣ���� �� ����.
	objB.g();
}