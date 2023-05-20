#include <iostream>
using namespace std;



class A {
public:
	A() { cout << "생성자 A" << endl; }
	A(int x) {
		cout << "매개변수생성자 A" << x << endl;
	}
};

class B :public A {
public:
	B() {
		cout << "생성자 B" << endl;
	}
	B(int x) :A(x+3) {// 파생 클래스의 생성자가 명시적으로 기본 클래스의 생성자를 선택 호출함
		cout << "매개변수생성자 B" << x << endl;
	}



}; int main() {
	B b(5); // B(5) 호출 그리고 A(5+3) 호출을 한다.
}