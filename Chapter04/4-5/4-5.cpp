#include <iostream>
using namespace std;

int main() {
	int* p;		//
	p = new int;//�� �Ʒ� ���ļ� ���� Ÿ���� ������ �Ҵ��ϴ� ���̴�.

	if (!p) { // if(p==NULL)�� ����, p�� NULL�̸�,
		cout << "�޸𸮸� �Ҵ��� �� �����ϴ�.";
		return 0;// �޸� �Ҵ�ޱ� ����
	}
	*p = 5; // �Ҵ���� ���� ������ 5�� ���
	int n = *p; // �Ҵ���� �������� �� �б�. n=5
	cout << "*p=" << p << endl;
	cout << "n = " << n << endl;

	delete p; // �Ҵ���� ���� ���� ��ȯ. �̰� ���� ���� �� ������ ����������.
}