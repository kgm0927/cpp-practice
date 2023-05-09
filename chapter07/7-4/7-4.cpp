#include <iostream>
using namespace std;

// * 연산자 중복 개념
// 
//  피연산자에 따라 서로 다른 연산을 하도록 동일한 연산자를 중복해서 작성하는 것이 연산자 중복(operator overloading)이다.이는
// 일종의 다형성을 위한 방법 중 하나이다.
// 
// * 연산자 중복의 특징
// 
// - C++ 언어에 본래 있는 연산자만 중복 가능하다.
// - 연산자 중복은 반드시 클래스와 관계를 가진다.
// - 연산자 중복으로 피연산자의 개수를 바꿀 수 없다.
// - 연산자 중복으로 연산의 우선순위를 바꿀 수 없다.
// - 모든 연산자가 중복이 가능한 것은 아니다.
// 
// 
// * 연산자 함수 선언과 연산자 함수 개요
// 
// 연산자 함수는 다음 2가지 방법으로 작성이 가능하다.
//	- 클래스의 멤버 함수로 구현
//	- 외부 함수로 구현하고 클랫의 프렌드 함수로 선언
// 
// 
// 연산자를 선언하는 방법은 operator 키워드와 함께 다음과 같이 연산자 함수를 선언한다.
// 
//	리턴타입 operator 연산자(매개변수리스트);
// 
//  * 연산자 착안
// 
//  a,b를 합치는 + 연산자는 다음과 같이 사용한다.
// 
// c=a+b;
// 
// * 연산자 함수 선언
// 
// C++의 기본 더하기 연산에서는 피연산자에 수 이외의 값이 올 수 없기에 처리 될수 없음을 판단한다. 그래서 
// 컴파일러는 Power 클래스 내의 + 연산자 함수가 정의되어 있는 찾고, 이 a+b식을 다음과 같이 변형한다.
// 
// a.+(b);
// 
// 이 식은 Power 객체 a의 멤버 함수 operator+()를 호출하며, b를 매개변수로 넘겨주는 함수 호출이다.
// 
// 
//

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {// 값 초기화
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	Power operator +(Power op2); // + 연산자 함수 선언
};


void Power::show() { 
	cout << "kick= " << kick << "punch= " << punch << endl;
}


Power Power::operator+(Power op2) {
	Power tmp; // 임시 객체 생성

	tmp.kick = this->kick + op2.kick;  // kick 더하기
	tmp.punch = this->punch + op2.punch;// punch 더하기

	return tmp;// 더한 결과 리턴
}

int main() {
	Power a(3, 5), b(4, 6), c;

	c = a + b;// 파워 객체 + 연산

	a.show();
	b.show();
	c.show();
}