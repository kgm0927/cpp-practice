#include <iostream>
using namespace std;

int getExp(int base, int exp) {// �Ű� ���� �� �ϳ��� �����̸� -1�� �����Ѵ�.

	if (base <= 0 || exp <= 0) {
		return -1;	// ���� ����
	}
	int value = 1;

	for (int n = 0; n < exp; n++)
	{
		value *= base; // base�� exp�� ���Ͽ� ���� �� ���
	}
	return value;// ���� ����. ���� �� ����

}

int main() {
	int v = 0; // v=2�� 3�� =8. getExp()�� 8 ����
	v = getExp(2, 3);

	if (v != -1)
	{
		cout << "2�� 3���� " << "����� �� �����ϴ�." << endl;
	}
	else
		cout << "����. 2�� 3����" << "����� �� �����ϴ�." << endl;



	int e = 0;
	e = getExp(2, -3);
	if (e != -1) {
		cout << "2�� -3����" << e << "�Դϴ�." << endl;
	}
	else
		cout << "����. 2�� -3����" << "����� �� �����ϴ�." << endl;
}