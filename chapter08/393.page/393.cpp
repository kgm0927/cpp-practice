#include <iostream>
using namespace std;

class A {
public:
	A() { cout << "생성자 A" << endl;}
	A(int x) {
		cout << "매개변수생성자 A" << x << endl;
	}
};

class B :public A {
public:
	B() {// A() 호출하도록 컴파일 됨
		cout << "생성자 B" << endl;
	}
	B(int x) {// A() 호출하도록 컴파일 됨
		cout << "매개변수생성자 B" << x << endl;
	}


	
}; int main() {
	B b(5);
}

// 컴파일러는 묵시적으로 기본 클래스의 기본 생성자를 호출하도록 컴파일 함.