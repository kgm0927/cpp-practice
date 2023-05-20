#include <iostream>
using namespace std;

// 동적 바인딩
// 
// * 동적 바인딩: 오버라이딩된 함수가 무조건 호출
// 
// 동적 바인딩(dynamic binding): 가상 함수를 호출하는 코드를 컴파일할 때, 컴파일러는 바인딩을 실행 시간에 결정하도록 미루어둔다.
// 나중에 가상 함수가 호출되면, 실행 중에 객체 내에 오버라이딩된 가상 함수를 동적으로 찾아 호출한다.
// 
// 이를 통하여 Base의 f() 호출되었지만 동적 바인딩을 통해 Derived의 f() 실행되는 사례이다.
// 
//
// * 동적 바인딩이 발생하는 구체적 경우
// 
// 동적 바인딩은 파생 클래스의 객체에 대해, 기본 클래스의 포인터로 가상 함수가 호출될 때 일어난다.
// 
// - 기본 클래스 내의 멤버 함수가 가상 함수 호출
// - 파생 클래스 내의 멤버 함수가 가상 함수 호출
// - main()과 같은 외부 함수에서 기본 클래스의 포인터로 가상 함수 호출
// - 다른 클래스에서 가상 함수 호출 
// 
// 가상 함수를 호출하면, 무조건 동적 바인딩을 통해 파생 클래스에 오버라이딩된 가상 함수가 발생한다.
// 
// 
// 
// * 동적 바인딩 사례
// 
// Shape 클래스만 있는 경우로서, 다음 코드는 자연스럽게 Shape의 draw()가 실행된다.
// 
// Shape *pShape = new Shape();
// pShape->paint();
// 
// 밑의 예제는 Shape을 상속받고 draw()를 오버라이딩한 Circle클래스가 있다. 다음과 같이 Circle 객체를 생성하고
// Shape 타입의 포인터로 paint()를 호출하면 결과는 어떻게 될까?
// 
// Shape *pShape=new Circle(); // 업 캐스팅
// pShape->paint() // paint()는 Circle에서 오버라이딩한 draw() 함수를 호출한다.
// 
// 실행 결과 paint() 함수는 pShape이 가리키는 객체 속에 오버라이딩한 draw()가 있는
// 것을 발견하고, 동적 바인딩을 통하여 Circle의 draw()를 호출한다.
//



class Shape {
public:
	void paint() {
		draw();
	}
	virtual void draw() {
		cout << "Shape::draw() called" << endl;
	}
};

int main() {
	Shape* pShape = new Shape();
	pShape->paint();
	delete pShape;
}