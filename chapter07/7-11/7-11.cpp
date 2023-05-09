#include <iostream>
using namespace std;

// 연산자 함수는 클래스 바깥의 외부 전역 함수로도 작성 가능하다. 이런 경우, 연산자 함수를 클래스에서 friend로 취하여
// 클래스의 멤버를 자유롭게 접근할 수 있게 한다.
// 
//  *2+a를 연산자를 외부 함수로 작성
//  다음 +연산 식을 보자.
// power a(3,4),b;
// b=2+a;
// 
// 지금 배운 바에 따르면, 컴파일러는 2+a 연산을 다음과 같이 변형하여 operator+() 함수를 호출하려고 한다.
// 2.+(a)
// 
// 그러나 2가 객체가 아니므로 이 변형식은 완전히 잘못된 것이다. 이처럼 첫 번째 피연산자가 객체가 아닌 경우, 컴파일러는
// 다음과 같은 식으로 변환한다.
// 
// +(2,a)
// 
// 사실 컴파일러에게 두 개의 옵션이 있는 셈이다. 앞의 식이 성공적이기 위해서는 operator+() 함수를 Power 클래스의 외부 함수로
// 구현할 수 밖에 없다.
// 
// * 외부 연산자 함수의 프렌드 선언
// 
// operator+(int,power) 연산자 함수에는 한 가지 걱정거리가 있다. 함수 내에서 Power의 private 멤버인 kick과 punch 를 자유롭게 접근하고 있기 때문이다.
// 이대로라면, 이 연산자 함수에 컴파일 오류가 발생할 것이 뻔하다. 이 문제의 손쉬운 해결책은 kick과 punch를 public으로 선언하면 된다. 하지만 그렇게 하면
// Power 클래스의 캡슐화 원칙을 무너뜨리게 되는 것이다. 
// 
// 그래서 friend 연산자를 사용하면 간단하게 해결이 된다. 외부에 구현된 operator+(int,power)의 연산자 함수를 다음과 같이 Power 클래스에 프렌드로 초대하는 방법이다.
//


class Power {
	int kick;
	int punch;
public:
	Power(int kick=0,int punch=0) {
		this->kick = kick;
		this->punch = punch;
	}

	void show();
	friend Power operator+(int op1, Power op2);	// 프렌드 선언

};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator+(int op1, Power op2) { // + 연산자 함수를 외부 함수로 구현
	Power tmp; // 임시 객체 생성
	tmp.kick = op1 + op2.kick;	// kick 더하기
	tmp.punch = op1 + op2.punch;// punch 더하기
	return tmp;// 임시 객체 리턴
}


int main() {
	Power a(3, 5), b;
	a.show();// 파워 객체 더하기 연산
	b.show();


}