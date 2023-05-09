#include <iostream>
using namespace std;


// + 연산자를 외부 프렌드 함수로 작성

// 두 개의 Power 객체를 더하는 + 연산자 외부 함수로 작성해보자. 다음과 같이 + 연산을 실행하는 코드가 있을 때
//
// Power a(3,4), b(4,5) ,c;
// c=a+b;
// 
// 컴파일러는 a+b 식을 외부에 선언된 operator+(Power, Power) 함수를 호출하고 a,b 모두 매개변수로 전달한다. 그리고 friend 
// 로 선언한다.
// 
//  c=a+b -----> c=+(a,b);
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

	friend Power operator +(Power op1, Power op2);

};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator+(Power op1, Power op2) {
	Power tmp;
	tmp.kick = op1.kick + op2.kick;
	tmp.punch = op1.punch + op2.punch;
	return tmp;
}

int main() {
	Power a(3, 5), b(4, 6), c;
		c = a + b;
	a.show();
	b.show();
	c.show();

}