#include <iostream>
using namespace std;

//
// 9.1 상속 관계에서의 함수 재정의
// 
// C++ 에서는 파생클래스에 기본 클래스의 멤버 함수와 동일한 이름과 원형으로 함수를 재정의(refine)하여 사용할 수 있다. 
// 
// main() 함수의 다음 코드는 객체 d를 생성한다.
// 
// Derived d;
// 
// 객체 d는 Base의 f()와 Derived의 f() 함수를 모두 가지고 있다. pDer이 Derived에 대한 포인터이므로 다음 코드는 Derived의 f()를
// 호출한다. pDer이 Derived에 대한 포인터이므로 다음 코드는 Derived의 f()를 호출한다.
// 
// pDer=&d;
// pDer->f();
// 
// 다음 코드는 업 캐스팅을 통해 pBase가 객체를 d를 가리킨다. pBase로 함수 f()를 호출하면 어떤 결과가 나타나게 될까?
// 
// pBase=pDer;
// pBase->f();
// 
// pBase가 Base 클래스에 대한 포인터이므로 컴파일러는 Base의 멤버 f() 함수를 호출하도록 컴파일한다.
//

class Base {
public:
	void f() {
		cout << "Base::f() called" << endl;
	}
};


class Derived :public Base {
public:
	void f() { cout << "Derived::f() called" << endl; }
};

void main() {
	Derived d, * pDer; // 객체와 포인터 객체 생성
	pDer = &d;			// 객체와 d를 가리킨다.
	pDer->f(); // Derived의 멤버 f() 호출


	Base* pBase;	
	pBase = pDer; // 업캐스팅. 객체 d를 가리킨다.
	pBase->f();		// Base 멤버 f() 호출
}

// 
// Base의 멤버 함수 f()와 완전히 동일한 원형으로 멤버 함수 f()를 Derived에 재정의 하였다.
// 
// 정리하면, 파생 클래스에서 기본 클래스와 동일한 형식의 함수를 재정의하는 경우, 기본 클래스에
// 대한 포인터로는 기본 클래스의 함수를 호출하고, 파생 클래스의 포인터로는 파생 클래스에 작성된
// 함수를 호출한다. 이러한 호출 관계는 컴파일 시에 결정된다.
//
