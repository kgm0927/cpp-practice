#include <iostream>
using namespace std;

//
// * '값에 의한 호출'로 객체를 전달할 때 문제점
// 
// 값에 의한 호출로 객체를 전달하면 표면적으로는 나타나지 않은 약간의 문제가 수반된다.
// 
// 객체가 함수에 전달되면, 함수의 매개 변수 객체가 생성되고, 함수가 종료하면 매개변수 객체가 소멸된다.
// 이때 매개 변수 객체의 생성자와 소멸자가 모두 실행되는가? 그렇지 않다.
// 객체를 매개 변수로 가지는 함수의 경우, c++ 컴파일러는 매개변수 객체의 생성자는 실행되지 않고 소멸자만 실행되도록 컴파일 한다.
//


class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();

	double getArea() {return 3.14 * radius * radius;}
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle() {
	radius = 1;
	cout << "생성자 실행 radius=" << radius << endl;
}

Circle::Circle(int radius) {
	this->radius = radius;
	cout << "실행자 실행 radius=" << radius << endl;
}

Circle::~Circle() {
	cout << "소멸자 실행 radius=" << radius << endl;
}

void increase(Circle c) {
	int r = c.getRadius();
	c.setRadius(r + 1);
}

int main() {
	Circle waffle(30);
	increase(waffle);
	cout << waffle.getRadius() << endl;
}


//
// * 왜 매개 변수 객체의 생성자가 실행되지 않도록 컴파일 되는가?
// 
// 다음 코드는 반지름이 30인 waffle 객체를 생성하고, increase() 함수를 호출하여 waffle 객체를 전달한다.
// 
// increase() 함수의 매개 변수 c에 waffle 객체가 전달된 후, 만일 객체 c의 생성자 Circle()이 실행된다면, 객체 c의 반지름이 1로 초기화되어, 전달받은 원본의
// 상태를 잃어버리게 된다. 
// 컴파일러는 이런 문제가 발생하지 않도록, 매개변수 객체의 생성자가 실행되지 않도록 한다.
// 소멸자의 경우는 다르다. increase()가 리턴하면 c의 소멸자가 실행되고 c는 사라진다.
//



// * '주소에 의한 호출'로 객체 전달
//
// '주소에 의한 호출' 방식으로 함수를 작성하면 '값에 의한 호출'시 생성자가 실행되지 않는 것으로 인한 염려에서 벗어날 수 있다.
// 
// * increase() 함수는 주소에 의한 호출을 하도록 다음과 같이 선언한다.
// 
// void increase(Circle *p)
// 
// main() 함수에서 다음과 같이 increase()를 호출하면,
// 
// Circle waffle(30);
// increase(&waffle);
// 으로 작동이 된다.
// 
// waffle 객체의 주소가 포인터 p에 전달되고, p는 객체가 아니므로 생성자나 소멸자와 관련이 없다. waffle 객체의 반지름이 1 증가한다.
// 
// p->setRadius(r+1);
//  
//
