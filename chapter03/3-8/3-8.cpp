#include <iostream>
using namespace std;
// ���� ��ü(local object): �Լ� ���� ����� ��ü ���� �Լ��� ����� �͵� ���Ե�.
// ���� ��ü(global object): �Լ� �ٱ��� ����� ��ü

// * ���� ��ü ���� ��ü ��� ������ ������ �ݴ� ������ �Ҹ�ȴ�.
class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
};

Circle::Circle() {
	radius = 1;
	cout << "������ " << radius << "�� ����" << endl;

}

Circle::Circle(int r) {
	radius = r;
	cout << "������ " << radius << " �� ����" << endl;
}

Circle::~Circle() {
	cout << "������ " << radius << " �� ����" << endl;

}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

Circle globalDonut(1000);// ���� ��ü
Circle globalPizza(2000);// ���� ��ü

void f() {
	Circle fDonut(100);// ���� ��ü
	Circle fPizza(200);// ���� ��ü
}

int main() {
	Circle mainDonut;
	Circle mainPizza(30);
	f();
}