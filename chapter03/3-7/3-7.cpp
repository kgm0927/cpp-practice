#include <iostream>
using namespace std;

// 소멸자(destructor): 객체가 소멸되는 시점에서 자동으로 호출되는 클래스이 멤버 함수이다.(~Circle())
// 소멸자의 목적은 객체가 사라질 때 필요한 마무리 작업을 하기 위함이다.
// 소멸자의 이름은 클래스 이름 앞에 ~를 붙인다.
// 소멸자는 리턴 타입이 업으며 어떤 값도 리턴해서는 안된다.
// 소멸자는 오로지 한개만 존재하며 매개 변수(parameter)를 가지지 않는다.
// 소멸자가 선언되어 있지 않으면 기본 소멸자(default destructor)가 자동으로 생성된다.

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();// 소멸자 선언
	double getArea();

};

Circle::Circle() {
	radius = 1;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r) {

	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;

}

Circle::~Circle() { // 소멸자 구현
	cout << "반지름 " << radius << " 원 소멸" << endl;
}

int main() {
	Circle donut;
	Circle pizza(30);
	return 0;// main() 함수가 종료하면 main() 함수의 스택에 생성된 pizza, donut 객체가 소멸된다.
}

// tip: 객체는 생성의 반대 순서로 소멸된다.