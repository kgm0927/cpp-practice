#include <iostream>
using namespace std;


// * 오버리이딩의 목적
// 기본 클래스에 가상 함수를 만드는 목적은 파생 클래스들이 자신의 목적에 맞게 가상 함수를 재정의 하도록 하는 것이다. 
// 기본 클래스의 가상 함수는 상속받는 파생 클래스에서 구현해야할 일종의 함수 인터페이스를 제공한다.
// 
// 가상 함수는 '하나의 인터페이스에 대해 서로 다른 모양의 구현'이라는 객체 지향 언어의 다형성(polmorphism)을 실현하는 도구이다.
// 
// 
// 밑의 예제는 Shape는 기본 클래스로서, 여러 종류의 파생 클래스들에게 상속된다. Shape은 draw()를 가상함수로 선언하였기 때문에,
// 파생 클래스들은 Shape의 draw() 함수를 오버라이딩하여 자신만의 모양을 그리도록 코딩한다.
// 
// 
// void paint(Shape *p){
// p->draw();
// }
// 
// 위의 함수는 p->draw()를 통해 포인터 p가 가리키는 객체에 오버라이딩된 draw() 함수를 호출하도록 작성하였다.
// 
// p->draw()는 p가 가리키는 객체 내에 오버라이딩된 draw() 함수를 호출하기 때문이다. 이것이 바로 오버라이딩을 통한 다형성의 실현이다.
//


class Shape {
protected:
	void paint(Shape* p) {
		p->draw();
	}
	virtual void draw();
};

class Circle :public Shape {
protected:
	virtual void draw() {

	}
}; class Rect :public Shape {
protected:
	virtual void draw() {

	}
}; class Line :public Shape {
protected:
	virtual void draw() {

	}
};

int main() {

}