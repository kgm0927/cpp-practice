#include <iostream>
using namespace std;

//
// 9.2 가상 함수와 오버라이딩
// 
// * 오버라이딩의 개념
// 
// 오버라이딩은 파생 클래스에서 기본 클래스에 작성된 가상 함수를 재작성하여, 기본 클래스에 작성된 가상 함수를 무력화시키고, 객체의 주인 노릇을 하는 것이다.
// 
// * 가상 함수 선언과 오버라이딩
// 가상 함수(virtual function)란 virtual 키워드로 선언된 멤버 함수이다. virtual은 컴파일러에게 자신에 대한 호출 바인딩을 실행 시간까지 미루도록 지시하는 키워드이다.
// 
// class Base{
// 
// public:
// virtual void f();
// };
// 
// 파생 클래스에서 기본 클래스의 가상 함수를 재정의 하는 것을 특별히 '함수 오버라이딩(function overriding)'이라고 한다.
// 혹은 '오버라이딩'이라고 부른다. 
//

class Base {
public:
	virtual void f() {
		cout << "Base::f() called" << endl;
	}
};

class Derived : public Base {
public:
	 void f()  {
		cout << "Derived::f() called" << endl;
	}
};

void main() {
	Derived d, * pDer;
	pDer = &d;	// 객체 d를 가리킨다.
	pDer->f();	// Dervied::f() 호출

	Base* pBase;
	pBase = pDer;	// 업 캐스팅. 객체 d를 가리킨다.
	pBase->f();		// 동적 바인딩 발생!! Derived::f() 실행 
}

//
// 예제의 main() 함수는 9-1와 동일하지만 Base에 선언된 멤버 함수 f()가 가상함수 이므로 예제 9-1과 다르게 실행된다. 
// pDer과 pBase는 모두 객체 d를 가리킨다. pDer 포인터가 Derived 타입이므로 다음 코드는 다음과 같인 Derived의 f()를 호출한다.
// 
// pDer->f(); // Derived::f() 호출
// 
// 그러나 pBase가 Base 타입의 포인터이므로 다음 코드는 Base의 f()을 호출할 것으로 예상되지만, pBase가 가리키는 객체는 오버라이딩한 Derived의
// f()를 포함하므로 '동적 바인딩'을 통하여 Derived의 f()가 호출이 된다.
// 
// pBase->f(); // 동적 바인딩에 의해 Derived::f() 호출
// 
// 객체 d에는 2개의 함수 f()가 있으나, Derived의 f()가 Base의 f()를 무시하도록 오버라이딩 되었기 때문이다.
// Base의 f()에 대한 모든 호출은 실행 시간 중에 Derived의 f() 함수로 동적 바인딩 된다.
// 
// 
// 
//
