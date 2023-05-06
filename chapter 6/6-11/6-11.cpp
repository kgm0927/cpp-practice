#include <iostream>
using namespace std;

class Circle {
private:
	static int numOfCircles; // ������ ���� ���� ���
	int radius;
public:
	Circle(int r = 1);
	~Circle() { numOfCircles--; } // ������ ���� ���� ����
	double getArea() { return 3.14 * radius * radius; }
	static int getNumOfCircles() { return numOfCircles; }
};

Circle::Circle(int r) {
	radius = r;
	numOfCircles++; // ������ ���� ���� ����
}

int Circle::numOfCircles = 0; // 0���� �ʱ�ȭ

int main() {
	Circle* p = new Circle[10]; // 10���� ������ ����
	cout << "�����ϰ� �ִ� ���� ����" << Circle::getNumOfCircles() << endl; // �����ڰ� 10�� �����Ͽ� numOfCircles=10 �� ��

	delete[]p; // 10���� �Ҹ��� ���� // numOfCircles=0 �� ��
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircles() << endl; 

	Circle a; // ������ ���� // numOfCircles = 1�� ��
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircles() << endl;

	Circle b;// ������ ���� //numOfCircles = 2
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircles() << endl;
}

// * static ��� �Լ��� ���� static ����鸸 ����
// 
// static ��� �Լ��� ���� static ��� ������ �����ϰų� static ��� �Լ��� ȣ���� �� �ִ�.
// 
// * static ��� �Լ��� this�� ����� �� ����.
// 
// static ��� �Լ��� ��ü�� ����� ������ ȣ���� �����ϹǷ�, static ��� �Լ����� this��
// ����� �� ������ �����Ѵ�. Person Ŭ������ addShared() �Լ��� ������ ���� �����ϸ� ������ ������ 
// �߻��Ѵ�.
// 
// 
//