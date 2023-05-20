#include <iostream>
using namespace std;
//
// 8.6 상속의 종류: public, protected, private 상속
// 
// 상속을 통하여 기본 클래스의 멤버들이 파생 클래스의 멤버로 확장이 될 때, 기본 클래스 멤버의 접근지정은 상속에 따라 달라진다.
// 
// 'public 상속'을 사용하면 Base에 선언된 멤버들은 접근 지정을 그대로 유지한 채 Derived의 멤버로 확장된다. 하지만 'private 상속'이나 'protected 상속'
// 은 기본 클래스에 선언된 멤버들의 경우 접근 지정을 변경한다.
// 
// - public 상속
// 기본 클래스를 public으로 상속받으면, 기본 클래스의 protected, public 멤버들은 접근 지정 변경 없이 파생 클래스에 그대로 상속된다.
// 
// - protected 상속
// 기본 클래스를 protected로 상속 받으면, 기본 클래스의 protected, public 멤버들은 모두 protected 접근 지정으로 변경되어 파생 클래스에 상속 확장된다.
// 
// - private 상속
// 기본 클래스를 private으로 상속받으면, 기본클래스의 protected, public 멤버들은 모두 private 접근 지정으로 변경되어 파생 클래스에 상속 확장된다.
// 
//

class Base {
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	void showA() { cout << a; }
};

class Derived : private Base {
	int b;
protected:
	void setB(int b) { this->b = b; }
public:
	void showB() { cout << b; }
};

int main() {
	Derived x;
	x.a = 5;	// 1 // 컴파일 오류, a는 Derived 클래스에 상속되지만  private 멤버이므로 접근 불가 
	x.setA(10);	// 2 // 
	x.showA();	// 3 // 2,3 컴파일 오류 setA(), showA()는 private 멤버로 변경되어 Derived 클래스에 상속되기 때문에 Derived 클래스 외부에서 접근 불가
	x.b = 10;	// 4 // 컴파일 오류, b는 private 멤버이기 때문에  Derived 클래스 외부에서 접근불가
	x.setB(10);	// 5 // 컴파일 오류 setB()는 protected 멤버이기 때문에 main()에서 접근 불가
	x.showB();	// 6 // 정상 컴파일, show()는 public 멤버이기 때문에 누구나 접근 가능
}