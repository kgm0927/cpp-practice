#include <iostream>
using namespace std;



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
	void setB(int b) {
		this->b = b;
	
	}
public:

	void ShowB() {
		setA(5);	// 1 // 정상 컴파일. setA()는 Base 클래스의 protected 멤버이기 때문에 파생클래스 Derived 에게 접근 허용.
		showA();	// 2 // 정상 컴파일. showA()는 Base 클래스의 public 멤버이기 때문에 파생 클래스 Derived 에게 접근 허용.
		cout << b;
	
	}
};

class GrandDerived:private Derived {
	int c;
protected:
	void setAB(int x) {
		setA(x);	// 3 // 컴파일 오류. setA()는 private 속성으로 변경되어 Derived 클래스에 상속되기 때문에 GrandDerived 클래스에서 접근 불가
	showA();		// 4 // 컴파일 오류. private  속성으로 변경되어 Derived 클래스에 상속되기 때문에 GrandDerived 클래스에서 접근 불가
		setB(x);	// 5 // 정상 컴파일. setB()는 Derived 클래스의 protected 멤버이기 때문에 파생 클래스 GrandDerived 접근 허용 멤버함수는 접근이 가능하다.
		
	}
};