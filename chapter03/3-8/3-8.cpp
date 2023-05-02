#include <iostream>
using namespace std;
// 지역 객체(local object): 함수 내에 선언된 객체 메인 함수에 선언된 것도 포함됨.
// 전역 객체(global object): 함수 바깥에 선언된 객체

// * 전역 객체 지역 객체 모두 생성된 순서의 반대 순으로 소멸된다.
class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
};

Circle::Circle() {
	radius = 1;
	cout << "반지름 " << radius << "원 생성" << endl;

}

Circle::Circle(int r) {
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::~Circle() {
	cout << "반지름 " << radius << " 원 생성" << endl;

}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

Circle globalDonut(1000);// 전역 객체
Circle globalPizza(2000);// 전역 객체

void f() {
	Circle fDonut(100);// 지역 객체
	Circle fPizza(200);// 지역 객체
}

int main() {
	Circle mainDonut;
	Circle mainPizza(30);
	f();
}