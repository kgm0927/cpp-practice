#include <iostream>
using namespace std;
 // Ŭ�����̸� *�����ͺ���=new Ŭ�����̸�;
// Ŭ�����̸� *�����ͺ���=new Ŭ�����̸�(�����ڸŰ���������Ʈ);

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle() {
	radius = 1;
	cout << "������ ���� radius=" << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "�Ҹ��� ���� radius=" << radius << endl;
}

Circle::~Circle() {
	cout << "�Ҹ��� ���� radius=" << radius << endl;
}

int main() {
	Circle* p, * q;
	p = new Circle;		// �⺻ ������ Circle()ȣ��. 
	q = new Circle(30);		//�⺻ ������ Circle(30) ȣ��


	cout << p->getArea() << endl << q->getArea() << endl;
	delete p;
	delete q; // ������ ������ ���Ծ��� ���ϴ� ������� delete �� �� �ִ�.
}
// tip: �����ͺ����� �ݵ�� new�� ����Ͽ� �����Ҵ� ���� �޸��� �ּ��̾�� �Ѵ�. 