#include <iostream>
using namespace std;


// * == ������ �ߺ�
// �� ������(==)�� �ߺ��� ���� ���� �����ڸ� �������ϴ� ������ �˾ƺ���.
// 
// * ������ ����
// ���� == �����ڴ� �� ���� Power Ŭ������ ���ϴ� ������ ������ ���� ���ȴ�.
// 
/*	Power a(3, 5), b(3, 5);
a.show();
b.show();
if (a == b)cout << "�� �Ŀ��� ����." << endl;
else cout << "�� �Ŀ��� ���� �ʴ�." << endl;*/
//
//  operator == () ������ �Լ��� ���� Ÿ���� bool �̴�.
// 
// * ������ �Լ� ����
// 
//  �����Ϸ��� a==b�� ���� ������ ���� �����Ͽ� Power Ŭ������ ����� �ۼ��� operator == () �Լ��� ã�´�.
// 
// a.==(b)
// 
// �� ���� Power ��ü a�� operator == () ������ �Լ��� ȣ���ϰ� b�� �Ű� ������ �ѱ��.
//
//




class Power
{
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}

	void show();
	bool operator == (Power op2); // == ������ �Լ� ����

};

void Power::show() {
	cout << "kick= " << kick << ',' << "punch= " << punch << endl;
}

bool Power::operator==(Power op2) {
	if (kick == op2.kick && punch == op2.punch)return true;
	else return false;
}

int main() {
	Power a(3, 5), b(3, 5); // 2 ���� ������ �Ŀ� ��ü ����
	a.show();
	b.show();
	if (a == b)cout << "�� �Ŀ��� ����." << endl;
	else cout << "�� �Ŀ��� ���� �ʴ�." << endl;
}