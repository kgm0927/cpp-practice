#include <iostream>
using namespace std;

class Circle {
private:
	static int numOfCircles; // 생성된 원의 개수 기억
	int radius;
public:
	Circle(int r = 1);
	~Circle() { numOfCircles--; } // 생성된 원의 개수 감소
	double getArea() { return 3.14 * radius * radius; }
	static int getNumOfCircles() { return numOfCircles; }
};

Circle::Circle(int r) {
	radius = r;
	numOfCircles++; // 생성된 원의 개수 증가
}

int Circle::numOfCircles = 0; // 0으로 초기화

int main() {
	Circle* p = new Circle[10]; // 10개의 생성자 실행
	cout << "생존하고 있는 원의 개수" << Circle::getNumOfCircles() << endl; // 생성자가 10번 실행하여 numOfCircles=10 이 됨

	delete[]p; // 10개의 소멸자 실행 // numOfCircles=0 이 됨
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl; 

	Circle a; // 생성자 실행 // numOfCircles = 1이 됨
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;

	Circle b;// 생성자 실행 //numOfCircles = 2
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;
}

// * static 멤버 함수는 오직 static 멤버들만 접근
// 
// static 멤버 함수는 오직 static 멤버 변수에 접근하거나 static 멤버 함수만 호출할 수 있다.
// 
// * static 멤버 함수는 this를 사용할 수 없다.
// 
// static 멤버 함수는 객체가 생기기 전부터 호출이 가능하므로, static 멤버 함수에서 this를
// 사용할 수 없도록 제약한다. Person 클래스의 addShared() 함수를 다음과 같이 수정하면 컴파일 오류가 
// 발생한다.
// 
// 
//