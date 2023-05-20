#include <iostream>
using namespace std;

//
// 오버라이딩과 범위 지정 연산자(::)
// 
// 범위 지정 연산자(::)를 이용하여 기본 클래스의 가상 함수를 호출할 수 있다. 범위 지정 연산자를 이용하여 기본 클래스 Shape의 가상 함수를
// 정성 바인딩으로 호출하는 사례를 보여준다.
// 
// 범위 지정 연산자를 사용하는 두 가지 경우를 모두 보여준다.
// 
// 첫째, main() 함수와 같이 클래스 외부에서 호출하는 경우이다. 다음 코드는 정적 바인딩으로 Shape의 draw()를 호출한다.
// 
// Circle circle;
// Shape* pShape=&Circle;
// pShape->Shape::draw();	// 정적 바인딩. Shape의 멤버 함수 draw() 호출
// 
// 
// 
// 
// 둘째, 클래스의 메멉 함수에서도 범위 지정 연산자를 이용하여 기본 클래스의 가상 함수를 호출할 수 있다. 이 경우에도 정적 바인딩이 이루어진다.
// 
// class Circle: public Shape{
// public:
// 
//		virtual void draw(){
//		shape::draw();		// 기본 클래스 Shape의 draw()실행. 정적 바인딩
//		// 필요한 기능 추가
//		}
// }
// 
// 이 두 번째의 경우는 실제 응용에서 많이 활용된다. 일반적으로 파생 클래스의 가상 함수(Circle::draw())를 작성하는 개발자는
// 기본 클래스의 가상 함수(Shape::draw())를 그대로 활용하고 기능을 추가하여 개발한다.
//


class Shape {
public:
	virtual void draw() {
		cout << "--Shape--";
	}
};

class Circle :public Shape {
public:
	int x;
	virtual void draw() {
		Shape::draw();	// 기본 클래스의 draw() 호출
		cout << "Circle" << endl;
	}
};

int main() {
	Circle circle;
	Shape* pShape = &circle;

	pShape->draw();	// 동적 바인딩 발생. draw()가 virtual이므로 
	pShape->Shape::draw();	// 정적 바인딩 발생. 범위 지정 연산자로 인해
}