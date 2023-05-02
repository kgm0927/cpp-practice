#include <iostream>
using namespace std;

// ��ü �迭�� �����ϴ� ����� �˾ƺ���. ��ü �迭�� ���Ұ� ��ü��� ���� ����, int, char �� �⺻ Ÿ���� �迭�� �����ϰ�
// Ȱ���ϴ� ����� �����ϴ�.

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }// radius�� �Է�.
	void setRadius(int r) { radius = r; }// �̰��� ���ٸ� ������ ������ �� ����.
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle circleArray[3]; // 1. Circle ��ü �迭 ����

	// �迭�� �� ���� ��ü�� ��� ����
	circleArray[0].setRadius(10); // 2.
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);

	for (int i = 0; i < 3; i++)// �迭�� �� ���� ��ü�� ��� ����
	{
		cout << "Circle" << i << "�� ����" << circleArray[i].getArea() << endl;
	}

	Circle* p;// 3.
	p = circleArray; // 4. p�� circleArray �迭�� ����Ų��.
	for (int i = 0; i < 3; i++)
	{// ��ü �����ͷ� �迭 ����

		cout << "Circle " << i << "�� ������" << p->getArea() << endl;
		p++;// 5. ���� Circle ��ü �ּҷ� ����
		//  p->getArea()�� p[0].getArea()�� (*p).getArea()�� �����ϰ� ���δ�.
	}

	

	for (int i = 0; i < 3; i++)
	{
		cout << "Circle " << i << "�� ������" << p->getArea() << endl;
		p++;
	}
	
	
}