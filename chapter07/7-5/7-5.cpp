#include <iostream>
using namespace std;


// * == 연산자 중복
// 비교 연산자(==)의 중복을 통해 관계 연산자를 재정의하는 과정을 알아보자.
// 
// * 연산자 착안
// 먼저 == 연산자는 두 개의 Power 클래스를 비교하는 것으로 다음과 같이 사용된다.
// 
/*	Power a(3, 5), b(3, 5);
a.show();
b.show();
if (a == b)cout << "두 파워가 같다." << endl;
else cout << "두 파워가 같지 않다." << endl;*/
//
//  operator == () 연산자 함수의 리턴 타입은 bool 이다.
// 
// * 연산자 함수 리턴
// 
//  컴파일러는 a==b의 식을 다음과 같이 변경하여 Power 클래스의 멤버로 작성된 operator == () 함수를 찾는다.
// 
// a.==(b)
// 
// 이 식은 Power 객체 a의 operator == () 연산자 함수를 호출하고 b를 매개 변수로 넘긴다.
//
//




class Power
{
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}

	void show();
	bool operator == (Power op2); // == 연산자 함수 선언

};

void Power::show() {
	cout << "kick= " << kick << ',' << "punch= " << punch << endl;
}

bool Power::operator==(Power op2) {
	if (kick == op2.kick && punch == op2.punch)return true;
	else return false;
}

int main() {
	Power a(3, 5), b(3, 5); // 2 개의 동일한 파워 객체 생성
	a.show();
	b.show();
	if (a == b)cout << "두 파워가 같다." << endl;
	else cout << "두 파워가 같지 않다." << endl;
}