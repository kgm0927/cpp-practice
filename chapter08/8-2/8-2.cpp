#include <iostream>
#include <string>
using namespace std;

//
// 
//  * 상속 선언
// 
// Point를 상속받는 ColorPoint의 상속 선언은 다음과 같다.
// 
// class ColorPoint: Public Point{
//			...
//		};
// 
// * 파생 클래스 객체 생성
// 
// Point 타입의 객체 p와 ColorPoint 타입의 객체 cp는 다음과 같이 생성하며, 객체 p와 cp의 내부 구성을 보여준다.
// 
// Point p;
// ColorPoint cp;
// 
// * 파생 클래스에서 기본 클래스 멤버 접근
// 
// 파생 클래스는 상속을 통하여 기본 클래스의 멤버를 자신의 멤버로 확장한다. 파생 클래스의 멤버들은 기본 클래스의 private 멤버 외에 
// 모든 멤버를 접근할 수 있다.
// 
// * 기본 클래스의 private 멤버의 상속과 접근
// 
// 우선 Point 클래스에  x,y 멤버를 private으로 선언함은, x,y는 Point 클래스의 set(), showPoint() 함수만 접근할 수 있다는 의미이다.
// 
// 기본 클래스의 private 멤버도 파생 클래스에 상속되며, 파생 클래스의 객체가 생길 때 파생 클래스의 객체 내에서 생성이 된다. 그러므로
// ColorPoint 객체 cp에는 상속받은 x,y를 포함하여 멤버가 존재한다. ColorPoint에서 x,y 멤버를 접근하고자 하면, 간접적으로 set()과 showPoint()
// 함수를 이용해야만 한다.
// 
// 정리하면, 기본 클래스에 선언된 private 멤버는 파생 클래스에 상속되고 파생 클래스의 객체에도 포함되지만, 파생 클래스의 어떤 함수에도 직접 접근할
// 수 없다.
// 
// * 클래스 외부에서 파생 클래스의 호출
// 
// * 8.3 상속과 객체 포인터
// 
// 파생 클래스의 객체에는 기본 클래스에서 선언된 멤버들과 파생 클래스에서 선언한 멤버들이 모두 존재하기에,
// 파생 클래스 객체를 파생 클래스의 포인터나 기본 클래스의 포인터로 모두 가리킬 수 있다.
// 
// 
// 









// 8.4 protected 접근 지정
// 
// 기본 클래스에 protected로 지정된 멤버는 파생 클래스에게 접근을 허용하고 다른 클래스나 외부 함수에서 접근할 수 없도록 숨겨진다.

// 


class Point {
protected:
	int x, y;// 한 점 (x,y) 좌표값 // 이는 main 함수 통해서 수정이 불가능하고, 오로지 파생 클래스를 통해서만 가능하다.
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint :public Point {
	string color;
public:
	void setcolor(string color) {
		this->color = color;
	}
	void showColorPoint();
	bool equals(ColorPoint p);
};


void ColorPoint :: showColorPoint() {
	cout << color << ":";
	showPoint();
}

bool ColorPoint::equals(ColorPoint p) {
	if (x == p.x && y == p.y && color == p.color) return true;
	else return false;
}

int main() {
	Point p; // 기본 클래스의 객체 생성
	p.set(2, 3);
	p.x = 5; // 변경불가
	p.y = 5;// 변경 불가
	p.showPoint();

	ColorPoint cp;	// 파생 클래스의 객체 생성

	cp.x = 10;// 변경불가
	cp.y = 10;// 변경불가
	cp.set(3, 4);
	cp.setcolor("Red");

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.showPoint();
	cp2.setcolor("Red");
	cout << ((cp.equals(cp2)) ? "true" : "false");// #7

}