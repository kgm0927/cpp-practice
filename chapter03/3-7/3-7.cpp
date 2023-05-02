#include <iostream>
using namespace std;

// �Ҹ���(destructor): ��ü�� �Ҹ�Ǵ� �������� �ڵ����� ȣ��Ǵ� Ŭ������ ��� �Լ��̴�.(~Circle())
// �Ҹ����� ������ ��ü�� ����� �� �ʿ��� ������ �۾��� �ϱ� �����̴�.
// �Ҹ����� �̸��� Ŭ���� �̸� �տ� ~�� ���δ�.
// �Ҹ��ڴ� ���� Ÿ���� ������ � ���� �����ؼ��� �ȵȴ�.
// �Ҹ��ڴ� ������ �Ѱ��� �����ϸ� �Ű� ����(parameter)�� ������ �ʴ´�.
// �Ҹ��ڰ� ����Ǿ� ���� ������ �⺻ �Ҹ���(default destructor)�� �ڵ����� �����ȴ�.

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();// �Ҹ��� ����
	double getArea();

};

Circle::Circle() {
	radius = 1;
	cout << "������ " << radius << " �� ����" << endl;
}

Circle::Circle(int r) {

	radius = r;
	cout << "������ " << radius << " �� ����" << endl;

}

Circle::~Circle() { // �Ҹ��� ����
	cout << "������ " << radius << " �� �Ҹ�" << endl;
}

int main() {
	Circle donut;
	Circle pizza(30);
	return 0;// main() �Լ��� �����ϸ� main() �Լ��� ���ÿ� ������ pizza, donut ��ü�� �Ҹ�ȴ�.
}

// tip: ��ü�� ������ �ݴ� ������ �Ҹ�ȴ�.