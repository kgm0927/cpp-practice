#include <iostream>
#include <string>
using namespace std;


// += 연산자 중복
// 
// 같은 이항 연산자지만 += 연산자는 + 연산자와 달리 약간의 주의가 필요하다.
// 
// * 연산자 함수 선언
// 
// +=의 문제는 원본의 객체에 전달하는 것이 아닌 복사본에 전달하게 된다. 이 문제를 해결하기 위해서는 (a+=b) 연산이 객체 a의 참조를
// 리턴하면 된다. 그러므로 += 연산자의 리턴 타입은 Power&으로 해야 한다.
// 
// a.+=(b);
// 
// Power 객체 a의 operator +=() 함수를 호출하고 객체 b를 매개변수로 넘긴다.
//


class Power {
	int kick;
	int punch;
	string word;
public:
	Power(int kick = 0, int punch = 0,string word="") {
		this->kick = kick;
		this->punch = punch;
		this->word = word;
	}
	void show();
	Power& operator +=(Power op2);
};



void Power::show() {
	cout << "kick= " << kick << "punch= " << punch<< word<<endl;
}

// operator += () 연산자 함수는 다음과 같이 구현된다.

Power& Power::operator+=(Power op2) {
	kick = kick + op2.kick;
	punch = punch + op2.punch;
	word += op2.word;
	return *this;	// 리턴 타입이 Power& 이므로 객체 자신의 참조가 리턴된다.
}
int main() {
	Power a(3, 5,"가"), b(4, 6,"가강"), c;
	a.show();
	b.show();
	c = a+=b;
	a.show();
	c.show();
}
