#include <iostream>
using namespace std;

// c++에서 객체를 다루기 위해 객체에 대한 포인터 변수를 선언하고,
// 이 포인터 변수로 객체의 멤버 변수를 읽고 값을 쓰거나 멤버 함수를
// 호출할 수 있다.
class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	double getArea();

};

double Circle::getArea() {
	return 3.14 * radius * radius;
}



int main() {
	Circle donut;
	Circle pizza(30);

	Circle* p;// Circle 타입의 객체에 대한 포인터 변수는 p는 다음과 같이 선언한다.
	p = &donut;// 포인터 변수를 선언할 때, 다음과 같이 객체의 주소로 초기화 할 수 있다.

	cout << p->getArea() << endl;	// 객체 포인터로 멤버를 접근할 때 -> 연산자를 사용한다.
	cout << (*p).getArea() << endl;		// 다음과 같이 할 수도 있다.

	p = &pizza;

	cout << p->getArea() << endl; //pizza의 getArea() 호출
	cout << (*p).getArea() << endl;	// pizza의 getArea() 호출
}