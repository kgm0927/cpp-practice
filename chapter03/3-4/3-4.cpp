#include <iostream>
using namespace std;

// 위임 생성자(delegating constructor): 한 클래스의 생성자들에는 대개 객체를 초기화하는 비슷한 코드가 중복된다.
// C++ 부터는 중복된 초기화 코드를 하니의 생성자로 몰고, 다른 생성자에서 이 생성자를 호출 할 수 있게 한다.
// 이 코드는 다음과 같이 간소화한다.

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	double getArea();
};

Circle::Circle() :Circle(1) {}// 위임 생성자: Circle(int r)의 생성자 호출
	Circle::Circle(int r) {// 타겟 생성자:호출
		radius = r;
		cout << "반지름" << radius << "원 생성" << endl;
	}


	double Circle::getArea() {
		return 3.14 * radius * radius;
}

	int main() {
		Circle donut; // 매개변수 없는 생성자 호출
		double area = donut.getArea();
		cout << "donut의 면적은" << area << endl;

		Circle pizza(30);
		area = pizza.getArea();
		cout << "pizza 면적의 " << area << endl;
	}