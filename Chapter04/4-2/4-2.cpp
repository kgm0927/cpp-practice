#include <iostream>
using namespace std;

// 객체 배열을 선언하는 방법을 알아보자. 객체 배열은 원소가 객체라는 점을 빼고, int, char 등 기본 타입의 배열을 선언하고
// 활용하는 방법과 동일하다.

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }// radius값 입력.
	void setRadius(int r) { radius = r; }// 이것이 없다면 변수를 선언할 수 없다.
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle circleArray[3]; // 1. Circle 객체 배열 생성

	// 배열의 각 원소 객체의 멤버 접근
	circleArray[0].setRadius(10); // 2.
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);

	for (int i = 0; i < 3; i++)// 배열의 각 원소 객체의 멤버 접근
	{
		cout << "Circle" << i << "의 면적" << circleArray[i].getArea() << endl;
	}

	Circle* p;// 3.
	p = circleArray; // 4. p는 circleArray 배열을 가리킨다.
	for (int i = 0; i < 3; i++)
	{// 객체 포인터로 배열 접근

		cout << "Circle " << i << "의 면적은" << p->getArea() << endl;
		p++;// 5. 다음 Circle 객체 주소로 증가
		//  p->getArea()는 p[0].getArea()와 (*p).getArea()와 동일하게 쓰인다.
	}

	

	for (int i = 0; i < 3; i++)
	{
		cout << "Circle " << i << "의 면적은" << p->getArea() << endl;
		p++;
	}
	
	
}