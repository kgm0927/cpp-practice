#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { this->radius = r; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

void readRadius(Circle &c) {// 키보드로부터 반지름 값을 읽어 Circle 객체에 반지름을 설정하는 readRadius() 함수를 작성한다.
	int r;
	cout << "반지름을 입력하세요: ";
	cin >> r;	// 반지름 값 입력
	c.setRadius(r);	// 반지름 설정
}

int main() {
	Circle donut;
	readRadius(donut);
	cout << "donut의 면적=" << donut.getArea() << endl;
}