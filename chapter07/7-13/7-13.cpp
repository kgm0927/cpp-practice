#include <iostream>
using namespace std;


// *���� ������ ++�� ������� �ۼ��ϱ�
//
// 
//  Power ��ü�� ���� ++ �����ڸ� ������ �Լ��� �ۼ��� ����. ++ �����ڴ� ������ ���� ������ ������ ���еǾ�����.
// 
//  Power a(3,5),b;
//	b=++a;
//	b=a++;
// 
// ���� ������ �Լ��� ���� ������ �Լ��� �����ϱ� ���� int �Ű������� �߰������� ������, �ǹ� ���� ���� ���޵ȴ�.
// 
// a) ���� ������
//	++a -----> ++(a)
// 
// b) ���� ������
// a++ -----> ++(a,0)// tip: 0�� �ǹ� ���� ������ ���� �����ڿ� �����ϱ� ����
// 
// * ���� �Ű� ������ ���� ���� ���
// 
// �� ������ ��� ���⼭�� ���� �Ű� ���� Power& op�� ����Ͽ�, ���� �������� ��� ������ �����ϴ� ���̴�.
// 
// ���� �Ű� ����(parameter)�� ���� �ʴ´ٸ�, �Ű����� op�� ���纻�� ������ �ǹǷ�, op ��ü�� kick�� punch�� ���� �������ѵ�
// ��ü a�� ���� ������ �ʰ�, ++a, a++�� ���� �� ��ü a�� ++ ���� ������ �����ϰ� �ȴ�.
// 
// Power& op�� ���� �Ű� ������ ��������ν� op�� ��ü a�� �����ϰ� �Ǿ� op ��ü�� �����ϸ� �ٷ� ��ü a�� ����ȴ�.
// 
//


class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) { this->kick = kick; this->punch = punch; }
	void show();
	friend Power& operator++(Power& op);// ���� ++ ������ �Լ� ������ ����
	friend Power& operator++(Power& op,int x);// ���� ++ ������ �Լ� ������ ����
};

void Power::show() {
	cout << "kick= " << kick << ',' << "punch=" << punch << endl;
}

Power& operator++(Power& op) {// ���� ++ ������ �Լ� ����
	op.kick++;
	op.punch++;
	return op;

}

Power& operator++(Power& op,int x) {// ���� ++ ������ �Լ� ����
	Power tmp = op; // �����ϱ� ���� op ���� ����
	op.kick++;
	op.punch++;
	return tmp;

}

int main() {
	Power a(3, 5), b;
	b = ++a;

	a.show(), b.show();

	b = a++;
	a.show(); b.show();
}