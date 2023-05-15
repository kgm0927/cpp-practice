#include <iostream>
#include <string>
using namespace std;

// * 상속
//
// 상속(Inheritance)은 객체 지향 언어의 본질적인 특성이다.
// 
// 
// 
// * C++ 클래스 상속
// 
// C++에서는 두 클래스 사이에 부모-자식의 상속 관계를 선언한다. 상속은 자식 클래스의 객체가
// 생성될 때, 자신의 멤버뿐 아니라 부모 클래스의 멤버를 포함한 것을 지시한다.
// C++ 에서 부모 클래스를 기본 클래스(base class), 자식 클래스를 파생 클래스(derived class)라고 한다.
// 
// C++ 에서는 여러 개의 클래스를 동시에 상속받는 다중 상속(multiple inheritance)를 허용한다.
// 
// 
// * 클래스 간의 계층적 분류 및 관리의 용이함
// 
// 상속의 서로 관련된 클래스를 계층 관계로 표현함으로써, 프로그램에 존재하는 클래스들의 구조적인 관계 파악을 쉽게 해준다.
// 
// 
// * 클래스 재사용과 확장을 통한 소프트웨어의 생산성 확장
// 
// 상속의 가장 큰 장점은 소프트웨어 생산성을 향상하는데 있다.
// 
// 
// * 상속 선언
// 
// 상속은 class 선언 뒤에, 콜론(:)과 기본 클래스 이름을 선언하면 된다. 이땐 기본 클래스 이름 앞에 반드시 상속 접근을 지정해야 하는데,
// public, private, protected 중 어떤 것도 가능하다.  
//



class Point { // 2차원 평면에서 한 점을 표현하는 클래스 Point 선언
	protected:
	int x, y;// 한점 (x,y) 좌표값
public:
	void set(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void showPoint(){
		cout << "(" << x << ',' << y << ")" << endl;
	}
};

class ColorPoint :public Point { // 2차원 평면에서 컬러 점을 표현하는 클래스 ColorPoint. Point 상속받음
	string color; // 점의 색 표현
	
public:
	void setcolor(string color) {
		this->color = color;
	
	}
	void showColorPoint();// Point의 showPoint() 호출
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}
/*
// * 업 캐스팅
//
// 업 캐스팅은 파생 클래스의 객체를 기본 클래스의 포인터로 가리키는 것을 말한다.
//


int main() {
	ColorPoint cp;
	ColorPoint* pDer = &cp;
	Point* pBase = pDer;// 업캐스팅

	pDer->set(3,4);
	pBase->showPoint();
	pDer->setcolor("red");
	pDer->showColorPoint();// 오류

	pBase->showPoint();
	// 이런 방법을 사용해어 포인터 객체 pBase에 Point 클래스 맴버(필드)만 사용할 수 있도록 한다.
}*/

int main() {

	// 기본 클래스 포인터가 가리키는 객체를 파생 클래스의 포인터로 가리키는 것을 다운 캐스팅(down-casting)이라고 한다.

	ColorPoint cp;
	ColorPoint* pDer;
	Point* pBase = &cp;



	cout << "pBase 객체=";


	pBase->set(3, 4);
	pBase->showPoint(); // 여기서는 현재 Point 클래스의 멤버(필드)만 쓸 수 있다.
	

	cout << endl << endl;

	pDer = (ColorPoint *)pBase;// pBase를 강제 타입 변환으로 다운 캐스팅(반드시 강제 변환이 필요.)

	cout << "pDer 객체=" ;

	pDer->set(3, 5);
	pDer->setcolor("red");
	pDer->showColorPoint();
	cout << endl << endl;

	cout << "cp 객체" ;
	cp.showColorPoint();
	




}