#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { this->radius = r; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

void readRadius(Circle &c) {// Ű����κ��� ������ ���� �о� Circle ��ü�� �������� �����ϴ� readRadius() �Լ��� �ۼ��Ѵ�.
	int r;
	cout << "�������� �Է��ϼ���: ";
	cin >> r;	// ������ �� �Է�
	c.setRadius(r);	// ������ ����
}

int main() {
	Circle donut;
	readRadius(donut);
	cout << "donut�� ����=" << donut.getArea() << endl;
}