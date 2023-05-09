#include<iostream>
using namespace std;

// + 연산자 작성 실습: b=a+2;
// 
// * 연산자 착안
// 
// a+2의 의미를 a의 kick과 punch 값에 더한 각각 2를 더한 결과를 리턴하는 것으로 정의한다.
// 
// * 연산자 함수 선언
// a.+(2)
// 
// 이를 위해 Power 클래스에 operator +(int) 연산자 함수를 다음과 같이 선언한다.
// 
//  a.+(2)
//



class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) { // operator +(int) 함수는 더한 결과로 Power 객체를 리턴한다.
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	Power operator+(int op2);

};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power Power::operator+(int op2) {
	Power tmp;	// 임시 객체 생성
		tmp.kick = kick + op2;	// kick에 op2 더하기
		tmp.punch = punch + op2;// punch op2 더하기
		return tmp;
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = a + 2; // 파워 객체와 정수 더하기

	a.show();
	b.show();
}