#include <iostream>
using namespace std;
 // 클래스이름 *포인터변수=new 클래스이름;
// 클래스이름 *포인터변수=new 클래스이름(생성자매개변수리스트);

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle() {
	radius = 1;
	cout << "생성자 실행 radius=" << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "소멸자 실행 radius=" << radius << endl;
}

Circle::~Circle() {
	cout << "소멸자 실행 radius=" << radius << endl;
}

int main() {
	Circle* p, * q;
	p = new Circle;		// 기본 생성자 Circle()호출. 
	q = new Circle(30);		//기본 생성자 Circle(30) 호출


	cout << p->getArea() << endl << q->getArea() << endl;
	delete p;
	delete q; // 생성한 순서에 관게없이 원하는 순서대로 delete 할 수 있다.
}
// tip: 포인터변수는 반드시 new를 사용하여 동적할당 받은 메모리의 주소이어야 한다. 