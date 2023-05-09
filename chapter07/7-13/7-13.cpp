#include <iostream>
using namespace std;


// *단항 연산자 ++를 프렌드로 작성하기
//
// 
//  Power 객체에 대한 ++ 연산자를 프렌드 함수로 작성해 보자. ++ 연산자는 다음과 같이 전위와 후위로 구분되어진다.
// 
//  Power a(3,5),b;
//	b=++a;
//	b=a++;
// 
// 후위 연산자 함수는 전위 연산자 함수와 구분하기 위해 int 매개변수를 추가적으로 가지며, 의미 없는 값이 전달된다.
// 
// a) 전위 연산자
//	++a -----> ++(a)
// 
// b) 후위 연산자
// a++ -----> ++(a,0)// tip: 0은 의미 없는 값으로 전위 연산자와 구분하기 위함
// 
// * 참조 매개 변수와 참조 리턴 사용
// 
// 두 연산자 모두 여기서는 참조 매개 변수 Power& op를 사용하여, 전위 연산자의 경우 참조를 리턴하는 것이다.
// 
// 참조 매개 변수(parameter)를 쓰지 않는다면, 매개변수 op에 복사본이 전달이 되므로, op 객체의 kick과 punch의 값을 증가시켜도
// 객체 a의 값은 변하지 않고, ++a, a++의 실행 후 객체 a는 ++ 연산 이전과 동일하게 된다.
// 
// Power& op의 참조 매개 변수를 사용함으로써 op는 객체 a를 참조하게 되어 op 객체를 변경하면 바로 객체 a가 변경된다.
// 
//


class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) { this->kick = kick; this->punch = punch; }
	void show();
	friend Power& operator++(Power& op);// 전위 ++ 연산자 함수 프렌드 선언
	friend Power& operator++(Power& op,int x);// 후위 ++ 연산자 함수 프렌드 선언
};

void Power::show() {
	cout << "kick= " << kick << ',' << "punch=" << punch << endl;
}

Power& operator++(Power& op) {// 전위 ++ 연산자 함수 구현
	op.kick++;
	op.punch++;
	return op;

}

Power& operator++(Power& op,int x) {// 후위 ++ 연산자 함수 구현
	Power tmp = op; // 변경하기 전의 op 상태 저장
	op.kick++;
	op.punch++;
	return tmp;

}

int main() {
	Power a(3, 5), b;
	b = ++a;

	a.show(), b.show();

	b = a++;
	a.show(); b.show();
}