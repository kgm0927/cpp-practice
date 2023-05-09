#include <iostream>
using namespace std;

//
// 
// * 후위 ++ 연산자 중복
// 
// Power 클래스에 후위 ++ 연산자 함수를 만들어보자. 전위 연산자와 후위 연산자를 구분하기위해 후위 연산자는 다음과 같이 
// 매개변수를 가지도록 한다.
// 
// Power operator ++();		// 전위 ++ 연산자 함수
// Power operator ++(int x);// 후위 ++ 연산자 함수
// 
// 후위 연산자 함수에서 매개 변수 x에는 의미 없는 값이 전달되므로 무시해도 된다. 이제 후위 ++ 연산자를 작성해보자.
// 
// * 연산자 착안
// 
// Power 객체 a,b에 대해 후위 ++연산자는 다음과 같이 사용된다.
// 
// Power a(3,5),b;
// b=a++;
// 
// a++는 객체 a의 kick과 punch를 1씩 증가시키지만, 증가 이전의 객체 a를 리턴하는 것으로 정의한다.
// a++는 l-value가 될 수 없으므로 ++는 참조를 리턴해서는 안 된다.
// 
// * 연산자 함수 선언
// 
// 컴파일러는 a++ 식을 다음과 같이 변형하여 Power 클래스에서 int 타입을 매개 변수를 가진 operator ++(int) 연산자 함수를
// 호출한다.
// 
// a.++(임의의 정수);
// 
// 
//






class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	Power operator ++(int x); // 후위 ++ 연산자 함수 선언
};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;

}

Power Power::operator++(int x) {
	Power tmp = *this; // 증가 이전 객체 상태를 저장
	kick++;	// 후위 연산
	punch++;// 후위 연산
	return tmp;// 객체 이전 상태 리턴
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = a++; // 후위 ++ 연산자 사용
	a.show();// a의 파워는 1 증가됨
	b.show();// b는 ark 증가되기 이전 상태를 가짐

}