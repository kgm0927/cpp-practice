#include <iostream>
using namespace std;


//
// C++ �������̵��� Ư¡
// 
// * �������̵��� ���� ���ǰ� ����
// 
// ���� �Լ��� �̸��� �Ű� ���� Ÿ��, ������ �ƴ϶� ���� Ÿ�Ե� ��ġ�ؾ� �������̵��� �����Ѵ�.
// 
// 
// * �������̵� �� virtual ���þ� ���� ����
// 
// �Ļ� Ŭ�������� virtual Ű���带 �����ص� �ڵ����� �����Լ��� �ȴ�.
//
//
class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base {
public: void f() {
	cout << "Derived::f() called" << endl;
}
};

class GrandDerived :public Derived {
public:
	void f() {
		cout << "GrandDerived::f() called" << endl;
	}
};

int main() {
	GrandDerived g;
	Base* bp;
	Derived* dp;
	GrandDerived* gp;

	bp = dp = gp = &g;// ��� �����Ͱ� ��ü g�� ����Ŵ

	bp->f();
	dp->f();
	gp->f();



}