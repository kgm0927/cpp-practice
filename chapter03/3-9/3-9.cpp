#include <iostream>
using namespace std;

// 접근 지정자(access specifier): 객체를 캡슐화하고, 외부에서 접근 가능한 공개 멤버와 외부의 접근을 허용하지 않는 비공개 멤버를 구분한다.
// private : private 접근 지정으로 선언된 멤버로서, 클래스 내의 멤버 함수들에게만 접근이 허용 가능하다.
// public : public 접근 지정으로 선언된 멤버로서, 클래스 내외를 막론하고 프로그램의 모든 함수들에게 접근이 허용된다.
// protected : protected 접근 지정으로 선언된 멤버로서, 클래스 내의 멤버 함수와 이 클래스를 상속받은 파생 클래스의 멤버 함수에게만 접근이 허용된다.
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
	PrivateAccessError objA; // 생성자 PrivateAccessError()는 private이므로 main()에서 호출할 수 없다.
	PrivateAccessError objB(100);
	objB.a = 10; //a는 PrivateAccessError 클래스의 private의 멤버이므로 main()에서 접근할 수 없다.
	objB.b = 20;
	objB.f(); //f() PrivateAccessError 클래스의 private 멤버이므로 main()에서 호출할 수 없다.
	objB.g();
}