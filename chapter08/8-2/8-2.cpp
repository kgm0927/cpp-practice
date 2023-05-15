#include <iostream>
#include <string>
using namespace std;

//
// 
//  * ��� ����
// 
// Point�� ��ӹ޴� ColorPoint�� ��� ������ ������ ����.
// 
// class ColorPoint: Public Point{
//			...
//		};
// 
// * �Ļ� Ŭ���� ��ü ����
// 
// Point Ÿ���� ��ü p�� ColorPoint Ÿ���� ��ü cp�� ������ ���� �����ϸ�, ��ü p�� cp�� ���� ������ �����ش�.
// 
// Point p;
// ColorPoint cp;
// 
// * �Ļ� Ŭ�������� �⺻ Ŭ���� ��� ����
// 
// �Ļ� Ŭ������ ����� ���Ͽ� �⺻ Ŭ������ ����� �ڽ��� ����� Ȯ���Ѵ�. �Ļ� Ŭ������ ������� �⺻ Ŭ������ private ��� �ܿ� 
// ��� ����� ������ �� �ִ�.
// 
// * �⺻ Ŭ������ private ����� ��Ӱ� ����
// 
// �켱 Point Ŭ������  x,y ����� private���� ��������, x,y�� Point Ŭ������ set(), showPoint() �Լ��� ������ �� �ִٴ� �ǹ��̴�.
// 
// �⺻ Ŭ������ private ����� �Ļ� Ŭ������ ��ӵǸ�, �Ļ� Ŭ������ ��ü�� ���� �� �Ļ� Ŭ������ ��ü ������ ������ �ȴ�. �׷��Ƿ�
// ColorPoint ��ü cp���� ��ӹ��� x,y�� �����Ͽ� ����� �����Ѵ�. ColorPoint���� x,y ����� �����ϰ��� �ϸ�, ���������� set()�� showPoint()
// �Լ��� �̿��ؾ߸� �Ѵ�.
// 
// �����ϸ�, �⺻ Ŭ������ ����� private ����� �Ļ� Ŭ������ ��ӵǰ� �Ļ� Ŭ������ ��ü���� ���Ե�����, �Ļ� Ŭ������ � �Լ����� ���� ������
// �� ����.
// 
// * Ŭ���� �ܺο��� �Ļ� Ŭ������ ȣ��
// 
// * 8.3 ��Ӱ� ��ü ������
// 
// �Ļ� Ŭ������ ��ü���� �⺻ Ŭ�������� ����� ������ �Ļ� Ŭ�������� ������ ������� ��� �����ϱ⿡,
// �Ļ� Ŭ���� ��ü�� �Ļ� Ŭ������ �����ͳ� �⺻ Ŭ������ �����ͷ� ��� ����ų �� �ִ�.
// 
// 
// 









// 8.4 protected ���� ����
// 
// �⺻ Ŭ������ protected�� ������ ����� �Ļ� Ŭ�������� ������ ����ϰ� �ٸ� Ŭ������ �ܺ� �Լ����� ������ �� ������ ��������.

// 


class Point {
protected:
	int x, y;// �� �� (x,y) ��ǥ�� // �̴� main �Լ� ���ؼ� ������ �Ұ����ϰ�, ������ �Ļ� Ŭ������ ���ؼ��� �����ϴ�.
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
	Point p; // �⺻ Ŭ������ ��ü ����
	p.set(2, 3);
	p.x = 5; // ����Ұ�
	p.y = 5;// ���� �Ұ�
	p.showPoint();

	ColorPoint cp;	// �Ļ� Ŭ������ ��ü ����

	cp.x = 10;// ����Ұ�
	cp.y = 10;// ����Ұ�
	cp.set(3, 4);
	cp.setcolor("Red");

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.showPoint();
	cp2.setcolor("Red");
	cout << ((cp.equals(cp2)) ? "true" : "false");// #7

}