#include <iostream>
#include <string>
using namespace std;

class Point {
protected: // ���� protected�� ��� ������ ������ ������ �� ������ ��ӹ޴� Ŭ����(�Ļ� Ŭ����)������ �Լ��� ���ؼ� ������ �����ϴ�.
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
		this->x = 5; //�Լ��� ���Ͽ� Point ������ ��� ���� x�� ������.
		
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