#include <iostream>
using namespace std;

// * 얕은 복사와 깊은 복사
// 복사란 원본과 동일한 별개의 사본을 만드는 것으로, 만능 복사기가 있다면 어떤 것도 복사할 수 있다.
// 
// 복사를 자세히 살펴보면 얕은 복사(shallow copy), 깊은 복사(deepcopy)로 구분할 수 있다. 이둘의 차이는 심각한 차이를 발생한다.
// 
// 얕은 복사가 이루어질 시, 원본 객체의 멤버변수는 그대로 사본 객체에 복사되므로, 사본의 변수는 원본의 변수 메모리를 공유하게 된다. 
// 그러나 깊은 복사는 원본의 멤버 변수 포인터가 가리키는 메모리까지 복사하여 원본과 사본의 멤버 변수은 별개의 메모리를 가리키므로, 완전한 복사가 이루어진다.
// 
// 
// * 객체의 얕은 복사 문제점
// 원본과 사본이 각각 name 포인터로 문자열 배열을 공유하고 있기 때문에 사본 객체에서 문자열 변수를 변경하면 원본 객체의 name 문자열이 변경되는 문제가 
// 발생한다.
// 
// 
// * 복사 생성자 선언
// 
// 복사 생성은 객체가 생성이 될 때, 원본 객체를 복사하여 생성되는 경우로써, c++에는 복사 생성 시에만 실행되는 특별한 복사 생성자가() 있다.
// 이는 다음과 같다.
// 
// class ClassName{
//	ClassName(const ClassName& c);
// };
// 
// 복사 생성자의 매개 변수는 오직 하나이며, 자기 클래스에 대한 참조로 선언된다. 또한 복사 생성자는 클래스에 오직
// 한 개만 선언할 수 있다.
// 
// class Circle{
// 
//		Circle(const Circle& c);
//	};
// 
// Circle::Circle(const Circle& c){}
// 
// 
// 
// * 복사 생성자 실행
// 
// 이는 치환연산을 통한 객체 복사가 아닌, 복사 생성이라는 점을 분명히 해야 한다.
// 
// ex)
// Circle src(30);
// 
// 다음은 복사 생성의 사례로서, src 객체를 복사해서 dest를 생성하는 코드이다.
// Circle dest(src);
// 
//




class Circle {
private:
	int radius;
public:
	Circle(const Circle& c);// 복사 생성자 선언
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle(const Circle& c) { // 복사 생성자 구현 이 생성자는 호출될 때, src 객체가 참조 매개 변수 c로 전달된다. c는 곧 src이다.
	this->radius = radius;
	cout << "복사 생성자 실행 radius=" << radius << endl;
}


int main() {
	Circle src(30); // 이것은 복사 생성의 사례로서, src 객체를 복사하여 dest를 생성하는 코드이다.
	Circle dest(src);
	cout << "원본의 면적=" << src.getArea() << endl;
	cout << "사본의 면적=" << dest.getArea() << endl;
}