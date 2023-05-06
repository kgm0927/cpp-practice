#include <iostream>
using namespace std;

//
// * '���� ���� ȣ��'�� ��ü�� ������ �� ������
// 
// ���� ���� ȣ��� ��ü�� �����ϸ� ǥ�������δ� ��Ÿ���� ���� �ణ�� ������ ���ݵȴ�.
// 
// ��ü�� �Լ��� ���޵Ǹ�, �Լ��� �Ű� ���� ��ü�� �����ǰ�, �Լ��� �����ϸ� �Ű����� ��ü�� �Ҹ�ȴ�.
// �̶� �Ű� ���� ��ü�� �����ڿ� �Ҹ��ڰ� ��� ����Ǵ°�? �׷��� �ʴ�.
// ��ü�� �Ű� ������ ������ �Լ��� ���, c++ �����Ϸ��� �Ű����� ��ü�� �����ڴ� ������� �ʰ� �Ҹ��ڸ� ����ǵ��� ������ �Ѵ�.
//


class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();

	double getArea() {return 3.14 * radius * radius;}
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle() {
	radius = 1;
	cout << "������ ���� radius=" << radius << endl;
}

Circle::Circle(int radius) {
	this->radius = radius;
	cout << "������ ���� radius=" << radius << endl;
}

Circle::~Circle() {
	cout << "�Ҹ��� ���� radius=" << radius << endl;
}

void increase(Circle c) {
	int r = c.getRadius();
	c.setRadius(r + 1);
}

int main() {
	Circle waffle(30);
	increase(waffle);
	cout << waffle.getRadius() << endl;
}


//
// * �� �Ű� ���� ��ü�� �����ڰ� ������� �ʵ��� ������ �Ǵ°�?
// 
// ���� �ڵ�� �������� 30�� waffle ��ü�� �����ϰ�, increase() �Լ��� ȣ���Ͽ� waffle ��ü�� �����Ѵ�.
// 
// increase() �Լ��� �Ű� ���� c�� waffle ��ü�� ���޵� ��, ���� ��ü c�� ������ Circle()�� ����ȴٸ�, ��ü c�� �������� 1�� �ʱ�ȭ�Ǿ�, ���޹��� ������
// ���¸� �Ҿ������ �ȴ�. 
// �����Ϸ��� �̷� ������ �߻����� �ʵ���, �Ű����� ��ü�� �����ڰ� ������� �ʵ��� �Ѵ�.
// �Ҹ����� ���� �ٸ���. increase()�� �����ϸ� c�� �Ҹ��ڰ� ����ǰ� c�� �������.
//



// * '�ּҿ� ���� ȣ��'�� ��ü ����
//
// '�ּҿ� ���� ȣ��' ������� �Լ��� �ۼ��ϸ� '���� ���� ȣ��'�� �����ڰ� ������� �ʴ� ������ ���� �������� ��� �� �ִ�.
// 
// * increase() �Լ��� �ּҿ� ���� ȣ���� �ϵ��� ������ ���� �����Ѵ�.
// 
// void increase(Circle *p)
// 
// main() �Լ����� ������ ���� increase()�� ȣ���ϸ�,
// 
// Circle waffle(30);
// increase(&waffle);
// ���� �۵��� �ȴ�.
// 
// waffle ��ü�� �ּҰ� ������ p�� ���޵ǰ�, p�� ��ü�� �ƴϹǷ� �����ڳ� �Ҹ��ڿ� ������ ����. waffle ��ü�� �������� 1 �����Ѵ�.
// 
// p->setRadius(r+1);
//  
//
