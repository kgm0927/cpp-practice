#include <iostream>
using namespace std;


bool getExp(int base,int exp,int &ret) {
	if (base<=0|| exp<=0) {
		return false; // ���� ����
	}

	int value = 1;
	for (int n = 0; n < exp;n++) {
		value *= base;
	}
	ret = base;

	return true;
}

int main() {
	int v = 0;
	if (getExp(2, 3, v))// v=2�� 3��=8. getExp()�� true ����
		cout << "2�� 3���� " << v << "�̴�." << endl;
	else
		cout << "����. 2�� 3���� " << "����� �� �����ϴ�." << endl;

	int e = 0;
	if (getExp(2, -3, e))// 2�� -3��? .getExp()�� false ����
		cout << "2�� -3����" << e << "�̴�." << endl;
	else
		cout << "����. 2�� -3���� " << "����� �� �����ϴ�." << endl;
}