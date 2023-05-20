#include <iostream>
using namespace std;


//
// C++ 오버라이딩의 특징
// 
// * 오버라이딩의 성공 조건과 실패
// 
// 가상 함수의 이름과 매개 변수 타입, 개수뿐 아니라 리턴 타입도 일치해야 오버라이딩이 성공한다.
// 
// 
// * 오버라이딩 시 virtual 지시어 생략 가능
// 
// 파생 클래스에서 virtual 키워드를 생략해도 자동으로 가상함수가 된다.
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

	bp = dp = gp = &g;// 모든 포인터가 객체 g를 가리킴

	bp->f();
	dp->f();
	gp->f();



}