#include <iostream>
using namespace std;

// c++���� ��ü�� �ٷ�� ���� ��ü�� ���� ������ ������ �����ϰ�,
// �� ������ ������ ��ü�� ��� ������ �а� ���� ���ų� ��� �Լ���
// ȣ���� �� �ִ�.
class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	double getArea();

};

double Circle::getArea() {
	return 3.14 * radius * radius;
}



int main() {
	Circle donut;
	Circle pizza(30);

	Circle* p;// Circle Ÿ���� ��ü�� ���� ������ ������ p�� ������ ���� �����Ѵ�.
	p = &donut;// ������ ������ ������ ��, ������ ���� ��ü�� �ּҷ� �ʱ�ȭ �� �� �ִ�.

	cout << p->getArea() << endl;	// ��ü �����ͷ� ����� ������ �� -> �����ڸ� ����Ѵ�.
	cout << (*p).getArea() << endl;		// ������ ���� �� ���� �ִ�.

	p = &pizza;

	cout << p->getArea() << endl; //pizza�� getArea() ȣ��
	cout << (*p).getArea() << endl;	// pizza�� getArea() ȣ��
}