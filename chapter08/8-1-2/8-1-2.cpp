#include <iostream>
#include <string>
using namespace std;

class Point {
protected: // 만약 protected로 멤버 변수를 설정해 놓았을 때 오로지 상속받는 클래스(파생 클래스)에서만 함수를 통해서 변경이 가능하다.
	int x, y;
public:
	void set(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void showPoint() {
		cout << "(" << x << ',' << y << ")" << endl;
	}
};

class ColorPoint :public Point {
public:
	string color;
	
	
public:
	void setcolor(string color) {
		this->color = color;
		this->x = 5; //함수를 통하여 Point 변수의 멤버 변수 x를 변경함.
		
	}
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}

int main() {
	Point p;
	ColorPoint cp;
	
	
	cp.setcolor("Red");
	cp.showColorPoint();
}