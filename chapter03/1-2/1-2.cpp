#include <iostream>
using namespace std;


// 생성자(constructor): 특별한 멤버 함수를 통하여 객체를 초기화하는 일을 한다.

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);// 생성자는 중복 생성이 가능하다.
	double getArea();

};

Circle::Circle() {
	radius = 1;
	cout << "반지름" << radius << "원 생성" << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "반지름" << radius << "원 생성" << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle donut;	// 매개 변수 없는 생성자 호출
	double area = donut.getArea(); 
	cout << "donut 면적은" << area << endl;

	Circle pizza(30);	// 매개 변수 있는 생성자 호출, 30이 r에 전달됨.
	area = pizza.getArea();
	cout << "pizza 면적은" << area << endl;

}