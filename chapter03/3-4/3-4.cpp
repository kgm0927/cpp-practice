#include <iostream>
using namespace std;

// ���� ������(delegating constructor): �� Ŭ������ �����ڵ鿡�� �밳 ��ü�� �ʱ�ȭ�ϴ� ����� �ڵ尡 �ߺ��ȴ�.
// C++ ���ʹ� �ߺ��� �ʱ�ȭ �ڵ带 �ϴ��� �����ڷ� ����, �ٸ� �����ڿ��� �� �����ڸ� ȣ�� �� �� �ְ� �Ѵ�.
// �� �ڵ�� ������ ���� ����ȭ�Ѵ�.

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	double getArea();
};

Circle::Circle() :Circle(1) {}// ���� ������: Circle(int r)�� ������ ȣ��
	Circle::Circle(int r) {// Ÿ�� ������:ȣ��
		radius = r;
		cout << "������" << radius << "�� ����" << endl;
	}


	double Circle::getArea() {
		return 3.14 * radius * radius;
}

	int main() {
		Circle donut; // �Ű����� ���� ������ ȣ��
		double area = donut.getArea();
		cout << "donut�� ������" << area << endl;

		Circle pizza(30);
		area = pizza.getArea();
		cout << "pizza ������ " << area << endl;
	}