#include <iostream>
using namespace std;

//
// 단항 연산자 중복
// 
// 단항 연산자는 연산자의 위치에 따라 전위 연산자(prefix operator)와 후위 연산자(postfix operator)로 나뉜다.
// 
// 
// *전위 ++ 연산자 중복
// 
// 전위 ++ 연산자의 사례로 전위 연산자를 중복하는 방법에 대해서 알아보자.
// 
// ++a 식은 객체 a의 모든 멤버들의 값을 1씩 증가시킨 후, 변경된 객체 a의 참조를 리턴하는 것으로 정의한다.
// 
// * 연산자 함수 선언
// 
// 컴파일러는 ++a 식을 다음과 같이 변경하여 Power 클래스의 선언된 operator++() 연산자 함수를 호출한다.
// 
// a.++();
// 
// 이 호출이 성공하도록 하기 위해 , 매개 변수 없는 operator++() 연산자 함수를 다음과 같이 선언한다. 리턴 타입은 Power& 이다.
// 
// * 참조를 리턴하는 연산자 함수 구현
// 
// operator++() 연산자 함수는 다음과 같이 자신의 kick과 punch를 같은 각각 1씩 증가시킨 후, 자신(*this)에 대한 참조를 리턴한다.
// 
//

class Power {
	int kick;
	int punch;
	int score;
public:
	Power(int kick=0,int punch=0,int score=0) {
		this->kick = kick;
		this->punch = punch;
		this->score = score;
	}
	void show();
	Power& operator++();

};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch <<"score="<<score<< endl;
}

Power& Power::operator++() {// 전위 ++연산자 멤버 함수 구현
	kick++;
	punch++;
	for (int i = 0; i < 10; i++)
	{
		score++;
	}
	return *this;
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = ++a; //전위 연산자 사용

	a.show();
	b.show();
}