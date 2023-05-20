#include <iostream>
using namespace std;

class Base {
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	void showA() { cout << a; }
};

class Derived :protected Base {
	int b;
protected:
	void setB(int b) {  this->b = b; }
public:
	void showB() { cout << b; }
};

int main() {
	Derived x;
	x.a = 5;	// 1 // Derived 클래스에 상속되지만 private 멤버이므로 접근 불가
	x.setA(10);	// 2
	x.showA();	// 3 // 컴파일 오류, setA(), showA(), 멤버는 protected 멤버로 변경되어 Derived 클래스에 상속되기 때문에 Derived 클래스 외부에서 접근 불가
	x.showB = 10;	// 4 // b는 private 멤버이기 때문에 Derived 클래스 외부에서 접근 불가
	x.setB(10);	// 5 // 컴파일 오류. setB()는 protected 멤버이기 때문에 main() 함수에서 접근 불가
	x.showB();	// 6 // 정상 컴파일. showB() public 멤버이기 때문에 누구나 접근이 가능하다.
}