#include <iostream>

using namespace std;
#include "Circle.h"
// Ŭ�������� ����δ� ��� ���Ͽ�, �����δ� cpp ���Ͽ� �и��Ͽ� �ۼ��Ѵ�.
// main() �� �Լ��� ���� ������ �� �� �̻��� cpp ���Ͽ� ������ �ۼ��Ѵ�.
// 
//

Circle::Circle() {
	radius = 1;
	cout << "������ " << radius;
	cout << " �� ����" << radius;
}
Circle::Circle(int r) {
	radius = r;
	cout << "������ " << radius;
	cout << " �� ���� " << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}